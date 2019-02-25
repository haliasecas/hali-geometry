#ifndef INF_H
#define INF_H
const double INF = std::numeric_limits<float>::infinity();
#endif

#ifndef FRACTION_H
#define FRACTION_H

#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>

class Fraction {
  private:
    long long _n, _d;

  public:
    Fraction(double fraction = 0) {
      long long precision = 1000000L;
      long rFrac = long(round(fraction * precision));

      long gcd = std::__gcd(rFrac, long(precision));

      this->_n = rFrac / gcd;
      this->_d = precision / gcd;
    }

    Fraction(long long n, long long d) {
      _n = n;
      _d = d;
      reduce();
    }

    // Getters y setters
    inline long long numerator() const {
      return _n;
    }

    inline void numerator(long long n) {
      _n = n;
      reduce();
    }

    inline long long denominator() const {
      return _d;
    }

    inline void denominator(long long d) {
      _d = d;
      reduce();
    }

    // Functions
    void reduce() {
      if (_d != 0) {
        long long gcd = std::__gcd(_n, _d);
        _n /= gcd;
        _d /= gcd;

        _n = _d < 0 ? -_n : _n;
        _d = _d < 0 ? -_d : _d;
      }
      else throw "Divide by zero exception";
    }

    // Operator overloading
    Fraction &operator+=(const Fraction &fB) {
      long long denA = this->_d;
      long long denB = fB._d;
      if (denA != 0 && denB != 0) {
        long long lcm = (denA * denB) / std::__gcd(denA, denB);

        this->_n = ((this->_n * lcm) / denA) + ((fB._n * lcm) / denB);
        this->_d = lcm;

        return *this;
      }

      throw "Divide by zero exception";
    }

    Fraction &operator-=(const Fraction &fB) {
      Fraction fA = *this - fB;
      *this = fA;
      return *this;
    }

    friend Fraction operator-(Fraction fA, const Fraction &fB) {
      fA += Fraction(-fB.numerator(), fB.denominator());
      return fA;
    }

    friend Fraction operator+(Fraction fA, const Fraction &fB) {
      fA += fB;
      return fA;
    }

    Fraction &operator+=(const long long &number) {
      this->_n += number * this->_d;
      this->reduce();
      return *this;
    }

    operator double() {
      if (this->_d != 0) {
        return this->_n / (this->_d * 1.0);
      }
      throw "Divide by zero exception";
    }

    friend Fraction operator*(Fraction fA, const long long &n) {
      fA.numerator(fA._n * n);
      return fA;
    }

    friend Fraction operator*(Fraction fA, const Fraction &fB) {
      return Fraction(fA._n * fB._n, fA._d * fB._d);
    }

    friend Fraction operator+(Fraction fA, const long long &number) {
      fA += number;
      return fA;
    }

    bool operator<(const Fraction &fraction) {
      return (this->_n * fraction._d) < (this->_d * fraction._n);
    }

    operator std::string() const {
      std::stringstream ss;
      ss << this->_n << '/' << this->_d;
      return ss.str();
    }
};

#endif

#ifndef FRACTION_H
#define FRACTION_H

#include <algorithm>

class Fraction {
  private:
    long long _numerator, _denominator;

  public:
    Fraction(long long numerator, long long denominator) {
      denominator = denominator != 0 ? denominator : 1;

      long long gcd = std::__gcd(numerator, denominator);
      _numerator = numerator / gcd;
      _denominator = denominator / gcd;
    }

    Fraction(long long numerator = 1): Fraction(numerator, 1) {}

    // Getters y setters
    inline long long numerator() const {
      return this->_numerator;
    }

    inline void numerator(long long _numerator) {
      this->_numerator = _numerator;
    }

    inline long long denominator() const {
      return this->_denominator;
    }

    inline void denominator(long long _denominator) {
      this->_denominator = (_denominator != 0 ? _denominator : 1);
    }

    // Functions
    void simplify() {
      if (_denominator != 0) {
        long long gcd = std::__gcd(_numerator, _denominator);
        _numerator /= gcd;
        _denominator /= gcd;
      }
    }

    // Operator overloading
    Fraction &operator+=(const Fraction &fractionB) {
      long long denominatorA = this->_denominator;
      long long denominatorB = fractionB._denominator;
      long long lcm = (denominatorA * denominatorB) / std::__gcd(denominatorA, denominatorB);

      this->_numerator = (this->_numerator * lcm) + (fractionB._numerator * lcm);
      this->_denominator = lcm;

      long long gcd = std::__gcd(this->_numerator, this->_denominator);
      this->_numerator /= gcd;
      this->_denominator /= gcd;
      return *this;
    }

    friend Fraction operator+(Fraction fractionA, const Fraction &fractionB) {
      fractionA += fractionB;
      return fractionA;
    }

    Fraction &operator+=(const long long &number) {
      this->_numerator += number * this->_denominator;

      long long gcd = std::__gcd(this->_numerator, this->_denominator);
      this->_numerator /= gcd;
      this->_denominator /= gcd;
      return *this;
    }

    Fraction &operator=(const double &doubleNumber) {
      double fraction = doubleNumber;
      long precision = 1000000000L;
      long gcd = std::__gcd(long(round(fraction * precision)), long(precision));

      this->_numerator = round(fraction * precision) / gcd;
      this->_denominator = precision / gcd;
      return *this;
    }

    friend Fraction operator+(Fraction fractionA, const long long &number) {
      fractionA += number;
      return fractionA;
    }
};

std::ostream &operator<<(std::ostream &os, const Fraction &fraction) {
  if (fraction.denominator() != 1)
    os << fraction.numerator() << '/' << fraction.denominator();
  else
    os << fraction.numerator();
  return os;
}

#endif

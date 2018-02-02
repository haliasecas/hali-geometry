#ifndef FRACTION_H
#define FRACTION_H

#include <algorithm>

class Fraction {
  private:
    int _numerator, _denominator;

  public:
    Fraction(int numerator, int denominator) {
      denominator = denominator != 0 ? denominator : 1;

      int gcd = std::__gcd(numerator, denominator);
      _numerator = numerator / gcd;
      _denominator = denominator / gcd;
    }

    Fraction(int numerator = 1): Fraction(numerator, 1) {}

    // Getters y setters
    inline int numerator() const {
      return this->_numerator;
    }

    inline void numerator(int _numerator) {
      this->_numerator = _numerator;
    }

    inline int denominator() const {
      return this->_denominator;
    }

    inline void denominator(int _denominator) {
      this->_denominator = (_denominator != 0 ? _denominator : 1);
    }

    // Functions
    void simplify() {
      if (_denominator != 0) {
        int gcd = std::__gcd(_numerator, _denominator);
        _numerator /= gcd;
        _denominator /= gcd;
      }
    }

    // Operator overloading
    Fraction &operator+=(const Fraction &fractionB) {
      int denominatorA = this->_denominator;
      int denominatorB = fractionB._denominator;
      int lcm = (denominatorA * denominatorB) / std::__gcd(denominatorA, denominatorB);

      this->_numerator = (this->_numerator * lcm) + (fractionB._numerator * lcm);
      this->_denominator = lcm;

      int gcd = std::__gcd(this->_numerator, this->_denominator);
      this->_numerator /= gcd;
      this->_denominator /= gcd;
      return *this;
    }

    friend Fraction operator+(Fraction fractionA, const Fraction &fractionB) {
      fractionA += fractionB;
      return fractionA;
    }

    Fraction &operator+=(const int &number) {
      this->_numerator += number * this->_denominator;

      int gcd = std::__gcd(this->_numerator, this->_denominator);
      this->_numerator /= gcd;
      this->_denominator /= gcd;
      return *this;
    }

    friend Fraction operator+(Fraction fractionA, const int &number) {
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

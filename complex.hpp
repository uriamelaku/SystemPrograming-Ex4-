// ooriamelaku@gmail.com
#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#include <iostream>
#include <cmath>
#include <sstream>

/**
 * @class Complex
 * A class to represent complex numbers and perform basic operations.
 */
class Complex
{
private:
    double real_part; // The real part of the complex number.
    double imaginary_part; // The imaginary part of the complex number.

public:
    // Default constructor to initialize a complex number to (0, 0)
    Complex() : real_part(0), imaginary_part(0) {}

    // Constructor to initialize a complex number with given real and imaginary parts.
    Complex(double real, double imaginary) : real_part(real), imaginary_part(imaginary) {}

    // Setter for the real part of the complex number.
    void set_real(double real) { real_part = real; }

    // Setter for the imaginary part of the complex number.
    void set_imaginary(double imaginary) { imaginary_part = imaginary; }

    // Getter for the real part of the complex number.
    double get_real() const { return real_part; }

    // Getter for the imaginary part of the complex number.
    double get_imaginary() const { return imaginary_part; }

    // Overloaded insertion operator to print the complex number.
    friend std::ostream &operator<<(std::ostream &os, const Complex &c)
    {
        if (c.imaginary_part >= 0)
        {
            os << c.real_part << "+" << c.imaginary_part << "i";
        }
        else
        {
            os << c.real_part << " " << c.imaginary_part << "i";
        }
        return os;
    }

    std::string toString() const {
        std::ostringstream oss;
        oss << real_part << "+" << imaginary_part << "i";
        return oss.str();
    }

    // Equality operator to compare two complex numbers.
    bool operator==(const Complex &c) const
    {
        return real_part == c.real_part && imaginary_part == c.imaginary_part;
    }

    // Inequality operator to compare two complex numbers.
    bool operator!=(const Complex &c) const
    {
        return !(*this == c);
    }

    // Less-than operator to compare two complex numbers.
    // This operator is used to sort complex numbers in a heap iterator.
    bool operator<(const Complex &c) const
    {
        return std::hypot(real_part, imaginary_part) < std::hypot(c.real_part, c.imaginary_part);
    }

    // Greater-than operator to compare two complex numbers.
    bool operator>(const Complex &c) const
    {
        return std::hypot(real_part, imaginary_part) > std::hypot(c.real_part, c.imaginary_part);
    }

    // Function to calculate the magnitude of the complex number.
    double magnitude() const
    {
        return std::hypot(real_part, imaginary_part);
    }
};

#endif

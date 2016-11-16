#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <cmath>

class Fraction {
private:
    int nominator;
    int denominator;

    void simplify() {
        if (denominator < 0) {
            nominator *= -1;
            denominator *= -1;
        }
        if ( abs(nominator) < 2 ) return;
        int gcd = getGCD( abs(nominator), denominator );
        nominator /= gcd;
        denominator /= gcd;
    }
public:
    
    Fraction( int n, int d ) : nominator(n), denominator(d) {
        simplify();
    }

    Fraction() : nominator(0), denominator(1) {}
    Fraction( const Fraction &other ) : nominator( other.getNominator() ), denominator( other.getDenominator() ) {}

    Fraction( int value ) : nominator(value), denominator(1) {}

    int getNominator() const { return nominator; }
    int getDenominator() const { return denominator; }

    double getValue() const {
        return static_cast<double>(getNominator()) / static_cast<double>(getDenominator());
    }

    int compareTo( const Fraction &other ) const {
        return getNominator() * other.getDenominator() - getDenominator() * other.getNominator();
    }

    int getGCD( int a, int b ) {
        while( a != b ) {
            if (a > b) a -= b; else b -= a;
        }
        return a;
    }

    Fraction operator-() {
        return Fraction(-getNominator(), getDenominator());
    }

    Fraction operator-(Fraction &a) {
        int commonDenominator = a.getDenominator() * getDenominator();
        int commonNominator = a.getNominator() * getDenominator() - getNominator() * a.getDenominator();
        return Fraction(commonNominator, commonDenominator);
    }

    Fraction operator+(const Fraction &a) {
        int commonDenominator = a.getDenominator() * getDenominator();
        int commonNominator = a.getNominator() * getDenominator() + getNominator() * a.getDenominator();
        return Fraction(commonNominator, commonDenominator);
    }

    Fraction operator*(const Fraction &a) {
        return Fraction(getNominator() * a.getNominator(), getDenominator() * a.getDenominator());
    }

    Fraction operator/(const Fraction &a) {
        return Fraction(getNominator() * a.getDenominator(), getDenominator() * a.getNominator());
    }

    bool operator==(const Fraction &a) { return compareTo(a) == 0; }

    bool operator<(const Fraction &a) { return compareTo(a) < 0; }

    bool operator<=(const Fraction &a) { return compareTo(a) <= 0; }

    bool operator>(const Fraction &a) { return compareTo(a) > 0; }

    bool operator>=(const Fraction &a) { return compareTo(a) >= 0; }
};

std::ostream &operator<<(std::ostream &stream, const Fraction& a) {
    return stream << a.getNominator() << "/" << a.getDenominator();
}

Fraction power(const Fraction &fraction, int power) {
    return (power < 0) ?
           Fraction((int)pow(fraction.getDenominator(), -power), (int)pow(fraction.getNominator(), -power)) :
           Fraction((int)pow(fraction.getNominator(), power), (int)pow(fraction.getDenominator(), power));
}

int main(int argc, char **argv) {
    Fraction a(-4, 7), b(1, 3), c(0, 4);
    std::cout << c << " " << a * c << std::endl;
    std::cout << a.getValue() << std::endl;
    std::cout << (a < b) << " " << power(Fraction(1, 4), -1) << std::endl;
}

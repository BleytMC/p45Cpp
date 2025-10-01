#include <iostream>
using namespace std;


class fraction {
    int numerator, denominator;
public:
    fraction() {
        this->numerator = 1;
        this->denominator = 1;
    }

    fraction(int numerator, int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void set(int numerator, int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void set() {
        cout << "Enter numerator: ";
        cin >> numerator;
        cout << "Enter denominator: ";
        cin >> denominator;
    }

    fraction add(fraction other) {

        int res_numerator =
            this->numerator * other.denominator + this->denominator * other.numerator;

        int res_denominator = this->denominator * other.denominator;

        fraction res;
        res.set(res_numerator, res_denominator);

        return res;
    }

    int getNumerator() const {
        return this->numerator;
    }

    int getDenominator() const {
        return this->denominator;
    }



    void print() {
        cout << numerator << "/" << denominator << "\n";
    }

    operator int() const {
        return (int)numerator / denominator;
    }

    operator double() const {
        return (double)numerator / denominator;
    }

};


fraction operator+(const fraction& a, const fraction& b) {
    fraction res;
    int numerator = a.getNumerator() * b.getDenominator() + a.getDenominator() * b.getNumerator();
    int denominator = a.getDenominator() * b.getDenominator();
    res.set(numerator, denominator);
    return res;
}

fraction operator+(const fraction& a, const int& number) {
    return a + fraction(number, 1);
}

fraction operator+(const int& number, const fraction& a) {
    return fraction(number, 1) + a;
}

fraction operator-(const fraction& a, const fraction& b) {
    fraction res;
    int numerator = a.getNumerator() * b.getDenominator() - a.getDenominator() * b.getNumerator();
    int denominator = a.getDenominator() * b.getDenominator();
    res.set(numerator, denominator);
    return res;
}

fraction operator-(const fraction& a, const int& number) {
    return a - fraction(number, 1);
}

fraction operator-(const int& number, const fraction& a) {
    return fraction(number, 1) - a;
}

fraction operator*(const fraction& a, const fraction& b) {
    fraction res;
    int numerator = a.getNumerator() * b.getNumerator();
    int denominator = a.getDenominator() * b.getDenominator();
    res.set(numerator, denominator);
    return res;
}

fraction operator*(const fraction& a, const int& number) {
    return a * fraction(number, 1);
}

fraction operator*(const int& number, const fraction& a) {
    return fraction(number, 1) * a;
}

fraction operator/(const fraction& a, const fraction& b) {
    fraction res;
    int numerator = a.getNumerator() * b.getDenominator();
    int denominator = a.getDenominator() * b.getNumerator();
    res.set(numerator, denominator);
    return res;
}

fraction operator/(const fraction& a, const int& number) {
    return a / fraction(number, 1);
}

fraction operator/(const int& number, const fraction& a) {
    return fraction(number, 1) / a;
}

bool operator==(const fraction& a, const fraction& b) {
    return (double)a == (double)b;
}

bool operator!=(const fraction& a, const fraction& b) {
    return !(a == b);
}

bool operator>(const fraction& a, const fraction& b) {
    return (double)a > (double)b;
}

bool operator<(const fraction & a, const fraction & b) {
    return (double)a < (double)b;
}

bool operator>=(const fraction& a, const fraction& b) {
    return (double)a >= (double)b;
}

bool operator<= (const fraction & a, const fraction & b) {
    return (double)a <= (double)b;
}

ostream& operator<<(ostream& os, const fraction& obj) {
    os << obj.getNumerator() << "/" << obj.getDenominator() << endl;
    return os;
}

istream& operator>>(istream& is, fraction& obj) {
    int num, den;
    is >> num >> den;
    obj.set(num, den);
    return is;
}




int main() {

   /* fraction f1(3, 4);
    fraction f2(9, 12);
    fraction res = f1 + f2;*/
    fraction f3;

    //cout << res;
    cin >> f3;
    cout << f3;


	return 0;
}
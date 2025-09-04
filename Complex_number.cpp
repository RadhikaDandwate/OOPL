#include <iostream>
using namespace std;

class Complex {
private:
    float real, imag;

public:
    // Default constructor
    Complex() {
        real = 0;
        imag = 0;
    }

    // Parameterized constructor 
    Complex(float r, float i) {
        real = r;
        imag = i;
    }

    // Friend function for addition
    friend Complex operator+(Complex& c1, Complex& c2);

    // Operator overloading using member functions
    Complex operator-(Complex& c) {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator*(Complex& c) {
        return Complex(real * c.real - imag * c.imag,
                       real * c.imag + imag * c.real);
    }

    Complex operator/(Complex& c) {
        float denominator = c.real * c.real + c.imag * c.imag;
        return Complex((real * c.real + imag * c.imag) / denominator,
                       (imag * c.real - real * c.imag) / denominator);
    }

    // Function to display complex number
    void display() {
        cout << real;
        if (imag >= 0)
            cout << " + " << imag << "i";
        else
            cout << " - " << -imag << "i";
        cout << endl;
    }
};

// Friend function definition
Complex operator+(Complex& c1, Complex& c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

int main() {
    float r, i;
    char ch;

    cout << "Enter first complex number:\n";
    cout << "Real: "; cin >> r;
    cout << "Imaginary: "; cin >> i >> ch;
    Complex c1(r, i);

    cout << "Enter second complex number:\n";
    cout << "Real: "; cin >> r;
    cout << "Imaginary: "; cin >> i >> ch;
    Complex c2(r, i);

    cout << "\nFirst Complex Number: ";
    c1.display();
    cout << "Second Complex Number: ";
    c2.display();

    Complex c3;

    c3 = c1 + c2;
    cout << "\nAddition: "; c3.display();

    c3 = c1 - c2;
    cout << "Subtraction: "; c3.display();

    c3 = c1 * c2;
    cout << "Multiplication: "; c3.display();

    c3 = c1 / c2;
    cout << "Division: "; c3.display();

    return 0;
}

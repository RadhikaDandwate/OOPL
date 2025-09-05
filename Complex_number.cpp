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
    cout << "Enter first complex number (real and imaginary): ";
    cin >> r >> i;
    Complex c1(r, i);

    cout << "Enter second complex number (real and imaginary): ";
    cin >> r >> i;
    Complex c2(r, i);

    Complex c3;
    int choice;

    do {
        cout << "\nComplex Number Operations\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                c3 = c1 + c2;
                cout << "Result: "; c3.display();
                break;

            case 2:
                c3 = c1 - c2;
                cout << "Result: "; c3.display();
                break;

            case 3:
                c3 = c1 * c2;
                cout << "Result: "; c3.display();
                break;

            case 4:
                c3 = c1 / c2;
                cout << "Result: "; c3.display();
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}


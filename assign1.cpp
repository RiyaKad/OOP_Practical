#include <iostream>

using namespace std;

class Complex {
private:
    float real;
    float imaginary;

public:
    // Constructor
    Complex(float r = 0.0, float i = 0.0) : real(r), imaginary(i) {}

    // Friend function for addition
    friend Complex operator+(const Complex& num1, const Complex& num2);

    // Friend function for multiplication
    friend Complex operator*(const Complex& num1, const Complex& num2);

    // Display the complex number
    void display() const {
        cout << real << " + " << imaginary << "i";
    }

    // Input function to read complex number from user
    friend istream& operator>>(istream& is, Complex& num);
};

// Friend function definition for addition
Complex operator+(const Complex& num1, const Complex& num2) {
    float realSum = num1.real + num2.real;
    float imagSum = num1.imaginary + num2.imaginary;
    return Complex(realSum, imagSum);
}

// Friend function definition for multiplication
Complex operator*(const Complex& num1, const Complex& num2) {
    float realmulti = num1.real * num2.real - num1.imaginary * num2.imaginary;
    float imagmulti = num1.real * num2.imaginary + num1.imaginary * num2.real;
    return Complex(realmulti, imagmulti);
}

// Input function definition for reading complex number fr
istream& operator>>(istream& is, Complex& num) {
    cout << "Enter real part: ";
    cin>> num.real;
    cout << "Enter imaginary part: ";
    cin >> num.imaginary;
    return is;
}

int main() {
    Complex num1, num2;
    
    cout << "Enter the first complex number:" << endl;
    cin >> num1;

    cout << "Enter the second complex number: " << endl;
    cin >> num2;

    Complex sum = num1 + num2;
    Complex product = num1 * num2;

    cout << " Sum: ";
    sum.display();
    cout << endl;

    cout << " multi: ";
    product.display();
    cout << endl;

    return 0;
}

#include <iostream>
using namespace std;

class Complex {
private:
    double real; // Real part
    double img;  // Imaginary part
    static int constructorCount; // Static counter for constructors
    static int destructorCount;  // Static counter for destructors

public:
    // Default constructor
    Complex() : real(0), img(0) {
        constructorCount++;
        cout << "Default constructor called" << endl;
    }

    // Constructor with parameters
    Complex(double r, double i) : real(r), img(i) {
        constructorCount++;
        cout << "Parameterized constructor called" << endl;
    }

    // Destructor
    ~Complex() {
        destructorCount++;
        cout << "This is destructor" << endl;
    }

    // Static function to display counts
    static void printCounts() {
        cout << "Total Constructors called: " << constructorCount << endl;
        cout << "Total Destructors called: " << destructorCount << endl;
    }

    // Setters
    void setValues(double r, double i) {
        real = r;
        img = i;
    }

    // Getters
    double getReal() const { return real; }
    double getImg() const { return img; }

    // Member function to add another complex number
    Complex add(const Complex& other) const {
        return Complex(real + other.real, img + other.img);
    }

    // Member function to subtract another complex number
    Complex sub(const Complex& other) const {
        return Complex(real - other.real, img - other.img);
    }

    // Function to print the complex number
    void print() const {
        if (real != 0 && img != 0) {
            if (img == 1) {
                cout << real << " + i" << endl;
            } else if (img == -1) {
                cout << real << " - i" << endl;
            } else if (img > 0) {
                cout << real << " + " << img << "i" << endl;
            } else {
                cout << real << " - " << -img << "i" << endl;
            }
        } else if (real != 0) {
            cout << real << endl;
        } else if (img != 0) {
            if (img == 1) {
                cout << "i" << endl;
            } else if (img == -1) {
                cout << "-i" << endl;
            } else {
                cout << img << "i" << endl;
            }
        } else {
            cout << 0 << endl;
        }
    }
};

// Initialize static variables
int Complex::constructorCount = 0;
int Complex::destructorCount = 0;

// Standalone function for subtraction
Complex sub(const Complex& c1, const Complex& c2) {
    return Complex(c1.getReal() - c2.getReal(), c1.getImg() - c2.getImg());
}

int main() {
    Complex c1, c2, c3;  // c3 will be used for both addition and subtraction
    double realPart, imgPart;

    // Input for c1
    cout << "Enter the real part of c1: ";
    cin >> realPart;
    cout << "Enter the imaginary part of c1: ";
    cin >> imgPart;
    c1.setValues(realPart, imgPart);

    // Input for c2
    cout << "Enter the real part of c2: ";
    cin >> realPart;
    cout << "Enter the imaginary part of c2: ";
    cin >> imgPart;
    c2.setValues(realPart, imgPart);

    // Adding c1 and c2 and storing the result in c3
    c3 = c1.add(c2);
    cout << "Result of c1 + c2: ";
    c3.print();

    // Subtracting c1 and c2 and storing the result in c3
    c3 = c1.sub(c2);
    cout << "Result of c1 - c2: ";
    c3.print();

    // Print constructor and destructor counts
    Complex::printCounts();

    return 0;
}



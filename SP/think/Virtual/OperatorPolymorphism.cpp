/**
 * OperatorPolymorphism.cpp -- Polymorphism with overloaded operators.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-09-05 [Thursday, 248]
 *
 * Build:
 *   g++ OperatorPolymorphism.cpp -o OperatorPolymorphism
 */

#include <iostream>

using namespace std;

class Matrix;
class Scalar;
class Vector;

class Math {
    public:
        virtual Math& operator*(Math& rv) = 0;
        virtual Math& multiply(Matrix*) = 0;
        virtual Math& multiply(Scalar*) = 0;
        virtual Math& multiply(Vector*) = 0;
        virtual ~Math() {}
};

class Matrix : public Math {
    public:
        /*
         * A virtual function is only capable of making a single dispatch – that is,
         * determining the type of one unknown object. To determine both types a
         * technique called multiple dispatching is used in this example, whereby
         * what appears to be a single virtual function call results in a second
         * virtual call.
         */
        Math& operator*(Math& rv) {
            cout << "Matrix::operator*" << endl;
            return rv.multiply(this); // 2nd dispatch
        }

        Math& multiply(Matrix*) {
            cout << "Matrix * Matrix" << endl;
            return *this;
        }

        Math& multiply(Scalar*) {
            cout << "Scalar * Matrix" << endl;
            return *this;
        }

        Math& multiply(Vector*) {
            cout << "Vector * Matrix" << endl;
            return *this;
        }
};

class Scalar : public Math  {
    public:
        Math& operator*(Math& rv) {
            cout << "Scalar::operator*" << endl;
            return rv.multiply(this); // 2nd dispatch
        }

        Math& multiply(Matrix*) {
            cout << "Matrix * Scalar" << endl;
            return *this;
        }

        Math& multiply(Scalar*) {
            cout << "Scalar * Scalar" << endl;
            return *this;
        }

        Math& multiply(Vector*) {
            cout << "Vector * Scalar" << endl;
            return *this;
        }
};

class Vector : public Math  {
    public:
        Math& operator*(Math& rv) {
            cout << "Vector::operator*" << endl;
            return rv.multiply(this); // 2nd dispatch
        }

        Math& multiply(Matrix*) {
            cout << "Matrix * Vector" << endl;
            return *this;
        }

        Math& multiply(Scalar*) {
            cout << "Scalar * Vector" << endl;
            return *this;
        }

        Math& multiply(Vector*) {
            cout << "Vector * Vector" << endl;
            return *this;
        }
};

int main() {
    Matrix m; Vector v; Scalar s;
    Math* math[] = { &m, &v, &s };
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) {
            Math& m1 = *math[i];
            Math& m2 = *math[j];
            m1 * m2;
        }

    return 0;
} ///:~

/* Output:
   Matrix::operator*
   Matrix * Matrix
   Matrix::operator*
   Matrix * Vector
   Matrix::operator*
   Matrix * Scalar
   Vector::operator*
   Vector * Matrix
   Vector::operator*
   Vector * Vector
   Vector::operator*
   Vector * Scalar
   Scalar::operator*
   Scalar * Matrix
   Scalar::operator*
   Scalar * Vector
   Scalar::operator*
   Scalar * Scalar
 */

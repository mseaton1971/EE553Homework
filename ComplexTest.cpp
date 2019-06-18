/*
	Author: Marlon Seaton
 */
#include <iostream>
using namespace std;

class Complex
{
   private:
   double realpart;
   double imaginarypart;

   public:
   
   Complex(double real, double imaginary);
   void print() const;
   friend Complex operator+(const Complex, const Complex);
   Complex operator-() const;
   Complex add(Complex b) const;
 
};

Complex::Complex(double real, double imaginary)
{
   realpart = real;
   imaginarypart = imaginary;
}


Complex operator+(Complex a,Complex b)
{
   return Complex(a.realpart + b.realpart, a.imaginarypart + b.imaginarypart);
}

Complex Complex::add(Complex b) const
{
   return Complex(realpart + b.realpart,imaginarypart + b.imaginarypart);

}

Complex Complex::operator-() const 
{
   return Complex(-(this->realpart), -(this->imaginarypart));
}

void Complex::print() const
{
   cout<<"("<<realpart<<","<<imaginarypart<<")"<<endl;

}



int main() 
{
	const Complex a(1.0, 2.0); // create a complex number with real=1.0 imag=2.0
	const Complex b(0.5, 0.0); // real = 0.5, imag = 0.0
	const Complex c = a + b;   // overload operator + using a friend function
	c.print(); // should print the following to cout: (1.5,2.0)
	// (member syntax).  Should look the same as method add where the name add
	// is replaced by operator +
	const Complex d = a.add(b); // this should be the same as the above except the name
	d.print();
	Complex e = -d; // implement unary - using a member operator. Since it has one parameter which is this should have ZERO PARAMETERS!!!
	e.print();
}



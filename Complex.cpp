#include "Complex.h"
#include <cmath>

Complex::Complex()
	{
		_real = 0.0;
		_imag = 0.0;
	}

	// Constructors
Complex::Complex(double re, double im)
	{
		_real = re;
		_imag = im;
	}
Complex::Complex(const Complex& z)
	{
		_real = z.real();
		_imag = z.imag();
	}

	// access values
double Complex::real() const
	{
		return _real;
	}
double Complex::imag() const
	{
		return _imag;
	}

	// assignment
	Complex& Complex::operator=(double r)
	{
		_real = r;
		_imag = 0;
		return *this;
	}
	Complex& Complex::operator+=(const Complex& z)
	{
		_real =+ z.real();
		_imag =+ z.imag();

		return *this;
	}
	Complex& Complex::operator-=(const Complex& z)
	{
		_real =- z.real();
		_imag =- z.imag();

		return *this;
	}
	Complex& Complex::operator*=(const Complex& z)
	{
		double r;
		double i;

		r = (_real *z.real()) - (_imag * z.imag());
		i = (_imag * z.real()) + (_real * z.imag());

		_real = r;
		_imag = i;

		return *this;
	}
	Complex& Complex::operator/=(const Complex&z)
	{
	double denom;
	double r;
	double i;

	denom = (z.real()*z.real()) + (z.imag()*z.imag());
	r  = (_real * z.real()) - (_imag * -z.imag());
        i = (_imag * z.real()) + (_real * -z.imag());

	_real = r / denom;
	_imag = i /denom;
	return *this;

	}

// basic math operations
Complex& Complex::operator=(const Complex& z)
{
	_real = z.real();
	_imag = z.imag();

	return *this;
}
Complex  operator+(const Complex& a, const Complex& b)
{
	double r;
	double i;
	r = a.real() + b.real();
	i = a.imag() + b.imag();
	
	Complex complex_return(r, i);

	return complex_return;

}
Complex operator-(const Complex& a, const Complex& b)
{
	double r;
	double i;
	r = a.real() - b.real();
	i = a.imag() - b.imag();

	Complex complex_return(r,i);

	return complex_return;
}
Complex operator*(const Complex& a, const Complex& b)
{
	double r;
	double i;
	r = a.real() * b.real() + ((-1) * b.imag() * a.imag());
	i =(a.real() * b.imag()) + (b.imag() * a.real()); 
	Complex complex_return(r,i);
	return complex_return;
}
Complex operator/(const Complex& a, const Complex& b)
{
 	double rel = 0;
	double comp = 0;
	if (b.real() == 0.0 && b.imag() == 0)
	{
	std::cout << "Division by Zero : ";
	}	
	rel =(((a.real()*b.real())-(a.imag() * -b.imag())))/norm(b);
	comp = (((a.real() * -b.imag()) + (a.imag() * b.real()))/norm(b));
	Complex c (rel,comp);
	return c;



}

// norm returns the squared magnitude of z
double norm(const Complex& z)
{
	double r;
	double i;
	double a;
	r = z.real() * z.real();
	i = z.imag() * z.imag();
	a = r + i;
	return a;
}
// conj returns the complex conjugate of z
Complex conj(const Complex& z)
{
	Complex total(z.real(), -(z.imag()));

	return total;
}

// comparison
bool operator==(const Complex& a, const Complex& b)
{
	return ((a.real() == b.real()) && (a.imag() == b.imag()));
}
bool operator==(const Complex& a, double r)
{
	return ((a.real() == r) && (a.imag() == 0));
}
bool operator!=(const Complex& a, const Complex& b)
{
	return ((a.real() != b.real()) || (a.imag() != b.imag()));
}
bool operator!=(const Complex& a, double r)
{
	return ((a.real() != r)||(a.imag() != 0));
}

// write the complex number z to the output stream in the
// format "6+5i" or "6-5i"
std::ostream& operator<<(std::ostream& out, const Complex& z)
{
	out << z.real() << (z.imag() < 0? "-":"+") << z.imag() << "i";
	return out;
}

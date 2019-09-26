#include <iostream>

// change the value below to 1 to run tests against your Complex class.
// change the value below to 0 to run tests against the built in std::complex.

#if 0
#include "Complex.h"
#else
#include <complex>
typedef std::complex<double> Complex;
#endif

bool Approximately(double val1, double val2, double eps)
{
	return abs(val1-val2) < eps;
}

void Assert(bool cond, std::string message)
{
	if (cond)
		std::cout << "Pass: " << message << std::endl;
	else
		std::cerr << "FAIL: " << message << std::endl;
}

int main()
{
	Complex z1(4, 3);
	Complex z2(6, -5);
	Complex z3(-6, -4);
	Complex z4(-2, 5);
	Complex z8(-8, 0);

	Assert(z1.real() == 4, "real constructor");
	Assert(z3.real() == -6, "real constructor");
	Assert(z1.imag() == 3, "real constructor");
	Assert(z8.imag() == 0, "real constructor");
	Assert(norm(z1) == 25, "complex norm");
	Assert(z1 == z2, "These are not equal");
	Assert(z8 == z4, "These are not equal");
	Assert((z1 + z2) == Complex(10, -2), "the answer is correct"); 
	Assert((z8 + z2) == Complex(-2, -5), "the answer is correct"); 
	Assert((z2 - z1) == Complex(2, -8), "the answer is correct");	
	Assert(conj(z1) == Complex(4, -3), "this is the conjuate");
	Assert(Approximately(norm(z2),61,1e-8), "Complex Norm"); 	
	Assert(Approximately(norm(z3),52,1e-8), "Complex Norm");
	Assert(conj(z4) == Complex(-2, -5), "this is the conjuate");
	Assert(z1 != z2, "These are not equal");
	Assert(z4 != z2, "These are not equal");
	Assert((z1 * z2) == Complex(39, -2), "this is z1 * z2");
	Complex z5 = z1 / z2;
	Assert(Approximately(z5.real(), 36./61.,1e-8), "z1/z2 Real Part");
	Assert(Approximately(z5.imag(), -2./61.,1e-8), "z1/z2 Imaginary Part");
	Complex (z1 /= z2);
	Assert(Approximately(z1.real(), 36./61.,1e-8), "z1/z2 Real Part");
	Assert(Approximately(z1.imag(), -2./61.,1e-8), "z1/z2 Imaginary Part");
	Assert((z2 *= z4) == Complex(13, 40), "z2 *= z4");
	Assert((z3 += z2) == Complex(7, 36), "z3 += z1");
	Assert((z4 -= z2) == Complex(-15, -35), "z4 -= z3");
	
	return 0;
}



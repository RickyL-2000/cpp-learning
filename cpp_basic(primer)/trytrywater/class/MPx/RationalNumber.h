#ifndef RATIONAL_NUMBER_H
#define RATIONAL_NUMBER_H

#include "Number.h"
class RationalNumber; //This is a forward declaration, needed only to remove circular dependencies
#include "ComplexNumber.h"
#include "RealNumber.h"
#include <stdlib.h>

class RationalNumber:public Number{
	private:
		//Class variables
		int numerator;
		int denominator;
	public:
		//Empty Constructor
		RationalNumber();
		//Complete Constructor
		RationalNumber(int numer, int denom);
		
		//Setter and getter functions
		void set_numerator(int numer);
		void set_denominator(int denom);
		int get_numerator(void) const;
		int get_denominator(void) const;

		//Class member functions
		void set_value (int numer, int denom);
		int gcd(int a, int b);
		double magnitude();
		double decimal_value() const;

		//Operation overload for RationalNumber (op) RationalNumber
		RationalNumber operator + (const RationalNumber& arg);
		RationalNumber operator - (const RationalNumber& arg);
		RationalNumber operator * (const RationalNumber& arg);
		RationalNumber operator / (const RationalNumber& arg);

		//Operation overload for RationalNumber (op) ComplexNumber
		ComplexNumber operator + (const ComplexNumber& arg);
		ComplexNumber operator - (const ComplexNumber& arg);
		ComplexNumber operator * (const ComplexNumber& arg);
		ComplexNumber operator / (const ComplexNumber& arg);

		//Operation overload for RationalNumber (op) RealNumber
		RealNumber operator + (const RealNumber& arg);
		RealNumber operator - (const RealNumber& arg);
		RealNumber operator * (const RealNumber& arg);
		RealNumber operator / (const RealNumber& arg);

		//Output class variables as string (provided)
		string to_String(void);
};

#endif

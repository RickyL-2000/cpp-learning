#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

#include "Number.h"
class ComplexNumber;  //This is a forward declaration, needed only to remove circular dependencies
#include "RealNumber.h"
#include "RationalNumber.h"
#include <cmath>
#include <iostream>

class ComplexNumber:public Number{
	private:
		//Class variables
		double realComponent;
		double imagComponent;
	public:
		//Empty Constructor
		ComplexNumber();
		//Complete Constructor
		ComplexNumber(double real, double imag);

		//Setter and getter functions
		void set_realComponent(double rval);
		void set_imagComponent(double ival);
		double get_realComponent(void) const;
		double get_imagComponent(void) const;
		void set_value (double rval, double ival);

		//Class member functions
		double magnitude();

		//Operation overload for ComplexNumber (op) ComplexNumber
		ComplexNumber operator + (const ComplexNumber& arg);
		ComplexNumber operator - (const ComplexNumber& arg);
		ComplexNumber operator * (const ComplexNumber& arg);
		ComplexNumber operator / (const ComplexNumber& arg);

		//Operation overload for ComplexNumber (op) RealNumber		
		ComplexNumber operator + (const RealNumber& arg);
		ComplexNumber operator - (const RealNumber& arg);
		ComplexNumber operator * (const RealNumber& arg);
		ComplexNumber operator / (const RealNumber& arg);

		//Operation overload for ComplexNumber (op) RationalNumber	
		ComplexNumber operator + (const RationalNumber& arg);
		ComplexNumber operator - (const RationalNumber& arg);
		ComplexNumber operator * (const RationalNumber& arg);
		ComplexNumber operator / (const RationalNumber& arg);

		//Output class variables as string (provided)
		string to_String(void);
};

#endif

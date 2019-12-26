#include "RealNumber.h"


//to_String converts real and imaginary components to string of type a+bi
string RealNumber::to_String(void){
	stringstream my_output;
	my_output << value;
	return my_output.str();
}


RealNumber::RealNumber() { NumberType = REAL; value = 0.0; }
RealNumber::RealNumber(double rval) { NumberType = REAL; value = rval; }

void RealNumber::set_value(double rval) { value = rval; }
double RealNumber::get_value(void) const { return value; }

double RealNumber::magnitude() { return (value<0) ? (-value) : value; } 

RealNumber RealNumber::operator + (const RealNumber& arg) 
{
    return RealNumber(this->value + arg.value);
}

RealNumber RealNumber::operator - (const RealNumber& arg) 
{
    return RealNumber(this->value - arg.value);
}

RealNumber RealNumber::operator * (const RealNumber& arg)
{
    return RealNumber(this->value * arg.value);
}

RealNumber RealNumber::operator / (const RealNumber& arg) 
{
    return RealNumber(this->value / arg.value);
}

ComplexNumber RealNumber::operator + (const ComplexNumber& arg)
{
    return ComplexNumber((this->value+arg.get_realComponent()), arg.get_imagComponent()); 	
}

ComplexNumber RealNumber::operator - (const ComplexNumber& arg)
{
    return ComplexNumber((this->value-arg.get_realComponent()), (-1.0*arg.get_imagComponent())); 	
}

ComplexNumber RealNumber::operator * (const ComplexNumber& arg)
{
    return ComplexNumber(this->value*arg.get_realComponent(), this->value*arg.get_imagComponent());
}

ComplexNumber RealNumber::operator / (const ComplexNumber& arg)
{
    double rc = this->value*arg.get_realComponent();
    double ic = this->value*arg.get_imagComponent()*(-1.);	
    double d = arg.get_realComponent()*arg.get_realComponent()+arg.get_imagComponent()*arg.get_imagComponent();
    return ComplexNumber(rc/d, ic/d);
}

RealNumber RealNumber::operator + (const RationalNumber& arg)
{
    double rn = arg.decimal_value();
    return RealNumber(this->value + rn);
}

RealNumber RealNumber::operator - (const RationalNumber& arg)
{
    double rn = arg.decimal_value();
    return RealNumber(this->value - rn);
}

RealNumber RealNumber::operator * (const RationalNumber& arg)
{
    double rn = arg.decimal_value();
    return RealNumber(this->value*rn);
}

RealNumber RealNumber::operator / (const RationalNumber& arg)
{
    double rn = arg.decimal_value();
    return RealNumber(this->value / rn);
}


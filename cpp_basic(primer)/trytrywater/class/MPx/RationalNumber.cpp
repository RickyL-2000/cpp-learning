#include "RationalNumber.h"

//to_String converts numerator and denominator to string of type num/denom
string RationalNumber::to_String(void){
	stringstream my_output;
	my_output << numerator << "/" << denominator;
	return my_output.str();
}


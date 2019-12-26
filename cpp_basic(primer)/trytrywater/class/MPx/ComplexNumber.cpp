#include "ComplexNumber.h"

//to_String converts real and imaginary components to string of type a+bi
string ComplexNumber::to_String(void){
	stringstream my_output;
	my_output << realComponent;
	if(imagComponent >= 0){
		my_output << " + " << imagComponent << "i";
	}
	else if(imagComponent < 0){
		my_output << "-" << imagComponent*(-1) << "i";
	}
	return my_output.str();
}

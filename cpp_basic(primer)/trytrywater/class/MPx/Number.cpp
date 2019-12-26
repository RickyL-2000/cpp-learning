#include "Number.h"

//Empty constructor sets NumberType as undefined value
Number::Number(){
	NumberType = -1;
}

//Complete constructor sets NumberType according to input value
Number::Number(int my_Number_type){
	NumberType = my_Number_type;
}

//toString function prints warning if to string function not overloaded
string Number::to_String(void){
	stringstream my_output;
	string Number_type_string = "";
	switch (NumberType){
		case REAL:
			Number_type_string = "REAL";
			break;
		case COMPLEX:
			Number_type_string = "COMPLEX";
			break;
		case RATIONAL:
			Number_type_string = "RATIONAL";
			break;
		default:
			Number_type_string = "UNDEFINED";
			break;
	}
	my_output << "Error: Number type ";
	my_output << Number_type_string;
	my_output << " does not have a valid to_String() method!!\n";
	string output_string = my_output.str();
	return output_string;
}

//Getter function for NumberType variable
int Number::get_NumberType() const{
	return NumberType;
}

//Setter function for NumberType variable
void Number::set_NumberType(int my_Number_type){
	NumberType = my_Number_type;
}

//Operator for + Will never execute (should be overwritten by derived class)
Number Number::operator + (const Number& arg)
{
    Number result;
    return result;
}

//Operator for - Will never execute (should be overwritten by derived class)
Number Number::operator - (const Number& arg)
{
    Number result;
    return result;
}

//Operator for * Will never execute (should be overwritten by derived class)
Number Number::operator * (const Number& arg)
{
    Number result;
    return result;
}

//Operator for / Will never execute (should be overwritten by derived class)
Number Number::operator / (const Number& arg)
{
    Number result;
    return result;
}

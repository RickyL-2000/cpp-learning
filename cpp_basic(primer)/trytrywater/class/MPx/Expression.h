#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include "Number.h"
#include "ComplexNumber.h"
#include "RealNumber.h"
#include "RationalNumber.h"
#include <iostream>

//This class is used for parsing input as read from file and generating output
//Do not modify

class Expression{
	private:
		char my_operator;
		ComplexNumber complex1, complex2, complex3;
		RealNumber real1, real2, real3;
		RationalNumber rational1, rational2, rational3;
		Number* left_Number;
		Number* right_Number;
		Number* result;
	public:
		Expression();
		Expression(string expression_string);
		std::string::iterator read_real(string expression_string, std::string::iterator current_iter, int Number_count);
		std::string::iterator read_complex(string expression_string, std::string::iterator current_iter, int Number_count);
		std::string::iterator read_rational(string expression_string, std::string::iterator current_iter, int Number_count);
		bool input_expression(string expression_string);
		void evaluate_expression();
		string print_result();
};

#endif

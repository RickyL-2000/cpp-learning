#include "Expression.h"

//Instantiates Empty Expression
Expression::Expression(){
	my_operator = '0';
	left_Number = NULL;
	right_Number = NULL;
	result = NULL;
}

//Instantiates Expression and parses input string
Expression::Expression(string expression_string){
	my_operator = '0';
	left_Number = NULL;
	right_Number = NULL;
	result = NULL;
	input_expression(expression_string);
}

//Function used to parse real number
std::string::iterator Expression::read_real(string expression_string, std::string::iterator my_iter, int Number_count){
	stringstream value_container;
	double value;
	bool first_num = true;
	for ( ; my_iter!=expression_string.end(); ++my_iter){
		char current_character = *my_iter;
		bool negative_detection = first_num && current_character == '-';
		if (isdigit(current_character) || negative_detection || current_character == '.'){
			first_num = false;
			value_container << current_character;
		}
		else{break;}
	}

	value_container >> value;
	if(Number_count == 0){
		real1 = RealNumber(value);
		left_Number = &real1;
	}
	else if(Number_count == 1){
		real2 = RealNumber(value);
		right_Number = &real2;
	}
	return my_iter;
}

//Function used to parse rational number
std::string::iterator Expression::read_rational(string expression_string, std::string::iterator my_iter, int Number_count){
	stringstream value_container1;
	stringstream value_container2;
	int value1, value2;
	int current_value = 1;
	bool paren_found = false;
	bool first_num = true;
	for ( ; my_iter!=expression_string.end(); ++my_iter){
		char current_character = *my_iter;
		bool negative_detection = first_num && current_character == '-';
		if(!paren_found && current_character == '('){
			paren_found = true;
		}
		else if(paren_found && current_character == ')'){
			break;
		}
		else if (isdigit(current_character) || negative_detection){
			first_num = false;
			if(current_value == 1){
				value_container1 << current_character;
			}
			else if(current_value == 2){
				value_container2 << current_character;
			}
		}
		else if(current_character=='/' && current_value == 1){
			first_num = true;
			current_value = 2;
		}
		else if(current_character!=' '){
			break;
		}
	}

	value_container1 >> value1;
	value_container2 >> value2;
	if(Number_count == 0){
		rational1 = RationalNumber(value1,value2);
		left_Number = &rational1;
	}
	else if(Number_count == 1){
		rational2 = RationalNumber(value1,value2);
		right_Number = &rational2;
	}
	return my_iter;
}

//Function used to parse complex number
std::string::iterator Expression::read_complex(string expression_string, std::string::iterator my_iter, int Number_count){
	stringstream value_container1;
	stringstream value_container2;
	double value1, value2;
	double current_value = 1;
	bool paren_found = false;
	bool first_num = true;
	for ( ; my_iter!=expression_string.end(); ++my_iter){
		char current_character = *my_iter;
		bool negative_detection = first_num && current_character == '-';
		if(!paren_found && current_character == '('){
			paren_found = true;
		}
		else if(paren_found && current_character == ')'){
			break;
		}
		else if (isdigit(current_character) || negative_detection || current_character == '.'){
			first_num = false;
			if(current_value == 1){
				value_container1 << current_character;
			}
			else if(current_value == 2){
				value_container2 << current_character;
			}
		}
		else if(current_character=='+' && current_value == 1){
			current_value = 2;
		}
		else if(current_character=='-' && current_value == 1){
			value_container2 << "-";
			current_value = 2;
		}
		else if(current_character=='i'){
			if(current_value == 1){
				string temp_string = value_container1.str();
                value_container1.str("");
                if(temp_string.compare("")==0){
                    value_container2 << 1;
                }
                else if(temp_string.compare("-")==0){
                     value_container2 << -1;
                }
                else{
				    value_container2 << temp_string;
                }
				current_value = 3;
			}
            else if(current_value == 2){
                string temp_string = value_container2.str();
                value_container2.str("");
                if(temp_string.compare("")==0){
                    value_container2 << 1;
                }
                else if(temp_string.compare("-")==0){
                     value_container2 << -1;
                }
                else{
				    value_container2 << temp_string;
                }
                current_value = 3;
            }
		}
		else if(current_character!=' '){
			break;
		}
	}

	value_container1 >> value1;
	value_container2 >> value2;
	if(Number_count == 0){
		complex1 = ComplexNumber(value1,value2);
		left_Number = &complex1;
	}
	else if(Number_count == 1){
		complex2 = ComplexNumber(value1,value2);
		right_Number = &complex2;
	}
	return my_iter;
}


//Function used to input string
bool Expression::input_expression(string expression_string){
	int Number_count = 0;
	for ( std::string::iterator my_iter=expression_string.begin(); my_iter!=expression_string.end() && Number_count < 2; ++my_iter){
    	char current_character = *my_iter;
		bool negative_detection = current_character=='-' && (Number_count == 0 || (Number_count == 1 && my_operator != '0'));
		if (isdigit(current_character) || negative_detection){
			my_iter = read_real(expression_string,my_iter,Number_count);
			my_iter--;
			Number_count++;
		}
		else{
			switch(current_character){
				case ' ':
					break;
				case 'R':
					my_iter++;
					my_iter = read_rational(expression_string,my_iter,Number_count);
					Number_count++;
					break;
				case 'C':
					my_iter++;
					my_iter = read_complex(expression_string,my_iter,Number_count);
					Number_count++;
					break;
				case '+':
					my_operator = '+';
					break;
				case '-':
					my_operator = '-';
					break;
				case '/':
					my_operator = '/';
					break;
				case '*':
					my_operator = '*';
					break;
				default:
					cout << "Warning: '" << current_character << "' is not supported!!\n";
					break;
			}
		}
	}
	if(Number_count==2){
		return true;
	}
	else{
		return false;
	}
}

//Function used to evaluate expression
//Expressions will be evaluated based on data types of left and right operands
void Expression::evaluate_expression(){
	int left_type = left_Number->get_NumberType();
	int right_type = right_Number->get_NumberType();
	switch(my_operator){
		case '+':
			switch(left_type){
				case REAL:
					if(right_type == REAL){
						real3 = *(dynamic_cast<RealNumber*>(left_Number)) + *(dynamic_cast<RealNumber*>(right_Number));
						result = &real3;
					}
					else if(right_type == COMPLEX){
						complex3 = *(dynamic_cast<RealNumber*>(left_Number)) + *(dynamic_cast<ComplexNumber*>(right_Number));
						result = &complex3;
					}
					else if(right_type == RATIONAL){
						real3 = *(dynamic_cast<RealNumber*>(left_Number)) + *(dynamic_cast<RationalNumber*>(right_Number));
						result = &real3;
					}
					break;
				case COMPLEX:
					if(right_type == REAL){
						complex3 = *(dynamic_cast<ComplexNumber*>(left_Number)) + *(dynamic_cast<RealNumber*>(right_Number));
						result = &complex3;
					}
					if(right_type == COMPLEX){
						complex3 = *(dynamic_cast<ComplexNumber*>(left_Number)) + *(dynamic_cast<ComplexNumber*>(right_Number));
						result = &complex3;
					}
					if(right_type == RATIONAL){
						complex3 = *(dynamic_cast<ComplexNumber*>(left_Number)) + *(dynamic_cast<RationalNumber*>(right_Number));
						result = &complex3;
					}
					break;
				case RATIONAL:
					if(right_type == REAL){
						real3 = *(dynamic_cast<RationalNumber*>(left_Number)) + *(dynamic_cast<RealNumber*>(right_Number));
						result = &real3;
					}
					if(right_type == COMPLEX){
						complex3 = *(dynamic_cast<RationalNumber*>(left_Number)) + *(dynamic_cast<ComplexNumber*>(right_Number));
						result = &complex3;
					}
					if(right_type == RATIONAL){
						rational3 = *(dynamic_cast<RationalNumber*>(left_Number)) + *(dynamic_cast<RationalNumber*>(right_Number));
						result = &rational3;
					}
					break;
				default:
					*result = *left_Number + *right_Number;
					break;
			}
			break;
		case '-':
			switch(left_type){
				case REAL:
					if(right_type == REAL){
						real3 = *(dynamic_cast<RealNumber*>(left_Number)) - *(dynamic_cast<RealNumber*>(right_Number));
						result = &real3;
					}
					else if(right_type == COMPLEX){
						complex3 = *(dynamic_cast<RealNumber*>(left_Number)) - *(dynamic_cast<ComplexNumber*>(right_Number));
						result = &complex3;
					}
					else if(right_type == RATIONAL){
						real3 = *(dynamic_cast<RealNumber*>(left_Number)) - *(dynamic_cast<RationalNumber*>(right_Number));
						result = &real3;
					}
					break;
				case COMPLEX:
					if(right_type == REAL){
						complex3 = *(dynamic_cast<ComplexNumber*>(left_Number)) - *(dynamic_cast<RealNumber*>(right_Number));
						result = &complex3;
					}
					if(right_type == COMPLEX){
						complex3 = *(dynamic_cast<ComplexNumber*>(left_Number)) - *(dynamic_cast<ComplexNumber*>(right_Number));
						result = &complex3;
					}
					if(right_type == RATIONAL){
						complex3 = *(dynamic_cast<ComplexNumber*>(left_Number)) - *(dynamic_cast<RationalNumber*>(right_Number));
						result = &complex3;
					}
					break;
				case RATIONAL:
					if(right_type == REAL){
						real3 = *(dynamic_cast<RationalNumber*>(left_Number)) - *(dynamic_cast<RealNumber*>(right_Number));
						result = &real3;
					}
					if(right_type == COMPLEX){
						complex3 = *(dynamic_cast<RationalNumber*>(left_Number)) - *(dynamic_cast<ComplexNumber*>(right_Number));
						result = &complex3;
					}
					if(right_type == RATIONAL){
						rational3 = *(dynamic_cast<RationalNumber*>(left_Number)) - *(dynamic_cast<RationalNumber*>(right_Number));
						result = &rational3;
					}
					break;
				default:
					*result = *left_Number - *right_Number;
					break;
			}
			break;
		case '/':
			switch(left_type){
				case REAL:
					if(right_type == REAL){
						real3 = *(dynamic_cast<RealNumber*>(left_Number)) / *(dynamic_cast<RealNumber*>(right_Number));
						result = &real3;
					}
					else if(right_type == COMPLEX){
						complex3 = *(dynamic_cast<RealNumber*>(left_Number)) / *(dynamic_cast<ComplexNumber*>(right_Number));
						result = &complex3;
					}
					else if(right_type == RATIONAL){
						real3 = *(dynamic_cast<RealNumber*>(left_Number)) / *(dynamic_cast<RationalNumber*>(right_Number));
						result = &real3;
					}
					break;
				case COMPLEX:
					if(right_type == REAL){
						complex3 = *(dynamic_cast<ComplexNumber*>(left_Number)) / *(dynamic_cast<RealNumber*>(right_Number));
						result = &complex3;
					}
					if(right_type == COMPLEX){
						complex3 = *(dynamic_cast<ComplexNumber*>(left_Number)) / *(dynamic_cast<ComplexNumber*>(right_Number));
						result = &complex3;
					}
					if(right_type == RATIONAL){
						complex3 = *(dynamic_cast<ComplexNumber*>(left_Number)) / *(dynamic_cast<RationalNumber*>(right_Number));
						result = &complex3;
					}
					break;
				case RATIONAL:
					if(right_type == REAL){
						real3 = *(dynamic_cast<RationalNumber*>(left_Number)) / *(dynamic_cast<RealNumber*>(right_Number));
						result = &real3;
					}
					if(right_type == COMPLEX){
						complex3 = *(dynamic_cast<RationalNumber*>(left_Number)) / *(dynamic_cast<ComplexNumber*>(right_Number));
						result = &complex3;
					}
					if(right_type == RATIONAL){
						rational3 = *(dynamic_cast<RationalNumber*>(left_Number)) / *(dynamic_cast<RationalNumber*>(right_Number));
						result = &rational3;
					}
					break;
				default:
					*result = *left_Number / *right_Number;
					break;
			}
			break;
		case '*':
			switch(left_type){
				case REAL:
					if(right_type == REAL){
						real3 = *(dynamic_cast<RealNumber*>(left_Number)) * *(dynamic_cast<RealNumber*>(right_Number));
						result = &real3;
					}
					else if(right_type == COMPLEX){
						complex3 = *(dynamic_cast<RealNumber*>(left_Number)) * *(dynamic_cast<ComplexNumber*>(right_Number));
						result = &complex3;
					}
					else if(right_type == RATIONAL){
						real3 = *(dynamic_cast<RealNumber*>(left_Number)) * *(dynamic_cast<RationalNumber*>(right_Number));
						result = &real3;
					}
					break;
				case COMPLEX:
					if(right_type == REAL){
						complex3 = *(dynamic_cast<ComplexNumber*>(left_Number)) * *(dynamic_cast<RealNumber*>(right_Number));
						result = &complex3;
					}
					if(right_type == COMPLEX){
						complex3 = *(dynamic_cast<ComplexNumber*>(left_Number)) * *(dynamic_cast<ComplexNumber*>(right_Number));
						result = &complex3;
					}
					if(right_type == RATIONAL){
						complex3 = *(dynamic_cast<ComplexNumber*>(left_Number)) * *(dynamic_cast<RationalNumber*>(right_Number));
						result = &complex3;
					}
					break;
				case RATIONAL:
					if(right_type == REAL){
						real3 = *(dynamic_cast<RationalNumber*>(left_Number)) * *(dynamic_cast<RealNumber*>(right_Number));
						result = &real3;
					}
					if(right_type == COMPLEX){
						complex3 = *(dynamic_cast<RationalNumber*>(left_Number)) * *(dynamic_cast<ComplexNumber*>(right_Number));
						result = &complex3;
					}
					if(right_type == RATIONAL){
						rational3 = *(dynamic_cast<RationalNumber*>(left_Number)) * *(dynamic_cast<RationalNumber*>(right_Number));
						result = &rational3;
					}
					break;
				default:
					*result = *left_Number * *right_Number;
					break;
			}
			break;
		default:
			cout << "Warning: Operation '" << my_operator << "' is not supported!!\n";
			break; 
	}
}

//Print output results
string Expression::print_result(){
	result->get_NumberType();
	string output_string;
	switch(result->get_NumberType()){
		case REAL:
			output_string = (dynamic_cast<RealNumber*>(result))->to_String();
			break;
		case COMPLEX:
			output_string = (dynamic_cast<ComplexNumber*>(result))->to_String();
			break;
		case RATIONAL:
			output_string = (dynamic_cast<RationalNumber*>(result))->to_String();
			break;
		default:
			output_string = "Error: result NumberType is undefined!\n";
			break;
	}
	return output_string;
}

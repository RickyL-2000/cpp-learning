#ifndef Number_H
#define Number_H

#include <string>
#include <sstream>
using namespace std;

enum Number_Types { REAL, COMPLEX, RATIONAL };

class Number {
	protected:
		//Superclass variables (inherited by all derived classes)
		int NumberType;
	public:	
		//Superclass constructors
		Number();
		Number(int my_Number_type);

		//Setter and getter functions
		void set_NumberType(int my_Number_type);
		int get_NumberType(void) const;		

		//operator overload
		virtual Number operator + (const Number& arg);
		virtual Number operator - (const Number& arg);
		virtual Number operator * (const Number& arg);
		virtual Number operator / (const Number& arg);

		//Converts class data to string (provides warning if derived class not used)
		string to_String(void);
};

#endif

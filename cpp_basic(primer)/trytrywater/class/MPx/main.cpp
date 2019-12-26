#include <iostream>
#include <fstream>
#include <string>
#include "Expression.h"
#define ARGS 3


using namespace std;

//Main function: do not modify
int main(int argc,char *argv[])
{
	if (argc != ARGS) {
		fprintf(stderr,"Wrong number of arguments.\nCorrect usage: %s tests.txt output_file.txt\n",
					argv[0]);
		return -1;
	}
   ifstream inFile (argv[1]);
   ofstream outFile (argv[2]);
   string current_line = "";

   while (inFile)
   {
		getline(inFile, current_line);
		Expression my_expression = Expression();
		if(my_expression.input_expression(current_line)){
			my_expression.evaluate_expression();
			outFile << my_expression.print_result() << endl;
		}
   }
   inFile.close();
   outFile.close();

   return 0;
}

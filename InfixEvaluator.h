
#include <string>
using namespace std;
/**
 * Author: Lauren Abrishami
 * Date: 7/7/20
 * Purpose: header for InfixEvaluator.cpp
 */
class InfixEvaluator
{
	private:
		string string_tokens;
		int n = 0;
		string token_array[100];
		string operator_stack[50];
		double operand_stack[50];
		int operand_temp;
		string operator_temp;
		
		double result=0;
		int operatorIndex = 0;
		System::Boolean did_something = false;
		int temp = 0;
		double operand1 = 0;
		double operand2 = 0;
		string operatorTemp;
		string string_without_space;
		int operand_index;
		int operator_index;
		int index = 0;

	public:
		double evaluate_infix(string infix_string);
		void push_operator_stack(string token);
		string pop_operator_stack();
		void push_operand_stack(double token);
		double pop_operand_stack();
		void execute_operation();
		string remove_whitespace(string base_string);

};


#include "InfixEvaluator.h"
using namespace std;

/**
 * Author: Lauren Abrishami
 * Date: 7/7/20
 * Purpose: This program will separate a string into tokens and-
 * push tokens into 2 stacks based on whether they are operands or operators and perform operations-
   based on the order of those operands and operators (according to precedence).
   There are methods to pop and push elements into the stacks-
 * and a method to perform arithmetic operations.
 */

const std::string WHITESPACE = " \n\r\t\f\v";

//method for trimming whitespace on the left of a string
std::string ltrim(const std::string& s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}

//method for trimming whitespace on the right of a string
std::string rtrim(const std::string& s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

//calls ltrim and rtrim to trim all whitespace from a string
string InfixEvaluator::remove_whitespace(string base_string) {
    return rtrim(ltrim(base_string));
}
void InfixEvaluator::push_operand_stack(double token) {
    
    
    operand_stack[operand_index++] = token;
}
void InfixEvaluator::push_operator_stack(string token) {
    
    
    operator_stack[operator_index++] = token;
}
double InfixEvaluator::pop_operand_stack() {
    
        return operand_stack[--operand_index];
}
string InfixEvaluator::pop_operator_stack() {
    
        return operator_stack[--operator_index];
}
void InfixEvaluator::execute_operation() {

    //if there's at least one operator and 2 operands, execute the operation
    if (operator_index != 0 && operand_index>1) {
        
        operator_temp = pop_operator_stack();
        operand1 = pop_operand_stack();
        int in_parenth = 0;
        operand2 = pop_operand_stack();
       
    
        if (operator_temp=="+") {
            
            did_something = true;
            result = operand2 + operand1;
        }
        else if (operator_temp == "-") {
            did_something = true;
            
            //if not inside parenthesis, the execution will happen backwards
            if (!in_parenth) { result = operand2 - operand1; }
            else result = operand1 - operand2;
        }
        else if (operator_temp == "/") {
            did_something = true;
            
            if (!in_parenth) { result = operand2/operand1; }
            else result = operand1/operand2;
        }
        else if(operator_temp == "*") {
            did_something = true;
            
            result = operand1*operand2;
        }
        
        
        
        push_operand_stack(result);

    }
    
    
    
}

double InfixEvaluator::evaluate_infix(string infix_string) {
                                                                             
        operand_index = 0;
        operator_index = 0;                                                          
        string num_temp = "";
        string op_temp = "";
        string_without_space = remove_whitespace(infix_string);
        int in_parenth = 0;


        //for each character in the input string
        for (int i = 0; i < string_without_space.size(); i++) {

           
            if (isdigit(string_without_space.at(i)) || string_without_space.at(i) == '.') {


                //the number is added to a string. If a number or . follows this number, 
                //it will be added as well.
                num_temp += string_without_space.at(i);

                //If there is a parenthesis before the number, multiplication is in order
                if (i != 0) {
                    if (string_without_space.at(i - 1) == ')') {
                        push_operator_stack("*");
                    }
                }
                //if this is the last number in the string, it is added to the stack
                if (i == string_without_space.size() - 1) {

                    push_operand_stack(stod(num_temp));
                    
                }
                //if this number is followed by an operator, it is added to the stack
                else if (i != string_without_space.size() - 1) {
                    if (string_without_space.at(i + 1) == '-'
                        || string_without_space.at(i + 1) == '+'
                        || string_without_space.at(i + 1) == '/'
                        || string_without_space.at(i + 1) == '*') {
                        push_operand_stack(stod(num_temp));
                        num_temp = "";
                    }
                    
                }
                
               

            }
            
            else if (string_without_space.at(i) == '(') {

                in_parenth = 1;
                if (i != 0) {

                    //if there's a number before the parenthesis, multiplication needs to be done
                    if (isdigit(string_without_space.at(i - 1))) {
                        push_operand_stack(stod(num_temp));
                        num_temp = "";
                        push_operator_stack("*");
                    }
                    //if right and left parenthesis are next to eachother,  
                    //multiplication needs to be done
                    else if(string_without_space.at(i - 1) == ')') {
                        push_operator_stack("*");
                    }

                }
                
                push_operator_stack("(");



            }
            else if (string_without_space.at(i) == ')') {

                if(i!=0){
                //if there's a digit before the end parenthesis, it is added to the stack
                    if (isdigit(string_without_space.at(i - 1))) {
                        push_operand_stack(stod(num_temp));
                        num_temp = "";
                    }
                }
                //operations inside the parenthesis are executed
                if (operand_index > 1 && operator_index > 0) {
                    while (operator_stack[operator_index - 1] != "(") {

                        
                            execute_operation();
                        
                    }
                }
                in_parenth = 0;
                pop_operator_stack(); //discard left parenthesis

            }
            if (string_without_space.at(i) == '-'
                || string_without_space.at(i) == '+'
                || string_without_space.at(i) == '/'
                || string_without_space.at(i) == '*') {
                op_temp = string_without_space.at(i);
                while (operator_index != 0 && operand_index > 1) {

                    //operation executed if there's no operator with higher or the same precedence
                    if ((string_without_space.at(i) == '+' ||
                        string_without_space.at(i) == '-') && (
                        (operator_stack[operator_index-1] == "+" ||   
                            (operator_stack[operator_index-1] == "-" ||  
                            (operator_stack[operator_index - 1] == "*" ||  
                                (operator_stack[operator_index - 1] == "/")))))) {

                        execute_operation();
                        
                    }
                    else if ((string_without_space.at(i) == '*' ||
                        string_without_space.at(i) == '/') && (
                        (operator_stack[operator_index - 1] == "*" ||   //Checks if operator at the top of the stack-
                            (operator_stack[operator_index - 1] == "/")))) {

                        execute_operation();
                        
                    }
                    
                    else {
                        break;
                    }


                }
                push_operator_stack(op_temp);

            }
        }
        
        while (operator_index != 0 && operand_index>1) {
            
            
            execute_operation();
        }
        if (did_something) {
            return result;
        }
        else {
            
            throw - 1;
        }
        
}

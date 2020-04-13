#include <iostream>
#include "NodeStack.h"
#include "NodeStack.cpp"
#include "string.h"
#include <math.h>;

//Subtract a char value of a number by this to get it as an interger
#define ASCII_OF_ZERO 48

//Usine namespace because I like danger ;)
using namespace std;

//Get the priority level of a character as a char. Priority goes from low->high 1->3. Returns 0 if it's not an operator
int getPriority(char x) {
	if (x == '+' || x == '-') {
		return 1;
	}
	if (x == '*' || x == '/') {
		return 2;
	}
	if (x == '^') {
		return 3;
	}
	return 0;
}
int main() {
	//Initialize variables for stack, user input, and output of infix
	NodeStack<double> stack;
	string readIn;
	string output;

	//read in user input
	cout << "Enter an expression in infix form to be converted to postfix and evaluated!" << endl;
	cin >> readIn;

	/*////////////////////////////////////////////////////////////////////////////////////////////
	Convert to Postfix Form
	*/////////////////////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < readIn.length(); i++) {
		char c = readIn[i];				//Current character
		int priority = getPriority(c);	//Priority of current character
		double prev;					//previous member of stack

		//Handle any error that may occur if stack is empty
		try {
			prev = stack.peek();
		}
		catch (int e) {
			prev = e;
		}

		//if operand, add to stack
		if (c >= 48 && c <= 57) {
			output += c;
		}//If not then make sure it's a valid character
		else if(priority){
			//If first member of stack getPriority will return 0 and this will be true
			if (priority >= getPriority(prev)) {
				stack.push(c);
			}
			//If the priority is less than the last thing in stack then take that out and keep trying until priority is correct
			else {
				while (priority < getPriority(prev)) {
					output += stack.peek();
					stack.pop();
					//get the new previous
					try {
						prev = stack.peek();
					}
					catch (int e) {
						prev = e;
					}
				}
				stack.push(c);
				
			}
		}
		else {
			//non valid character throws error
			throw("Unknown operator encountered");
		}
		
	}
	//empty what is left of the stack to output
	while (!stack.isEmpty()) {
		output += stack.peek();
		stack.pop();
	}

	//clear the stack so we can use it to evaluate too!
	stack.clear();

	/*////////////////////////////////////////////////////////////////////////////////////////////
	Evaluate Postfix
	*/////////////////////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < output.length(); i++) {
		char c = output[i];
		if (c >= 48 && c <= 57) {
			stack.push((int)c-ASCII_OF_ZERO);
		}
		else if (getPriority(c)) {				//will return 0 if not a valid operator
			double operand1 = stack.peek();
			stack.pop();
			double operand2 = stack.peek();
			stack.pop();
			//Switch
			switch (c) {
			case('+'):
				stack.push(operand2 + operand1);
				break;
			case('-'):
				stack.push(operand2 - operand1);
				break;
			case('*'):
				stack.push(operand2 * operand1);
				break;
			case('/'):
				stack.push(operand2 / operand1);
				break;
			case('^'):
				stack.push(pow(operand2, operand1));
			}
		}
	}
	//Print out the postfix expression
	cout << "POSTFIX EXPRESSION" << endl;
	cout << output << endl;
	//Print the evaluation saved in the stack
	cout << "EVALUATION" << endl;
	cout << stack.peek() <<endl;
	return 0;
}
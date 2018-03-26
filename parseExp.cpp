// MARIEL TRAJANO
// CECS 282H HONORS LAB 2

#include <iostream>
#include <stack>
#include <cstring>
#include <typeinfo>
using namespace std;

bool higherPrec(char a, char b);
string convertPostfix(string e);
int evaluatePostfix(string e);
int eval(char op, stack<int> &s);

// converts an infix expression to postfix
// string e - infix expression to convert to postfix
string convertPostfix(string e)
{
	const char *exp = e.c_str();
	stack <char> ops;
	string result = "";
	for(int i = 0; i < strlen(exp); i++)
	{
		if(isdigit(exp[i])) { result += exp[i]; } // if digit, add to string result
		else // if operator add to stack
		{
			while(!ops.empty() && higherPrec(ops.top(), exp[i]))
			{ // if an operator in stack is higher in precedence, add that operator first
				result += ops.top();
				ops.pop();
			}
			ops.push(exp[i]);
		}
	}
	while(!ops.empty())
	{
		result += ops.top(); // add any remaining operators from stack
		ops.pop();
	}
	return result;
}

// indicates precedence of operators
// char a - first operator to compare
// char b - second operator to compare
bool higherPrec(char a, char b)
{
	if(a=='*' || a=='/')
	{
		if(b=='+' || b=='-')
		{
			return true;
		}
		if(b=='*' || b=='/')
		{
			return true;
		}
	}
	else if(a=='+' || a=='-')
	{
		if(b=='+' || b=='-')
		{
			return true;
		}
		return false;
	}
	
}

// evaluates a postfix expression
// e - expression to evaluate as a string
int evaluatePostfix(string e)
{
	const char *exp = e.c_str();
	stack <int> nums;
	int result;
	for(int i = 0; i < strlen(exp); i++)
	{ // if digit add to stack
		if(isdigit(exp[i])) { nums.push((int)(exp[i]-'0')); }
		else
		{ // if operator, evaluate
			result = eval(exp[i], nums);
		}
 }
	
	return result;
}

// helper method to evaluate postfix expression using stacks
// op - char representing operator
// s - stack of integers (operands) passed by reference
int eval(char op, stack<int> &s)
{	
	int i;
	int b = s.top(); // pop first operand from stack
	s.pop();
	int a = s.top(); // pop second operand
	s.pop();
			
	switch(op) // perform operation based on op argument
    {
    	case '+':
			i = a + b;
			break;
    	case '-':
			i = a - b;
			break;
    	case '*':
			i = a * b;
			break;
    	case '/':
       		i = a / b;
       		break;
    }
    s.push(i); // pushes result to the stack
    return i;
}

int main()
{
	cout << "1. Enter expression.\n2. Quit" << endl;
	int choice;
	cin >> choice;
	
	while(choice == 1)
	{
		string exp;
		cout << "Enter arithmetic expression: ";
		cin >> exp;
		string eval = convertPostfix(exp);
		cout << "Result: " << evaluatePostfix(eval);	
		cout << endl;
		
		cout << "1. Enter expression.\n2. Quit" << endl;
		cin >> choice;	
	}

	return 0;
}

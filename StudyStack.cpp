#include <iostream>
#include <string>
using namespace std;
#define		SIZE	100

class pd_stack {
	char s[SIZE];
	int top;
public:
	pd_stack();
	void push(char x);
	char pop();
};

pd_stack::pd_stack()
{
	top = 0;
}

void pd_stack::push(char x)
{
	s[top] = x;
	top++;
}

char pd_stack::pop()
{
	top--;
	return s[top];
}

bool checkPalindrome(string word)
{
	pd_stack stack;
	string temp1, temp2;
	int len = word.length();
	int t = 0;
	if (len % 2 == 1)	t = 1;
	else				t = 0;

	for (int i = 0; i < (len / 2); i++)
	{
		stack.push(word[i]);
	}
	for (int i = 0; i < (len / 2); i++)
	{
		temp1 += stack.pop();
	}
	for (int i = (len / 2) + t; i < len; i++)
	{
		temp2 += word[i];
	}

	if (temp1 == temp2)
		return true;
	else
		return false;
}

int main()
{
	string input;
	cout << "Enter a word >> ";
	cin >> input;

	if (checkPalindrome(input))
		cout << "yes!" << endl;
	else
		cout << "no!" << endl;
}

/* Assignment 2; infix to postfix Algorithm
#include <iostream>
#include <string>
using namespace std;
#define		SIZE	100
#define		EOS		'$'

class op_stack {
	char s[SIZE];
	int top;
public:
	op_stack();
	void push(char x);
	char pop();
	bool stackEmpty();
	bool stackFull();
	char top_element();
};

op_stack::op_stack()
{
	top = 0;
}

void op_stack::push(char x)
{
	if (stackFull())
	{
		cout << "Error: Stack is full\n";
		return;
	}
	s[top] = x;
	top++;
}

char op_stack::pop()
{
	if (stackEmpty())
	{
		cout << "Error: Stack is empty\n";
		return NULL;
	}
	top--;
	return s[top];
}

bool op_stack::stackEmpty()
{
	if (top == 0)
		return true;
	else
		return false;
}

bool op_stack::stackFull()
{
	if (top >= SIZE)
		return true;
	else
		return false;
}

char op_stack::top_element()
{
	return s[top-1];
}

bool is_operand(char ch)
{
	if ((ch == '(') || (ch == ')') ||
		(ch == '+') || (ch == '-') ||
		(ch == '*') || (ch == '/') ||
		(ch == '%') || (ch == '$'))
		return false;
	else
		return true;
}

int get_precedence(char op)
{
	if (op == '$' || op == '(')
		return 0;
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/' || op == '%')
		return 2;
	return -1;
}

int main()
{
	op_stack stack;
	string input, output;

	cout << "Enter expression: ";
	cin >> input;
	stack.push(EOS);
	
	int i = 0;
	while (i != input.length())
	{
		// case1. open parenthesis
		if (input[i] == '(')	stack.push(input[i]);
		// case2. close parenthesis
		else if (input[i] == ')')
		{
			while (stack.top_element() != '(')
			{
				output += stack.pop();
			}	stack.pop();
		}
		// case3. operators (do not duplicate with open parenthesis)
		else if (!is_operand(input[i]))
		{
			while (get_precedence(stack.top_element()) >= get_precedence(input[i]))
			{
				output += stack.pop();
			}
			stack.push(input[i]);
		}
		// case4. operands
		else if (is_operand(input[i]))
			output += input[i];
		i++;
	}
	
	// except EOS when printing output
	while (!stack.stackEmpty())
	{
		if (stack.top_element() == EOS)
			break;
		output += stack.pop();
	}
	cout << "postfix version is... " << output << endl;
}
*/
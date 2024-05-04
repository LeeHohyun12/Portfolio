#include <iostream>
#include <string>
#define	 SIZE	100
#define  EOS	'$'
using namespace std;

class op_stack {
    char s[SIZE];
    int top;

public:
    op_stack();
    void push(char x);
    char pop();
    bool empty();
    char top_element();
};


op_stack::op_stack() {
    top = 0;
}


void op_stack::push(char x) {
    s[top] = x;
    top++;
}


char op_stack::pop() {
    top--;
    return(s[top]);
}


bool op_stack::empty() {
    return (top == 0);
}


char op_stack::top_element() {
    return (s[top - 1]);
}


bool is_operand(char ch)
{
    if ((ch >= 33) && (ch <= 47))
        return false;
    else
        return true;
}


int get_precedence(char op)
{
    if ((op == '$') || (op == '('))
        return (0);
    if ((op == '+') || (op == '-'))
        return (1);
    if ((op == '*') || (op == '/') || (op == '%'))
        return (2);

    return (-1);
}


int main()
{
    string input, output;
    op_stack stack1;
    cout << "Input an infix expression to convert: ";
    cin >> input;
    stack1.push(EOS);

    for (int i = 0; i < input.size(); i++)
    {
        // operand. directly assign its value to output object
        if (is_operand(input[i]))
        {
            output += input[i];
        }

        // operator. clarify which operator has the highest priority
        else
        {
            if (get_precedence(stack1.top_element())
                < get_precedence(input[i]) || input[i] == '(')
                // input token has higher priority than token of stack1
                // exception. '(' has the lowest priority, but just push it into stack1
            {
                stack1.push(input[i]);
            }

            else if (input[i] == ')')
            {
                while (stack1.top_element() != '(')
                {
                    // pop the element of stack1 until you find '('
                    output += stack1.pop();
                }
                stack1.pop();  // pop the '('
            }

            else if (get_precedence(stack1.top_element())
                >= get_precedence(input[i]))
            {
                while (get_precedence(input[i])
                    <= get_precedence(stack1.top_element()))
                {
                    // pop top token of stack1 until the priority of input token is higher than stack1's token
                    output += stack1.pop();
                }
                // if the input token priority is the highest, push it into the stack1
                stack1.push(input[i]);
            }
        }
    }

    while (!stack1.empty())
    {
        // pop the stack1 until it is empty
        if (stack1.top_element() == EOS)
            break;

        output += stack1.pop();
    }
    cout << output;
}
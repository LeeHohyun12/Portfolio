#include <iostream>
#include <string>
using namespace std;
#define SIZE  100


class pthsis_stack {
private:
    char s[SIZE];
    int top;

public:
    pthsis_stack();
    void push(char x);
    char pop();
    char top_element();
    int size();
};

pthsis_stack::pthsis_stack() {
    top = 0;
}

void pthsis_stack::push(char x) {
    s[top] = x;
    top++;
}

char pthsis_stack::pop() {
    top--;
    return (s[top]);
}

char pthsis_stack::top_element() {
    return (s[top - 1]);
}


int pthsis_stack::size() {
    return top;
}


int main()
{
    string input;
    pthsis_stack stack;
    char cmp_pth;               // value to find what kind of parenthesis has missed
    int cmp_index;              // value to find missed parenthesis index
    int mismatch_error = 0;     // mismatch error not happen; 0, error happen; 1

    char pth[3][2] =
    {
      {'(', ')'},
      {'{', '}'},
      {'[', ']'}
    };

    cout << "Enter polynomial >> ";
    cin >> input;

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '(' || input[i] == '{' || input[i] == '[')
            stack.push(input[i]);

        else if (input[i] == ')' || input[i] == '}' || input[i] == ']')
        {
            cmp_pth = stack.pop();   // open parenthesis


            if (stack.size() <= -1)
            {
                // Error1. parenthesis matched: but too much end parenthesis
                cout << "Error: An extra parenthesis " << "'" << input[i] << "'" << " is found." << endl;
            }

            // matching open parenthesis and end parenthesis
            for (int k = 0; k < 3; k++)
            {
                if (pth[k][1] == input[i])
                    cmp_index = k;
            }


            if (pth[cmp_index][0] != cmp_pth && (stack.size() >= 0))
            {  // Error2. mismatch case: open parenthesis and end parenthesis are not matched
                mismatch_error = 1;

                for (int k = 0; k < 3; k++)
                {
                    if (pth[k][0] == cmp_pth)    cmp_index = k;
                }
                cout << "Error: mis-matched parenthesis, " << "'" << pth[cmp_index][1] << "'" << " is expected." << endl;
            }
        }

    }


    if ((stack.size() == 0) && (mismatch_error == 0))
    {
        // No Error. normal expression, stack is empty
        cout << "It's a normal expression" << endl;
    }

    else if (stack.size() > 0 && (mismatch_error == 0))
    {
        // Error3. too much open parenthesis, stack is not empty
        for (int k = 0; k < 3; k++)
        {
            if (stack.top_element() == pth[k][0])
                cmp_index = k;
        }
        cout << "Error: Cannot find an parenthesis " << "'" << pth[cmp_index][1] << "'" << endl;
    }
}
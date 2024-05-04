#include <iostream>
#include <string>
using namespace std;

class node {
public:
    char pth;
    node* link;
};

class pthsis_stack {
public:
    node* top;
    pthsis_stack();
    void push(node t);
    node pop();
    char top_element();
    int size();
};

pthsis_stack::pthsis_stack() {
    top = NULL;
}

void pthsis_stack::push(node t) {
    node* p;
    p = new node;
    (*p) = t;
    p->link = top;
    top = p;
}

node pthsis_stack::pop() {
    node tmp;
    node* t;
    t = top;
    tmp = (*top);
    top = top->link;
    delete t;
    return tmp;
}

char pthsis_stack::top_element() {
    return (*top).pth;
}

int pthsis_stack::size() {
    int count = 0;
    node* p;
    for (p = top; p != NULL; p = p->link)
        count++;
    return count;
}

int main()
{
    node nd;
    pthsis_stack tmp;
    pthsis_stack stack;

    string input;
    char cmp_pth;
    int cmp_index;
    int mismatch_error = 0;
    char pth[3][2] =
    {
      {'(', ')'},
      {'{', '}'},
      {'[', ']'}
    };

    cout << "Enter polynomial >> ";
    cin >> input;

    for (int i = input.size() - 1; i >= 0; i--)
    {
        nd.pth = input[i];
        tmp.push(nd);
    }

    node *p;
    for (p = tmp.top; p != NULL; p = p->link)
    {
        if (p->pth == '(' || p->pth == '{' || p->pth == '[')
            stack.push(*p);

        else if (p->pth == ')' || p->pth == '}' || p->pth == ']')
        {
            if (stack.top == NULL)
            {
                // Error1. parenthesis matched: but too much end parenthesis
                cout << "Error: An extra parenthesis " << "'" << p->pth << "'" << " is found." << endl;
            }

            cmp_pth = stack.pop().pth;   // open parenthesis

            // matching open parenthesis and end parenthesis
            for (int k = 0; k < 3; k++)
            {
                if (pth[k][1] == p->pth)
                    cmp_index = k;
            }


            if (pth[cmp_index][0] != cmp_pth)
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
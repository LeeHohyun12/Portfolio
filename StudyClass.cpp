#include <iostream>
using namespace std;
#define     SIZE    100

class my_stack {
    int s[SIZE];
    int top;
public:
    my_stack();
    void push(int n);
    int pop();
    bool isEmpty();
    bool isFull();
};

my_stack::my_stack()
{
    s[SIZE-1] = 0;
    top = 0;
}

void my_stack::push(int n)
{
    s[top] = n;
    top++;
}

int my_stack::pop()
{
    top--;
    return s[top];
}

bool my_stack::isEmpty()
{
    return (top == 0);
}

bool my_stack::isFull()
{
    return (top >= SIZE);
}

int main()
{
    my_stack stack;
    int list[5] = { 45, 72, 97, 12, 4 }, i, x;
    for (i = 0; i < 5; i++)
    {
        if (list[i] > 20)
            stack.push(list[i]);
    }
    while (!stack.isEmpty())
    {
        x = stack.pop();
        cout << x << endl;
    }
    return 0;
}

class weight {
    int grams;
    int kilos;
public:
    int get_kilos();
    int get_grams();
    void set_kilos(int k);
    void set_grams(int g);
    int get_weight();
    void set_weight(int k, int g);
};

int weight::get_kilos()
{
    return kilos;
}

int weight::get_grams()
{
    return grams;
}

void weight::set_kilos(int k)
{
    kilos = k;
}

void weight::set_grams(int g)
{
    grams = g;
}

int weight::get_weight()
{
    int sum_weight = kilos * 1000 + grams;
    return sum_weight;
}

void weight::set_weight(int k, int g)
{
    kilos = k;
    grams = g;
}

weight add_weight(weight o1, weight o2)
{
    int sum_kilos = o1.get_kilos() + o2.get_kilos();
    int sum_grams = o1.get_grams() + o2.get_grams();
    weight sum_weight;

    if (sum_grams >= 1000)
    {
        sum_grams -= 1000;
        sum_kilos++;
    }
    sum_weight.set_kilos(sum_kilos);
    sum_weight.set_grams(sum_grams);
    return sum_weight;
}

bool less_than(weight o1, weight o2)
{
    if (o1.get_weight() < o2.get_weight())
        return true;

    else
        return false;
}

/* int main()
{
    weight  w1, w2, w3;  // weight라는 class object 3개 생성
    w1.set_weight(3, 400);  // w1을 3kg 400 g으로
    w2.set_weight(2, 700);  // w2을 2kg 700 g으로
    w3 = add_weight(w1, w2); // w1과 w2을 더하여 w3에 à w3는 6kg 100g
    cout << w3.get_weight() << "grams\n"; // w3의 값 ‘6100 grams’ 출력
    if (less_than(w1, w2)) // w1이 w2보다 작은 값인가 판단
        cout << "yes.\n";
    else
        cout << "no. \n";   // 작지 않으므로 ‘no’ 출력
} */
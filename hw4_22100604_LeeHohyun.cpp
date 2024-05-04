#include <iostream>
#include <string>
using namespace std;
#define YES    1
#define NO     0

bool check(string str, int start, int end)
{
    // Base case: if start index and end index meet and char values are symmetric, it is palindrome
    if (start >= end)            return true;

    // General case: if char of start index and end index are different, it isn't palindrome
    else
    {
        if (str[start] != str[end])
            return false;
    }
    return check(str, start + 1, end - 1);
}

int main()
{
    string input;
    int len;
    cout << "Input a string : ";
    cin >> input;
    len = input.size();
    if (check(input, 0, len - 1) == YES)
        cout << " Yes, it is a palindrome. \n";

    else
        cout << " No, it is not a palindrome. \n";

    return 0;
}
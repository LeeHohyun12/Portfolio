#include <iostream>
#include <string>
using namespace std;

string st;

string reverse(string str)
{
	// Base case: 
	// 'str length 0' means reverse action has done
	if (str.size() == 0)      return st;

	// General case: 
	// assign last index's value in new string and
	// erase the size of original string until the original string size becomes 0
	st += str[str.size() - 1];
	return reverse(str.erase(str.size() - 1, 1));
}

int main()
{
	string  input, r_input;
	cout << "Input a string : ";
	cin >> input;
	r_input = reverse(input);
	cout << r_input << endl;
	return 0;
}
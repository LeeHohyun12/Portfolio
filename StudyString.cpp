#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
	// 알아야하는 string constructor 3가지 형태
	// 1) string st;
	// 2) string st("something");
	// 3) string st(otherObject);

	/*
	char st1[] = "hello", st2[] = "world";
	char st3[20];
	strcpy_s(st3, st1);
	if (strcmp(st1, st2) >= 0)
		strcat_s(st3, st1);
	int n = strlen(st2);

	cout << st1 << ", " << st2 << ", " << st3 << "\n";
	cout << n << endl;
	*/

	string str1("hello"), str2("world");
	string str3;

	str1.insert(2, "apple", 1, 2);
	str1.erase(1, 3);

	str3 = str1;
	if (str1 >= str2)
		str3 += str1;
	int n = str2.size();	// length(); doesn't matter!

	cout << str1 << ", " << str2 << ", " << str3 << "\n";
	cout << n << endl;

	/*
	string test("wow");
	string st(test);
	st = st + "program";
	st = st + 'a';
	// st = 'n' + st;
	cout << st << endl;
	*/
	/*
	char str1[20] = "Test", str2[20] = "Midterm";
	// strcpy_s(str1, str2);
	// strcat_s(str2, str1);
	if (strcmp(str1, str2) >= 0)
		cout << "true" << endl;	// true 출력
	else
		cout << "false" << endl;

	cout << "str1: " << str1 << ", str2: " << str2 << endl;
	cout << "length: " << strlen(str1) << ", " << strlen(str2) << endl;
	*/

	/*
	char str3[20];
	strcpy_s(str3, "JamesPot\0ter");
	cout << str3 << endl; // JamesPot (cout은 null문자까지 출력하니까!)

	string st1, st2;
	st1 += "JamesPot\0ter";
	cout << st1 << endl;	// JamesPot

	cout << (str3 == st1 ? "true" : "false") << endl;	// true
	*/
}
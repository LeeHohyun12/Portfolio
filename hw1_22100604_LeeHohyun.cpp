#include <iostream>
using namespace std;

// Programming Assignment 1. Finish the code of set_weight(), add_weight(), get_weight(), and less_than()

class weight {
public:
	int kiloGrams = 0;
	int grams = 0;
	int set_weight(int kiloGram, int gram);
	int get_weight();
};


weight add_weight(weight object1, weight object2)
{
	// Function. Add the member variables(kiloGrams, grams) in which are located each objects

	int add_kiloGram = object1.kiloGrams + object2.kiloGrams;
	int add_gram = object1.grams + object2.grams;

	if (add_gram >= 1000)
	{
		add_kiloGram++;
		add_gram = add_gram - 1000;
	}	// if the sum is equal or greater than 1000

	weight temp_object;
	temp_object.kiloGrams = add_kiloGram;
	temp_object.grams = add_gram;
	// define temporary object that is made from class weight

	return temp_object;
}

bool less_than(weight object1, weight object2)
{
	// Function. Find which object variable is larger than the other
	
	int n1 = object1.get_weight();
	int n2 = object2.get_weight();
	// use get_weight() function to find which is larger

	if (n1 - n2 < 0)		return true;
	else					return false;
}


int main()
{
	weight w1, w2, w3;
	w1.set_weight(3, 400);		// object w1's variable, kilos and grams have assigned 3 and 400
	w2.set_weight(2, 700);		// object w2's variable, kilos and grams have assigned 2 and 700

	w3 = add_weight(w1, w2);	// return type of add_weight and the type of w3(weight) is same
	cout << w3.get_weight() << "grams\n";

	if (less_than(w1, w2))
		cout << "yes.\n";
	else
		cout << "no.\n";
}


int weight :: set_weight(int kiloGram, int gram)
{
	// Function. Assign the parameters' value to objects' variables
	kiloGrams = kiloGram;
	grams = gram;
	
	return 0;
}

int weight :: get_weight()
{
	// Function. Change the kg value to gram, and add all grams
	int add_result = (kiloGrams * 1000) + (grams);

	return add_result;
}
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream f1("c.dat");
	ofstream f2("d.dat");
	ifstream f3;
	int n, n_count = 0, n_sum = 0;

	while (!f1.eof())
	{
		f1 >> n;
		n_count++;
		n_sum += n;
	}
	double n_avg = (n_sum / n_count);

	f2 << "n_count: " << n_count << endl;
	f2 << "n_sum: " << n_sum << endl;
	f2 << "n_avg: " << n_avg << endl;
	f1.close();
	f2.close();
	return 0;
}
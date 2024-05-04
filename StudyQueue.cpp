#include <iostream>
#include <string>
using namespace std;
#define		Q_SIZE		100

class element {
public:
	string sname;
	string phone_no;
	void set_data(string s1, string s2);
};

void element::set_data(string s1, string s2)
{
	sname = s1;
	phone_no = s2;
}

class my_queue {
	element q[Q_SIZE];
	int front, rear;
public:
	my_queue();
	void insert_q(element x);
	element delete_q();
	bool queue_empty();
	bool queue_full();
};

my_queue::my_queue()
{
	front = 0;
	rear = 0;
}

void my_queue::insert_q(element x)
{
	if (!queue_full())
	{
		q[rear] = x;
		rear = (rear + 1) % Q_SIZE;
	}
	else	cout << "Error: queue is already full\n";
}

element my_queue::delete_q()
{
	if (!queue_empty())
	{
		element tmp = q[front];
		front = (front + 1) % Q_SIZE;
		return tmp;
	}
	else	cout << "Error: queue is empty\n";
}

bool my_queue::queue_empty()
{
	if (front == rear)
		return true;
	else
		return false;
}

bool my_queue::queue_full()
{
	if ((rear + 1) % Q_SIZE == front)
		return true;
	else
		return false;
}

int main()
{
	my_queue queue;

	element e;

	e.set_data("Kim", "010-4544-2525");
	queue.insert_q(e);

	e.set_data("Lee", "010-3244-2325");
	queue.insert_q(e);

	e.set_data("Park", "010-9534-0942");
	queue.insert_q(e);

	while (!queue.queue_empty())
	{
		e = queue.delete_q();
		cout << e.sname << " : " << e.phone_no << endl;
	}
	return 0;
}
#include <iostream>
using namespace std;
#define MAX_SIZE	100

class node {
public:
	string name;
	double score;
	node* left, * right;
	void set_data(string s, double n);
};

class my_queue {
	node* q[MAX_SIZE];
	int front, rear;
public:
	my_queue();
	void insert_q(node* p);
	node* delete_q();
	bool q_empty();
	bool q_full();
};

my_queue::my_queue()
{
	front = 0;
	rear = 0;
}

void my_queue::insert_q(node* p)
{
	if (q_full())	cout << "Error: queue is full!" << endl;
	else
	{
		q[rear] = p;
		rear = (rear + 1) % MAX_SIZE;
	}
}

node* my_queue::delete_q()
{
	if (q_empty())	cout << "Error: queue is Empty!" << endl;
	else
	{
		node* tmp = q[front];
		front = (front + 1) % MAX_SIZE;
		return tmp;
	}
}

bool my_queue::q_empty()
{
	return front == rear;
}

bool my_queue::q_full()
{
	return (rear + 1) % MAX_SIZE == front;
}

void node::set_data(string s, double n)
{
	name = s;
	score = n;
}

class my_tree {
public:
	int node_count;
	node* root;
	my_tree();
	int insert_root(node t);
	int insert_left(string tname, node t);
	int insert_right(string tname, node t);

	void print_inorder();
	void print_preorder();
	void print_postorder();
	void print_data_levelorder();
	
	node* findTargetNode(string tname);
};

my_tree::my_tree()
{
	node_count = 0;
	root = NULL;
}

int my_tree::insert_root(node t)
{
	if (root != NULL)	return 0;
	node* p = new node;
	(*p) = t;
	p->left = NULL;
	p->right = NULL;
	root = p;
	node_count++;
	return 1;
}

int findNameInNode_left(node *p, string fname, node t)
{
	if (p == NULL)		return 0;

	if (fname != p->name)
	{
		int result;
		result = findNameInNode_left(p->left, fname, t);
		if (result != 0)
			return result;
		return findNameInNode_left(p->right, fname, t);
	}
	else
	{
		if (p->left != NULL)	return -1;
		node* tmp = new node;
		(*tmp) = t;
		tmp->left = NULL;
		tmp->right = NULL;
		p->left = tmp;
		return 1;
	}
}

int my_tree::insert_left(string tname, node t)
{
	int result = findNameInNode_left(root, tname, t);
	if (result == 1)
		node_count++;
	return 1;
}

int findNameInNode_right(node* p, string fname, node t)
{
	if (p == NULL)		return 0;

	if (fname != p->name)
	{
		int result;
		result = findNameInNode_right(p->left, fname, t);
		if (result != 0)
			return result;
		return findNameInNode_right(p->right, fname, t);
	}
	else
	{
		if (p->right != NULL)	return -1;
		node* tmp = new node;
		(*tmp) = t;
		tmp->left = NULL;
		tmp->right = NULL;
		p->right = tmp;
		return 1;
	}
}

int my_tree::insert_right(string tname, node t)
{
	int result = findNameInNode_right(root, tname, t);
	if (result == 1)
		node_count++;
	return 1;
}

void node_inorder(node *p)
{
	if (p == NULL)		return;

	node_inorder(p->left);
	cout << "Name: " << p->name << ", " << p->score << endl;
	node_inorder(p->right);
}

void my_tree::print_inorder()
{
	cout << "Inorder Print Result\n";
	node_inorder(root);
}

void node_preorder(node* p)
{
	if (p == NULL)		return;

	cout << "Name: " << p->name << ", " << p->score << endl;
	node_preorder(p->left);
	node_preorder(p->right);
}

void my_tree::print_preorder()
{
	cout << "Preorder Print Result\n";
	node_preorder(root);
}

void my_tree::print_data_levelorder()
{
	my_queue a1;
	node* t;

	if (root == NULL)
		return;
	a1.insert_q(root);
	while (1)
	{
		if (a1.q_empty())
			return;
		t = a1.delete_q();
		cout << t->name << " : " << t->score << endl;
		if (t->left != NULL)
			a1.insert_q(t->left);
		if (t->right != NULL)
			a1.insert_q(t->right);
	}
}

node* adrTarget(string fname, node* p, node* target)
{
	if (p == NULL)		return target;
	if (p->name == fname)
	{
		return p;
	}
	else
	{
		target = adrTarget(fname, p->left, target);
		target = adrTarget(fname, p->right, target);
		return target;
	}
}

node* my_tree::findTargetNode(string tname)
{
	return adrTarget(tname, root, root);
}

int main()
{
	my_tree thetree;
	node tmp;

	tmp.set_data("Kim", 8.2);
	thetree.insert_root(tmp);
	tmp.set_data("Lee", 6.7);
	thetree.insert_left("Kim", tmp);
	tmp.set_data("Wow", 9.5);
	thetree.insert_right("Kim", tmp);
	tmp.set_data("Choi", 3.2);
	thetree.insert_left("Wow", tmp);
	tmp.set_data("Ruy", 4.5);
	thetree.insert_right("Wow", tmp);

	thetree.print_data_levelorder();
	cout << "Target is... " << thetree.findTargetNode("Wow")->score << endl;
	// cout << "The number of nodes are... " << thetree.node_count << endl;
	// thetree.print_inorder();
	// thetree.print_preorder();
}
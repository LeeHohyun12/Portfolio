#include <iostream>
using namespace std;


class  node { 
public:
	string  name; 
	double  score; 
	node* left, * right; 
	void set_data(string s, double n); 
}; 

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

	double score_sum();
	double score_average();
	void print_data_inorder();
	void print_data_preorder();
	void print_data_postorder();
};

my_tree::my_tree()
{
	node_count = 0;
	root = NULL;
}

int my_tree::insert_root(node t)
{
	if (root != NULL)
		return 0;
	node* p;
	p = new node;
	(*p) = t;
	p->left = NULL;
	p->right = NULL;
	root = p;
	node_count++;
	return 1;
}

node* inorder_traverse(node* p, string name)
{
	if (p == NULL)	return NULL;

	inorder_traverse(p->left, name);
	if (name == p->name)
	{
		return p;
	}
	inorder_traverse(p->right, name);
}

int my_tree::insert_left(string tname, node t)
{
	if (inorder_traverse(root, tname) == NULL)
		return 0;
	else
	{
		node* tmp = inorder_traverse(root, tname);
		// cout << inorder_traverse(root, tname)->name << endl;
		node* p = new node;
		(*p) = t;
		cout << "found content is ... " << tmp->name << " : " << tmp->score << endl;
		cout << "node content is ... " << p->name << " : " << p->score << endl;
		tmp->left = p;
		p->left = NULL;
		p->right = NULL;
		node_count++;
		return 1;
	}
}

int my_tree::insert_right(string tname, node t)
{
	if (tname != inorder_traverse(root, tname)->name)
		return 0;
	else
	{
		node* tmp = inorder_traverse(root, tname);
		node* p = new node;
		(*p) = t;
		tmp->right = p;
		p->left = NULL;
		p->right = NULL;
		node_count++;
	}
}

node* getAddress(node* p)
{
	return p;
}

node* p;

void my_tree::print_data_inorder()
{
	if (p == NULL)	return;
	node* tmp = getAddress(p);
	p = p->left;
	print_data_inorder();
	cout << tmp->name << " : " << tmp->score << endl;
	node* tmp2 = getAddress(tmp);
	p = tmp->right;
	print_data_inorder();
}


int main()
{
	my_tree thetree;
	node tmp;

	tmp.set_data("Kim", 8.1);
	thetree.insert_root(tmp);
	p = thetree.root;
	tmp.set_data("Lee", 6.5);
	thetree.insert_left("Kim", tmp);
	
	tmp.set_data("Park", 8.3);
	thetree.insert_right("Kim", tmp);
	tmp.set_data("Choi", 7.2);
	thetree.insert_left("Lee", tmp);
	//tmp.set_data("Ryu", 9.0);
	//thetree.insert_right("Lee", tmp);
	//tmp.set_data("Cho", 7.7);
	//thetree.insert_right("Park", tmp);
	thetree.print_data_inorder();
	return 0;
}


/*
class node {
public:
	string name;
	double score;
	node *left, *right;
	void set_data(string s, double n);
};

void node::set_data(string s, double n)
{
	name = s;
	score = n;
}

class my_tree {
public:
	int node_count;
	node *root;

	node* get_root()
	{
		return root;
	}

	my_tree();
	int insert_root(node t);
	int insert_left(string tname, node t);
	int insert_right(string tname, node t);
	
	double score_sum();
	double score_average();
	void print_data_inorder(node *p);
};

my_tree::my_tree()
{
	node_count = 0;
	root = NULL;
}

int my_tree::insert_root(node t)
{
	if (root != NULL)
		return 0;
	node *p;
	p = new node;
	(*p) = t;
	p->left = NULL;
	p->right = NULL;
	root = p;
	node_count++;
	return 1;
}

node* inorder_traverse(node* p, string name)
{
	if (p == NULL)	return NULL;
	if (name == p->name)	return p;

	inorder_traverse(p->left, name);
	inorder_traverse(p->right, name);
}

int my_tree::insert_left(string tname, node t) 
{
	if (tname != inorder_traverse(root, tname)->name)
		return 0;
	else
	{
		node* tmp = inorder_traverse(root, tname);
		node* p = new node;
		(*p) = t;
		tmp->left = p;
		p->left = NULL;
		p->right = NULL;
		node_count++;
	}
}

int my_tree::insert_right(string tname, node t)
{
	if (tname != inorder_traverse(root, tname)->name)
		return 0;
	else
	{
		node* tmp = inorder_traverse(root, tname);
		node* p = new node;
		(*p) = t;
		tmp->right = p;
		p->left = NULL;
		p->right = NULL;
		node_count++;
	}
}


void my_tree::print_data_inorder(node *p)
{
	// Left > Root > Right
	if (p == NULL)	return;

	print_data_inorder(p->left);
	cout << p->name << " : " << p->score << endl;
	print_data_inorder(p->right);
}

int main()
{
	my_tree thetree;
	node tmp;

	tmp.set_data("Kim", 8.1);
	thetree.insert_root(tmp);
	tmp.set_data("Lee", 6.5);
	thetree.insert_left("Kim", tmp);
	tmp.set_data("Park", 8.3);
	thetree.insert_right("Kim", tmp);
	//tmp.set_data("Choi", 7.2);
	//thetree.insert_left("Lee", tmp);
	//tmp.set_data("Ryu", 9.0);
	//thetree.insert_right("Lee", tmp);
	//tmp.set_data("Cho", 7.7);
	//thetree.insert_right("Park", tmp);
	//thetree.print_data_inorder(thetree.get_root());
}
*/
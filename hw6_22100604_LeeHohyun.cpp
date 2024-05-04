#include <iostream>
using namespace std;

class node {
public:
    string name;
    double score;
    node* link;
    void  set_data(string s, double n);
};

void node::set_data(string s, double n)
{
    name = s;
    score = n;
}

class my_list {
    node* head, * tail;
public:
    my_list();
    void  add_to_head(node t);
    void  add_to_tail(node t);
    node  delete_from_head();
    int   num_nodes();
    double score_sum();
    double get_score(string t_name);
    int remove_a_node(string t_name);
};

my_list::my_list()
{
    head = NULL;
    tail = NULL;
}

void my_list::add_to_head(node t)
{
    node* p;
    p = new node;
    (*p) = t;
    p->link = head;
    head = p;
    if (tail == NULL)
        tail = p;
}

void my_list::add_to_tail(node t)
{
    node* p;
    p = new node;
    (*p) = t;
    p->link = NULL;
    if (tail != NULL)
        tail->link = p;
    else
        head = p;
    tail = p;
}

node my_list::delete_from_head()
{
    node  temp;
    node* t; 
    t = head;
    temp = *head;
    head = head->link;
    delete t;
    if (head == NULL)
        tail = NULL;
    return temp;
}

int my_list::num_nodes()
{
    node* t;
    int count = 0;
    for (t = head; t != NULL; t = t->link)
        count++;
    return count;
}

double my_list::score_sum()
{
    // Function. add all score variables in which node class
    double sum = 0;
    node* p;
    for (p = head; p != NULL; p = p->link)
        sum += (p->score);
    return sum;
}

double my_list::get_score(string t_name)
{
    // Function. find and return score variable corresponding to t_name
    node* p;
    // Case 1. corresponding variable exists 
    for (p = head; p != NULL; p = p->link)
    {
        if ((p->name) == t_name)
            return (p->score);
    }
    // Case 2. no corresponding variable
    cout << "Cannot find target... it will be considered as ";
    return 0;
}

int my_list::remove_a_node(string t_name)
{
    // Function. remove the node that including t_name
    node* p;
    for (p = head; p != NULL; p = p->link)
    {
        if ((p->name) == t_name)
        {
            delete_from_head();
            return 1;
        }  // Exception case1. front part matches with t_name

        if ((p->link) == NULL)    break;
            // Exception case2. to prevent garbage value
            // (p->link->name) will get garbage value when p->link points NULL

        if ((p->link->name) == t_name)
        {
            (p->link) = (p->link->link);
            return 1;
        }  // General case. node variable, name, matches with t_name
    }
    cout << "Target node doesn't exist..." << endl;
    return 0;
}

int main()
{
    my_list a;
    node  tmp;
    tmp.set_data("Kim", 83.5);
    a.add_to_head(tmp);
    tmp.set_data("Lee", 78.2);
    a.add_to_head(tmp);
    cout << a.num_nodes() << " : " << a.score_sum() << "\n";
    tmp.set_data("Park", 91.3);
    a.add_to_tail(tmp);
    cout << a.num_nodes() << " : " << a.score_sum() << "\n";
    tmp = a.delete_from_head();
    cout << tmp.name << " is deleted.\n";
    tmp.set_data("Choi", 85.1);
    a.add_to_tail(tmp);
    tmp.set_data("Ryu", 94.3);
    a.add_to_head(tmp);
    cout << a.num_nodes() << " : " << a.score_sum() << "\n";
    cout << "Park's score : " << a.get_score("Park") << "\n";
    if (a.remove_a_node("Kim") == 1)
        cout << "Kim is deleted from the list. \n";
    cout << a.num_nodes() << " : " << a.score_sum() << "\n";
    return 0;
}
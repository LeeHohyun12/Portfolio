#include <iostream>
#include <string>
using namespace std;

class node {
public:
    string name;
    double score;
    node* link;
    void set_data(string s, double n);
};

void node::set_data(string s, double n)
{
    name = s;
    score = n;
}

class my_stack {
    node* top;
public:
    my_stack();
    void stack_push(node t);
    node stack_pop();
    bool stack_empty();
};

my_stack::my_stack()
{
    top = NULL;
}

void my_stack::stack_push(node t)
{
    node* p = new node;
    (*p) = t;
    p->link = top;
    top = p;
}

bool my_stack::stack_empty()
{
    if (top == NULL)
        return true;
    else
        return false;
}

node my_stack::stack_pop()
{
    if (top == NULL)
    {
        cout << "queue is empty..." << endl;
        node tmp;
        tmp.name = "NO NAME";
        tmp.score = 0;
        return tmp;
    }
    node tmp;
    node* t;
    t = top;
    tmp = *top;
    top = top->link;
    delete t;
    return tmp;
}

class my_queue {
    node *front, *rear;
public:
    my_queue();
    void insert_q(node t);
    node delete_q();
    bool queue_empty();
};

my_queue::my_queue()
{
    front = NULL;
    rear = NULL;
}

void my_queue::insert_q(node t)
{
    // q[rear] = x;
    // rear = (rear + 1) % Q_SIZE;
    node* p = new node;
    (*p) = t;
    p->link = NULL;
    if (rear != NULL)
        rear->link = p;
    else
        front = p;
    rear = p;
}

node my_queue::delete_q()
{
    // int temp = front;
    // front = (front + 1) % Q_SIZE;
    // return q[front]
    if (front == NULL)
    {
        cout << "queue is empty..." << endl;
        node tmp;
        tmp.name = "NO NAME";
        tmp.score = 0;
        return tmp;
    }
    node tmp;
    node *t;
    tmp = *front;
    t = front;
    front = front->link;
    delete t;
    return tmp;
}

bool my_queue::queue_empty()
{
    if (front == NULL)
        return true;
    else
        return false;
}

class my_list {
    node *head, *tail;
public:
    my_list();
    void add_to_head(node t);
    void add_to_tail(node t);
    node delete_from_head();
    int num_nodes();
    bool list_empty();

    void show_all_data();
    void delete_low_score(double score);
    void insert_node(node t);

    void invert();
    friend bool list_equal(my_list a, my_list b);
};

my_list::my_list()
{
    head = NULL;
    tail = NULL;
}

void my_list::add_to_head(node t)
{
    node *p = new node;
    (*p) = t;
    p->link = head;
    if (tail == NULL)
        tail = p;
    head = p;
}

void my_list::add_to_tail(node t)
{
    node *p = new node;
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
    node temp;
    node *t;
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
    node *p;
    int count = 0;
    for (p = head; p != NULL; p = p->link)
        count++;
    return count;
}

bool my_list::list_empty()
{
    if (head == NULL)
        return true;
    else
        return false;
}

void my_list::show_all_data()
{
    node* p;
    for (p = head; p != NULL; p = p->link)
        cout << "Name: " << p->name << ", Score: " << p->score << endl;
}

void my_list::delete_low_score(double score)
{
    node* p = head;
    while (1)
    {
        if (p == NULL)      break;
        while (p->score < score)
        {
            node* t = head->link;
            delete head;
            head = t;
            p = t;
        }
        if (p->link == NULL)      break;
        while (p->link->score < score)
        {
            node* tmp = p->link;
            p->link = p->link->link;
            delete tmp;
        }
        p = p->link;
    }
}

void my_list::insert_node(node t)
{
    node* p = new node;
    (*p) = t;
    if (head == NULL)
    {
        p->link = NULL;
        head = p;
        return;
    }
    if (p->score < head->score)
    {
        p->link = head;
        head = p;
        return;
    }
  
    node* tmp = head;
    while (1)
    {
        if (tmp->link == NULL)
        {
            if (tmp->score < p->score)
            {
                node* tmp1 = new node;
                *tmp1 = *p;
                tmp1->link = NULL;
                tmp->link = tmp1;
            }
            break;
        }

        if ((tmp->link != NULL)
            && (tmp->link->score < p->score))
        {
            tmp = tmp->link;
            continue;
        }
        
        if (p->score < tmp->link->score)
        {
            node* temp1 = new node;
            *temp1 = (*p);
            temp1->link = tmp->link;
            tmp->link = temp1;
            return;
        }
    }
}

void my_list::invert()
{
    node* oldhead = head;
    node* newhead = NULL;
    node* tmp;

    while (oldhead != NULL)
    {
        tmp = newhead;
        newhead = oldhead;
        oldhead = oldhead->link;
        newhead->link = tmp;
    }

    tail = head;
    head = newhead;
}

bool isEqual(node* p1, node* p2)
{
    if (p1 == NULL && p2 == NULL)
        return true;
    if (p1 == NULL || p2 == NULL)
        return false;
    if ()
}

bool list_equal(my_list a, my_list b)
{
    return isEqual(a.head, b.head);
}

int main()
{
    my_list a, b;
    node tmp;

    tmp.set_data("Kim", 83.5);
    a.add_to_head(tmp);
    tmp.set_data("Lee", 58.2);
    a.add_to_head(tmp);
    tmp.set_data("Park", 91.3);
    a.add_to_head(tmp);
    tmp.set_data("Choi", 55.1);
    a.add_to_head(tmp);

    tmp.set_data("Kim", 83.5);
    b.add_to_head(tmp);
    tmp.set_data("Lee", 58.2);
    b.add_to_head(tmp);
    tmp.set_data("Park", 91.3);
    b.add_to_head(tmp);
    tmp.set_data("Choi", 55.1);
    b.add_to_head(tmp);

    a.show_all_data();
    a.invert();
    a.show_all_data();

    return 0;

    /*
    my_queue a;
    node tmp;

    tmp.set_data("KIM", 22.2);
    a.insert_q(tmp);
    tmp.set_data("LEE", 33.3);
    a.insert_q(tmp);
    tmp.set_data("PARK", 44.4);
    a.insert_q(tmp);
    tmp.set_data("CHOI", 55.5);
    a.insert_q(tmp);

    tmp = a.delete_q();
    cout << tmp.name << " : " << tmp.score << endl;
    tmp = a.delete_q();
    cout << tmp.name << " : " << tmp.score << endl;
    tmp = a.delete_q();
    cout << tmp.name << " : " << tmp.score << endl;
    tmp = a.delete_q();
    cout << tmp.name << " : " << tmp.score << endl;
    tmp = a.delete_q();
    cout << tmp.name << " : " << tmp.score << endl;

    return 0;
    */

    /*
    my_stack a;
    node tmp;

    tmp.set_data("KIM", 22.2);
    a.stack_push(tmp);
    tmp.set_data("LEE", 33.3);
    a.stack_push(tmp);
    tmp.set_data("PARK", 44.4);
    a.stack_push(tmp);
    tmp.set_data("CHOI", 55.5);
    a.stack_push(tmp);

    tmp = a.stack_pop();
    cout << tmp.name << " : " << tmp.score << endl;
    tmp = a.stack_pop();
    cout << tmp.name << " : " << tmp.score << endl;
    tmp = a.stack_pop();
    cout << tmp.name << " : " << tmp.score << endl;
    tmp = a.stack_pop();
    cout << tmp.name << " : " << tmp.score << endl;
    tmp = a.stack_pop();
    cout << tmp.name << " : " << tmp.score << endl;

    return 0;
    */
}

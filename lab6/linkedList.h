#include <iostream>
using namespace std;

struct node
{
    int value;
    node *next;
    node *prev;

    node(int x = 0)
    {
        next = NULL;
        prev = NULL;
        value = x;
    }
};
class linkedList
{

    node *head;

public:
    linkedList()
    {
        head = NULL;
    }

    node *getHead() { return this->head; }

    void insertNode(int x)
    {
        node *_node = new node(x);
        if (head == NULL)
        {
            head = _node;
        }
        else
        {
            _node->next = head;
            head->prev=_node;
            head = _node;
        }
    }
    void display()
    {
        node *temp = head;
        while (temp)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
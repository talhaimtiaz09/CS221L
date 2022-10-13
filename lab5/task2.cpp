#include <iostream>
using namespace std;

class queue
{
    struct node
    {
        node *next;
        int val;

        node(int _val = 0)
        {
            next = NULL;
            val = _val;
        }
    };
    node *head;
    int counter;

    node *tail;

public:
    queue()
    {
        head = tail = NULL;
        counter = 0;
    }
    void enqueue(int data)
    {

        node *_node = new node;
        _node->val = data;
        if (!tail)
            head = tail = _node;

        tail->next = _node;
        tail = tail->next;
        counter++;
    }
    void dequeue()
    {
        node *_node;
        _node = head;
        head = head->next;
        delete _node;
    }
    void print()
    {
        node *temp = head;
        while (temp)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
    }
    void interLeave()
    {
        node *prev = head;
        node *mid = head;
        for (int i = 1; i < counter / 2; i++)
        {
            mid = mid->next;
        }

        node *prev2;
        node *mid2;
        node *mid3;
        prev2 = prev->next;
        mid2 = mid->next;
        mid3 = mid2->next;

        for (int i = 0; i < counter / 2 - 1; i++)
        {

            prev->next = mid2;
            mid2->next = prev2;
            mid->next = mid3;
            mid2 = mid3;
            prev = prev2;
            prev2 = prev2->next;
            mid3 = mid3->next;
        }
    }
};

int main()
{
    queue q;
    for (int i = 0; i < 8; i++)
        q.enqueue(i + 1);

    system("cls");
    q.print();
    q.interLeave();
    cout << "\nAfter InterLeaving" << endl;
    q.print();
    return 0;
}
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

    node *tail;

public:
    queue()
    {
        head = tail = NULL;
    }
    void enqueue(int data)
    {

        node *_node = new node;
        _node->val = data;
        if (!tail)
            head = tail = _node;

        tail->next = _node;
        tail = tail->next;
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
    void reverseK(int k)
    {
        node *prev = head;
        node *temp = head->next;

        for (int i = 1; i < k; i++)
        {
            node *tempNext;
            tempNext = temp->next;

            temp->next = prev;
            prev = temp;
            temp = tempNext;
        }

        head->next = temp;
        head = prev;
    }
};

int main()
{
    queue q;
    for (int i = 0; i < 10; i++)
        q.enqueue(i + 1);
    system("cls");
    q.print();
    q.reverseK(3);
    cout << "\nAfter Reversing" << endl;
    q.print();
    return 0;
}
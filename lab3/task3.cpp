#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
class linkedList
{
private:
    node *head;
    node *tail;

public:
    linkedList()
    {
        this->tail=new node();
        this->tail->next = NULL;
        this->head = NULL;
    }
    void addNode(node *n)
    {
        n->next = head;
        head = n;
        
    }
    void makeCycle()
    {
        if (this->tail->next == NULL)
            this->tail->next = this->head;
        else
            cout << "It is already a cycle\n";
    }

    void print()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
    void detectCycle()
    {
        if (this->tail->next == NULL)
        {
            cout << "It is not a cycle" << endl;
        }
        else
        {
            cout << "It is a cycle\n";
        }
    }
    void removeCycle()
    {
        this->tail->next = NULL;
    }
};
int main()
{
    linkedList List;


    for (int i = 0; i < 6; i++)
    {
        node *temp = new node();
        temp->data = 6 - i;
        List.addNode(temp);
    }


    List.makeCycle();
    List.detectCycle();
    List.print();

    return 0;
}
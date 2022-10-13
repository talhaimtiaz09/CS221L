#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
class linkedList{
    private:
    node * head;

    public:
    linkedList(){
        this->head=NULL;
    }
    void addNode(node * n){
        n->next=head;
        head=n;
    }
    void print(){
        node * temp=head;
        while(temp!=NULL){
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
    void reverseNode(){
        node *temp1= head;
        while(temp1!=NULL){
            int tData=temp1->data;
            temp1->data=temp1->next->data;
            temp1->next->data=tData;
            temp1=temp1->next->next;

        }


    }
};
int main()
{
    linkedList L;
    for(int i=0;i<6;i++){
        node * temp=new node();
        temp->data=6-i;
        L.addNode(temp);
    }

    cout<<"\nBefore\n--------------\n";
    L.print();
    L.reverseNode();
    cout<<"\nAfter\n--------------\n";
    L.print();
 return 0;
}
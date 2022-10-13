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
        node *prev;
        node *temp2= temp1->next;

        int i=0;
        while(temp1!=NULL && temp2!=NULL){

            this->print();
            if(i!=0){
                prev->next=temp2;
            }
            if(temp2->next==NULL){
                cout<<"chekc";
                temp1->next=NULL;
                temp2->next=temp1;
            }
            else{

            temp1->next=temp2->next;
            temp2->next=temp1;
            }
            if(i==0){
                head=temp2;
            }
            i++;
            prev=temp1;
            temp1=temp1->next;
            temp2=temp1->next;
            cout<<"i: "<<i<<endl;
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

    L.print();
    L.reverseNode();
    cout<<"\n--------------\n";
    L.print();
 return 0;
}
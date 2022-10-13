#include<iostream>
using namespace std;
struct person{
    string name;
    int age;
    float salary;
    // default constructor 
    person(){
        this->name="";
        this->age=0;
        this->salary=0;
    }
    // contructor with args 
    person(string _name,int _age,float _salary){
        this->name=_name;
        this->age=_age;
        this->salary=_salary;
    }
    void print(){
        cout<<"Name:   "<<this->name<<endl;
        cout<<"Age :   "<<this->age<<endl;
        cout<<"Salary: "<<this->salary<<endl;
    }
};


int main()
{
person p("talha",19,1999.657);
p.print();

    return 0;
}
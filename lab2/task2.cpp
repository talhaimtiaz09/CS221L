#include <iostream>
#include <string>
using namespace std;
struct student
{
    int roll;
    string name;
    string address;
    int age;
    
    // default constructor 
    student()
    {
        this->address = "";
        this->name = "";
        this->roll = 0;
        this->age = 0;
    }
    // constructor with args
    student(string _name, string _address, int _roll, int _age)
    {
        this->address = _address;
        this->name = _name;
        this->roll = _roll;
        this->age = _age;
    }

    void input()
    {
        cout << "Please enter the name: ";
        getline(cin, this->name);
        cout << "Please enter roll no. :";
        cin >> this->roll;
        do
        {
            cout << "Please enter age between 11 to 14: ";
            cin >> this->age;
        } while (this->age < 11 || this->age > 14);
        cin.ignore();
        cout << "Please enter address: ";
        getline(cin, this->address);
    }
    void print()
    {
        cout << "\n------------------------------------\n";
        cout << "Name: " << this->name << endl;
        cout << "Roll: " << this->roll << endl;
        cout << "age: " << this->age << endl;
        cout << "address: " << this->address << endl;
        cout << "\n------------------------------------\n";
    }
};

void printAge14(student std[], int sz)
{
    for (int i = 0; i < sz; i++)
    {
        if (std[i].age == 14)
            cout <<"Name of student with age 14: " <<std[i].name << endl;
    }
}

void printEvenRoll(student std[], int sz)
{
    for (int i = 0; i < sz; i++)
    {
        if (std[i].roll % 2 == 0)
            cout <<"Name of student with even roll: "<< std[i].name << endl;
    }
}

void printByInput(student std[], int sz)
{ 
    int _roll;
    cout<<"Please enter the roll you want to search: ";
    cin>>_roll;
    for (int i = 0; i < sz; i++)
    {
        if (std[i].roll == _roll)
        {
            std[i].print();
            return;
        }
    }
    cout << "No student with " << _roll << " no. is registered" << endl;
}



int main()
{
    const int SZ=3;
    student arr[SZ];
    for(int i=0;i<SZ;i++){
        cout<<"\n----------------------------\n";
        arr[i].input();
        cout<<"\n----------------------------\n";
    }

    printAge14(arr,SZ);
    printEvenRoll(arr,SZ);
    printByInput(arr,SZ);

    return 0;
}
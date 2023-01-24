#include <iostream>
using namespace std;
struct dat
{
    int val;
    int freq;
    // bool to keep check of if insertion is done before or not
    bool inserted;
    // constructor
    dat(int _val = 0, int _freq = 0)
    {
        val = _val;
        freq = _freq;
        inserted = false;
    }
};

class hashing
{

private:
    dat *hashTable;
    int size;

public:
    // constructor
    hashing()
    {
        hashTable = NULL;
        size = 0;
    }
    void createHashTable(int _size)
    {
        // creating an arr for hashtable
        this->size = _size;
        hashTable = new dat[_size];
    }

    void insert(int _val)
    {
        // open addressing insertion (linear probing)
        int i = 0;
        // keep iterating unless any empty slot found
        while (hashTable[hash(i + _val)].inserted)
        {
            if (hashTable[hash(i + _val)].val == _val)
            {
                // increase frequency count for duplicated
                hashTable[hash(i + _val)].freq++;
                return;
            }
            i++;
        }
        // inserting in empty slot
        hashTable[hash(i + _val)].val = _val;
        hashTable[hash(i + _val)].inserted = true;
        hashTable[hash(i + _val)].freq++;
    }

    int hash(int x)
    {
        // hash function
        return x % size;
    }

    void print()
    {
        // print function to view hastable data
        cout << "Val\tfreq\tinserted\n";
        for (int i = 0; i < size; i++)
            cout << hashTable[i].val << "\t" << hashTable[i].freq << "\t" << hashTable[i].inserted << endl;
    }
    bool alreadIn(int _val)
    {
        // checking _val is already present in hashtable or not
        int i = 0;
        while (hashTable[hash(i + _val)].inserted && i < size)
        {
            if (hashTable[hash(i + _val)].val == _val)
            {
                return true;
            }
            i++;
        }
        return false;
    }
};
void takeUserInput(int *&arr1, int *&arr2, int &sz1, int &sz2)
{

    // funciton to take arr inputs from user
    cout << "Please enter the size of Arr1: ";
    cin >> sz1;
    arr1 = new int[sz1];
    for (int i = 0; i < sz1; i++)
    {
        cout << "Please enter the " << i + 1 << " element of Arr1: ";
        cin >> arr1[i];
    }

    cout << "Please enter the size of Arr2: ";
    cin >> sz2;
    arr2 = new int[sz2];
    for (int i = 0; i < sz2; i++)
    {
        cout << "Please enter the " << i + 1 << " element of Arr2: ";
        cin >> arr2[i];
    }
}
int main()
{

    int *arr1, *arr2;
    int sz1, sz2;
    takeUserInput(arr1, arr2, sz1, sz2);
    bool subset = true;

    hashing table;
    table.createHashTable(sz1);
    // insertion
    for (int i = 0; i < sz1; i++)
        table.insert(arr1[i]);
    // checking for subset
    for (int i = 0; i < sz2; i++)
    {

        if (!table.alreadIn(arr2[i]))
        {
            // if any new value found then its not a subset
            subset = false;
        }
    }

    if (subset)
        cout << "Arr2 is subset of Arr1\n";
    else
        cout << "Arr2 is not subset of Arr1\n";

    return 0;
}
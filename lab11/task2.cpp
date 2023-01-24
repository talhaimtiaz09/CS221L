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
        // creating a dynamic array for hashtable
        this->size = _size;
        hashTable = new dat[_size];
    }

    void insert(int _val)
    {
        // open addressing insertion (linear probing)
        int i = 0;
        // iterate unless empty slot found
        while (hashTable[hash(i + _val)].inserted)
        {
            if (hashTable[hash(i + _val)].val == _val)
            {
                // if duplicates found then increment its frequency
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
        // k mod size hash function
        return x % size;
    }

    void print()
    {
        // function to view all the contents of hastable
        cout << "Val\tfreq\tinserted\n";
        for (int i = 0; i < size; i++)
            cout << hashTable[i].val << "\t" << hashTable[i].freq << "\t" << hashTable[i].inserted << endl;
    }
    int getHighestFreq()
    {
        // function to extract the maximum frequency by iterating over whole table
        int max = -1;
        for (int i = 0; i < size; i++)
            if (hashTable[i].freq > max)
                max = hashTable[i].freq;

        return max;
    }
};
int main()
{
    int sz = 0;
    int *arr;
    cout << "Please enter the total number of enteries you want to insert:\n";
    cin >> sz;

    hashing table;
    arr = new int[sz];
    table.createHashTable(sz);

    for (int i = 0; i < sz; i++)
    {
        cout << "Please enter " << i + 1 << " element :";
        cin >> arr[i];
        table.insert(arr[i]);
    }

    // first find the most frequenty occuring value
    // then we have to delete all other enteries to make array equal
    //  So minimum deletion required is (Size of array)-(Max freqency)

    cout << "\nMinimum no. of deletion required to make equal: " << sz - table.getHighestFreq() << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void print(vector<string> _v)
{
    cout << "--------------\n";
    for (int i = 0; i < _v.size(); i++)
    {
        cout << _v[i] << endl;
    }
    cout << "--------------\n";
}
bool validDateCheck(string _date)
{
    if(_date.length()!=10)
    return false;
    // using stringstream to separate digits and "/"
    stringstream ss(_date);
    // str stores digits e.g "01" or "2022"
    string str;
    while (getline(ss, str, '/'))
    {
        // no digits in date have length greater than 4
        if (str.length() > 4 || str.length() == 3)
        {
            cout << "Invalid date\n";
            return false;
        }
        // checking for valid day and month digits
        else if (str.length() == 2)
        {
            // if str[0] or str[1] is out of '0'~'9' range then it must be anytbing other than digits and thus its invalid
            if (str[0] > '9' || str[0] < '0' || str[1] > '9' || str[1] < '0')
            {
                cout << "Invalid date\n";
                return false;
            }
        }
        // checking for valid year
        else if (str.length() == 4)
        {
            // if str[i] is out of '0'~'9' range then it must be anytbing other than digits and thus its invalid
            for (int i = 0; i < 4; i++)
                if (str[i] > '9' || str[i] < '0')
                {
                    cout << "Invalid date\n";
                    return false;
                }
        }
    }
    return true;
}

bool compareDates(string firstDate, string secondDate)
{
    // if secondDate is greater than firstDate the funciton returns true
    stringstream first_stream(firstDate);
    stringstream second_stream(secondDate);
    string str;
    int _firstDate[3];
    int _secondDate[3];
    for (int i = 0; getline(first_stream, str, '/'); i++)
    {
        _firstDate[i] = stoi(str);
    }
    for (int i = 0; getline(second_stream, str, '/'); i++)
    {
        _secondDate[i] = stoi(str);
    }

    for (int i = 2; i >= 0; i--)
    {
        if (_secondDate[i] > _firstDate[i])
            return true;
    }
    return false;
}

void swap(string *a, string *b) {
string temp = *a;
  *a = *b;
  *b = temp;
}

void sort(vector<string> &_v)
{

    for (int i = 0; i < _v.size() - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < _v.size(); j++)
        {
            if (compareDates(_v[j], _v[minIndex]))
                minIndex = j;
        }

        swap(&_v[minIndex], &_v[i]);
    }
}

int main()
{

    vector<string> _v;
    _v.push_back("08/01/2004");
    _v.push_back("08/08/2022");
    _v.push_back("08/03/2022");
    _v.push_back("09/01/2004");
    _v.push_back("09/02/2004");


    int loop = true;
    while (loop)
    {
        int choice;
        string str;
        cout << "Please select your option: \n";
        cout << "1. Add a date\n";
        cout << "2. Print dates\n";
        cout << "3. Sort dates\n";
        cout << "4. Exit\n";

        cin >> choice;

        switch (choice)
        {

        case 1:
            cin.ignore();
            do
            {
                cout << "Please enter data in format day/month/year\n--Example: 01/08/2022\n";
                getline(cin, str);
            } while (!validDateCheck(str) );
            _v.push_back(str);
            break;
        case 2:
            print(_v);
            break;
        case 3:
            sort(_v);
            print(_v);
            break;
        case 4:
            loop = false;
            break;
        default:
            cout << "Invalid choice\nPlease enter between 1~4\n";
        }
    }

    return 0;
}
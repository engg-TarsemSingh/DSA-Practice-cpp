#include <iostream>
#include <string>
using namespace std;

void accurances(string given)
{
    int temp[26] = {0};
    cout << "number of accurances of each character" << endl;
    for (int i = 0; i < given.size(); i++)
    {
        int number;
        if (given[i] >= 'a' && given[i] <= 'z' && given[i]!=' ')
        {
            number = given[i] - 'a';
        }
        else
        {
            number = given[i] - 'A';
        }
        temp[number]++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (temp[i] != 0)
        {
            char character = 'a' + i;
            cout << "number of accurances of [" << character << "] in given string is = " << temp[i] << endl;
        }
    }
}

int main()
{
    cout << "enter the string" << endl;
    string given;
    getline(cin, given);
    accurances(given);

    return 0;
}
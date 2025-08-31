#include <iostream>
#include <string>
using namespace std;

string remove_accurances(string main)
{
    cout << "enter substring which is to be removed = ";
    string sub ;
    getline(cin, sub);
    int subsize=sub.size()-1;
    for(int i=0 ; i<main.size()-subsize ; i++)
    {
        string ref;
        for(int j=i ; j<=i+subsize ; j++ )
        {
            ref.push_back(main[j]);
        }
        cout<<i<<" th ref = "<<ref<<endl;
        if(ref==sub)
        {
            main.erase(i,subsize+1);
        }
    } 
    return main;
}

int main()
{
    cout << "enter the main string" << endl;
    string main;
    getline(cin, main);
    string answer=remove_accurances(main);
    cout<<"answer = "<<answer;

    return 0 ;
}
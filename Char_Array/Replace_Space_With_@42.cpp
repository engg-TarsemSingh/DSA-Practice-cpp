#include<iostream>
#include<string>
using namespace std;

int main()
{
    cout<<"enter the string "<<endl;
    string given ;
    getline(cin,given);
    int m=given.size();
    for(int i=0 ; i<m ; i++ )
    {
        if(given[i]==' ')
        {
            given[i]='@';
            given.push_back('4');
            given.push_back('4');
            cout<<m<<endl;
            m=given.size();
            cout<<m<<endl;
            cout<<given<<endl<<endl;
            for(int j=(m-3) ; j>i ; j--)
            {
                given[j+2]=given[j];
                cout<<given<<endl;
            }
            given[i+1]='4';
            given[i+2]='2';
        }
    }
    cout<<given;
    return 0 ;
}
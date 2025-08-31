#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> numbering( string character , vector<int>& numb )
{
    for( int i=0 ; i<character.size() ; i++ )
    {
        int temp;
        int lx=0;
        if(character[i]>='a' && character[i]<='z')
        {
            temp=character[i]-'a';
        }
        if(character[i]>='A' && character[i]<='Z')
        {
            temp=character[i]-'A';
        }
        if(character[i]==' ')
        {
            temp=27+lx;
            lx++;
        }
        numb[temp]++;
    }
    return numb ;
}

bool permutation_check(string main , string sub)
{
    int size=sub.size();
    vector<int> numb;
    numbering(sub,numb);
    for( int i=0 ; i<main.size()-(size-1) ; i++ )
    {

    }
}

int main()
{
    cout<<"enter the string"<<endl;
    string main;
    getline(cin,main);
    cout<<"enter the string whose permutation is to be found = ";
    string sub;
    getline(cin,sub);
    bool answer=permutation_check(main,sub);
    cout<<"the permutation is happening = "<<answer;

    return 0 ;
}
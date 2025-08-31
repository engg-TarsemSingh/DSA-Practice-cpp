#include<iostream>
using namespace std;

int getlength( char name[] )
{
    int temp=0 ;
    for( int i=0 ; name[i]!='\0' ; i++ )
    {
        temp++;
    }
    return temp ;
}

int main()
{
    cout<<"enter your name "<<endl;
    char name[10];
    cin>>name;
    cout<<"your name is "<<name<<endl;
    int answer = getlength(name);
    cout<<"your name has "<<answer<<" latters in it "<<endl;

    return 0 ;
}
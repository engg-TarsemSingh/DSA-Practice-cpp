#include<iostream>
using namespace std;

void reverse ( char arr[] , int length )
{
    for( int i=0,j=(length-1) ; i<j ; i++,j-- )
    {
        swap(arr[i],arr[j]);
    }
}

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
    int length = getlength(name);
    reverse(name,length);
    cout<<"by reversing your name we get "<<name<<endl;

    return 0 ;
}
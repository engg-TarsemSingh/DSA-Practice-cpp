#include<iostream>
using namespace std;
void truecondition (int a,int b)
{
    if(a>=b)
    {
        cout<<"a is equal to or less than b"<<endl;
    }else{
        cout<<"b is greater than a"<<endl;
    };
    cout<<"HELLOW"<<endl;
};

void falsecondition (int a, int b)
{
    if(a==b)
    {
        cout<<"a is equal to b"<<endl;
    }else{
        cout<<"a is not equal to b"<<endl;
    };
};

int main()
{
    int a,b;
    cout<<"enter value of a"<<endl;
    cin>>a;
    cout<<"enter value of b"<<endl;
    cin>>b;
    
    truecondition ( a,  b);
    falsecondition ( a,  b);
    return 0;
}
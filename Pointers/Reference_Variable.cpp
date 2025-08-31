#include<iostream>
using namespace std;

int main()
{   
    int i=5;
    int& j=i;                  //creating referance variable j
    cout<<"value of i = "<<i<<endl;
    cout<<"address of i = "<<&i<<endl;
    cout<<"value of reference variable j = "<<j<<endl;
    cout<<"address of reference variable j = "<<&j<<endl;
    cout<<endl;
    i=i+4;
    cout<<"changing value of i=i+4 = "<<i<<endl;
    cout<<"value of j = "<<j<<endl;

    return 0 ;
}
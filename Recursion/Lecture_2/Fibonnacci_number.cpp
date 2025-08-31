#include<iostream>
using namespace std;

int fibonnacci(int position )
{
    if(position==0)
    {
        return 0 ;
    }
    if(position==1)
    {
        return 1 ;
    }

    return fibonnacci(position-1)+fibonnacci(position-2);
}

int main()
{
    int n;
    cout<<"enter the position of fibonnacci series whoes value is required = ";
    cin>>n;
    cout<<" the calue at "<<n<<"th position is = "<<fibonnacci(n);

    return 0;
}
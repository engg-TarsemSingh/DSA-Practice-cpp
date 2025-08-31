#include<iostream>
using namespace std ;

int counting(int count )
{
    if(count==0)
    {
        return 0;
    }
    int ans=counting(count-1);
    cout<<count<<endl;

    return count ;
}

int main()
{
    int count ;
    cout<<"ente the value upto which you want to count = ";
    cin>>count;
    counting(count);                               

    return 0 ;
}
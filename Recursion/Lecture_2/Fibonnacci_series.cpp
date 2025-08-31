#include<iostream>
using namespace std;

int fibonnacci(int max , int first=0 , int second=1)
{
    int third = first+second ;
    cout<<third<<"  ";
    max--;
    if(max==0)
    {
        return third;
    }
    int answer=fibonnacci(max,second,third);
    return answer;
}


int main()
{
    int max_value;
    cout<<"enter which positioned fibonnacci series number is required = ";
    cin>>max_value;
    cout<<"FIBONNACCI SERIES"<<endl;
    cout<<0<<"  "<<1<<"  ";
    int answer=fibonnacci(max_value-2);
    cout<<endl;
    cout<<"the fibonnacci number at position "<<max_value<<" is = "<<answer;

    return 0;
}
#include<iostream>
using namespace std;

void say_digits( int n , string d[] )
{
    if(n==0)
    {
        return ;
    }
    int index = n%10;
    n=n/10;
    say_digits( n , d );
    cout<<d[index]<<"  ";
}

int main()
{
    int number;
    cout<<"enter the number = ";
    cin>>number;
    string digit[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    say_digits(number,digit);

    return 0;
}
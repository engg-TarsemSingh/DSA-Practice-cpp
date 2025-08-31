#include<iostream>
using namespace std ;

long long power_fun( int number , int power )
{
    if(power==1)
    {
        return number ;
    }
    long long ans = number*power_fun(number,power-1);

    return ans;
}

int main()
{
    int number , power ;
    cout<<"enter the number = ";
    cin>>number;
    cout<<"enter the power of number = ";
    cin>>power;
    long long answer = power_fun(number,power);           //Function call
    cout<<"the answer of "<<number<<" POWER "<<power<<" is = "<<answer<<endl;

    return 0;
}
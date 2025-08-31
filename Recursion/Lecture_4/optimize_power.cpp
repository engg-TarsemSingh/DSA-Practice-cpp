//           a^b if b is even === (a^b/2) * (a^b/2)
//           a^b if b is odd  === a * [ (a^b/2) * (a^b/2) ]

#include<iostream>
using namespace std ;

int power_power(int number , int power)
{
    if(power==0)
    {
        return 1 ;
    }
    int ans = power_power(number,power/2);
    if(power%2==0)
    {
        return ans*ans;
    }
    else if(power%2!=0)
    {
        return number*(ans*ans);
    }

    return 1 ;
}

int main()
{
    int number , power ;
    cout<<"enter the number = ";
    cin>>number;
    cout<<"enter the power of number = ";
    cin>>power;
    cout<<"answer of "<<number<<" POWER "<<power<<" is = "<<power_power(number,power);

    return 0 ;
}
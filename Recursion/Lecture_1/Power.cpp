#include<iostream>
using namespace std ;

int power_fun( int n , int p )
{
    // n^p = n*n*n*n------(number of n = p)
    // n^p = (n^2)*n*n----(number of n = p-1)
    // let (n^2) = ppp
    
    if(p==0)                                   //base statment
    {
        return 1;
    }
    //             int ppp = power_fun(n,(p-1));
    //             int answer = n*ppp;
    //             return answer ;
    //                    OR

    return n*power_fun(n,(p-1));
}

int main()
{
    int power , number ;
    cout<<"enter the number = ";
    cin>>number;
    cout<<"enter the power = ";
    cin>>power;
    int answer = power_fun(number,power);
    cout<<"answer = "<<answer<<endl;

    return 0 ;
}
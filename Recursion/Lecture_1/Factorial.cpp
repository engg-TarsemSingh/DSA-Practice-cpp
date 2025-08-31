//    factorial of 3 
//    3! = 3*(3-1)*(3-2)
//    3! = 3*2*1

#include<iostream>
using namespace std ;

int factorial_fun( int given )
{
    // given! = given*(given-1)!
    // given! = given*(n)!
    // where n!=0 
    
    if(given==0)                                       //this is base statment
    {
        return 1;
    }
    int n = factorial_fun(given-1);
    int answer=given*n;

    return answer ;
}

int main()
{
    int factorial;
    cout<<"enter the number whose factorial is required = ";
    cin>>factorial;
    int answer = factorial_fun(factorial);
    cout<<"answer = "<<answer<<endl;

    return 0;
}
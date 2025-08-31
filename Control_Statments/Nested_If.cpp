#include<iostream>
using namespace std;
int main()
{
    int a= 5 , b = 5 , c= 12;
    if(a==b)
    {
        if(c==a+b){
            cout<<"value of c is"<<endl<<c<<endl;
        }
        else if (c==12){
            cout<<"c is 12"<<endl;
        }
        else{
            cout<<"a + b is not c"<<endl;
        }
    }else{
        if(a==5){
            cout<<"value of a is "<<endl<<a<<endl;
        }else{
            cout<<"all statment are false";
        }
    }

    return 0;
}
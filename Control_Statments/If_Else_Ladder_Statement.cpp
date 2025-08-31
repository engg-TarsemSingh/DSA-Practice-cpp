#include<iostream>
using namespace std;

void simple(int a , int b)
{
    if(a+b==10){
        cout<<"a+b=10"<<endl;
    }
    else if (a==b){
        cout<<"a=b"<<endl;
    }
    else if (a-b==0){
        cout<<"a-b=0"<<endl;
    }
    else if (a*b==2){
        cout<<"false"<<endl;
    }else{
        cout<<"all conditions are false"<<endl;
    };

};

void logic(int a, int b)
{
    if ( a+b==10 && a-b==0){
        cout<<"a+b=10"<<endl<<"a-b=0"<<endl;
    }else{
        cout<<"a is not equal to b"<<endl;
    }
};

int main()
{
    int a , b;
    cout<<"enter value of a"<<endl;
    cin>>a;
    cout<<"enter value of b"<<endl;
    cin>>b;
    simple(a,b);
    
    logic(a,b);

    return 0;
}



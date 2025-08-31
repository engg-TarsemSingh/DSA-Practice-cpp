#include<iostream>
using namespace std;

int star(int R, int C)
{
    for(int i=0 ; i<R ; i++)
    {
        for(int j=0 ; j<C ; j++)
        {
            cout<<"*"<<'\t';
        }
        cout<<endl;
    }
    return 0;
}

void numbers(int R , int C)
{
    int i ;
    for(i=1 ; i<=R ; i++)
    {
        for(int j = 0 ; j<C ; j++)
        {
            cout<<i<<'\t';
        }
        cout<<endl;
    }
}

int main()
{
    int R,C;
    cout<<"enter the no. of rows"<<endl;
    cin>>R;
    cout<<"enter the no. of columns"<<endl;
    cin>>C;
    star(R,C);
    cout<<endl<<endl<<endl;
    numbers(R,C);
    cout<<endl<<endl<<endl;
}
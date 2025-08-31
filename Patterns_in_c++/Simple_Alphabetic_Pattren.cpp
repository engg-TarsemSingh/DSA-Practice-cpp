#include<iostream>
using namespace std;

void square(int R)
{
    for(int i=0 ; i<R ; i++)
    {   
        for(int j=0 ; j<R ; j++)
        {
            char y= 'A'+i;
            cout<<y<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;

    for(int i=0 ; i<R ; i++)
    {
        for(int j=0 ; j<R ; j++)
        {
            char q='A'+j;
            cout<<q<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;

    char u='A';
    for(int i=0 ; i<R ; i++)
    {
        for(int j=0 ; j<R ; j++)
        {
            cout<<u<<"  ";
            u=u+1;
        }
        cout<<endl;
    }
    cout<<endl;

    for(int i=0 ; i<R ; i++)
    {   
        char q='A'+R-i-1;
        char w;
        for(int j=0 ; j<=i ; j++)
        {
            w=q+j;
            cout<<w;
        }
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
    cout<<"enter the rows required"<<endl;
    int R;
    cin>>R;
    cout<<"square alphabatic pattern"<<endl;
    square(R);

    return 0;
}
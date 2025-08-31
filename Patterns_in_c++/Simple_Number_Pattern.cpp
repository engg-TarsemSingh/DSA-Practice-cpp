#include<iostream>
using namespace std;

int main()
{   
    int R;
    cout<<"enter the rows required"<<endl;
    cin>>R;
    cout<<"enter the values of columan"<<endl;
    int C;
    cin>>C;

    for(int i=0 ; i<R ; i++)
    {
        for( int j=1;  j<=C ; j++ )
        {
            static int a=1;
            cout<<a<<"  ";
            a=a+1;
        }
        cout<<endl;
    }
    return 0 ;
}
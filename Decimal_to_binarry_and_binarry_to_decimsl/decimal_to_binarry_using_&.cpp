#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    cout<<"enter the decimal to be converted"<<endl;
    int d;
    cin>>d;

    int bit ;
    int answer = 0;
    for( int i=0 ; d!=0 ; d=d>>1 , i++)
    {
        bit=d&1;
        cout<<"bit"<<bit;
        answer=(bit*pow(10,i)+answer);

    }
    cout<<"dinary form is = "<<answer;
    
    return 0 ;
}
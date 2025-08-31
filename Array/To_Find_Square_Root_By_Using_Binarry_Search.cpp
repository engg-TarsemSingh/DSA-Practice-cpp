#include<iostream>
#include<math.h>
using namespace std;

long long int root ( int N , int R)
{
    int start=0 , end=N/2 , mid=(start+end)/2 , answer=0 ;
    for( ; start<=end ; )
    {
        long long int root=pow(mid,R);
        if(root==N)
        {
            cout<<"the "<<R<<" of the given number "<<N<<" is = "<<mid<<endl;
            return 1 ;
        }
        if(root>N)
        {
            end=mid-1;
        }
        else if(root<N)
        {
            start=mid+1;
            answer=mid;
        }
        mid=(start+end)/2 ;
    }
    cout<<"the closest answer to your question is "<<answer<<endl;
    return answer ;
}

double perfection (int N , int R , int a )
{
    cout<<"enter the number upto which decimal is required "<<endl;
    double tempt=a , decimal ;
    cin>>decimal;
    for(int i=1 ; i<=decimal ; i++ )
    {
        double fraction=1/pow(10,i) ;                                     

        for(double k=tempt ; pow(k,R)<N ; )
        {    
            tempt=tempt+fraction ;
            k=tempt+fraction ;                   //k is used to check wheather the future tempt is less than N
            cout<<" value of k = "<<tempt<<endl;
        }
    }
    cout<<" the fracional but not ferfect valoe is "<<tempt<<endl;
    return 0 ;
}

int main ()
{
    cout<<"enter the number whose root is required "<<endl;
    int Number;
    cin>>Number;
    cout<<"enter the value of root "<<endl;
    int Root;
    cin>>Root;

    int a = root(Number,Root);                                            //why is function callig here 
    if(a!=1)
    {
        perfection(Number,Root,a);
    }

    return 0 ;
}
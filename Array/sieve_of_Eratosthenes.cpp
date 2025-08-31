#include<iostream>
#include<vector>
using namespace std;

bool prime(int a)
{
    for(int i=2 ; i<a ; i++)
    {
        if(a%i==0)
        {
            return true;
        }
    }
    return false;
}

int  sieve_of_Eratosthenes(int target )
{
    cout<<"using sieve of Eratosthenes"<<endl;
    vector<bool> arr(target+1,true);
    int answer=0;
    for(int i=2 ; i<=target ; i++ )
    {
        if(arr[i])
        {
            answer += 1;
            cout<<"prime number = "<<i<<endl;
            for(int j=i ; j<=target ; j++)
            {
                if(prime(j))
                {
                    arr[j]=false;
                }
            }
        }
    }
    return answer;
}

int main ()
{
    cout<<"enter the number upto which prime number are required = ";
    int target;
    cin>>target;
    int ans=sieve_of_Eratosthenes(target);
    cout<<endl<<"number of prime number till "<<target<<" is "<<ans;

    return 0;
}
#include<iostream>
using namespace std;

void search(int array[],int N,int X)
{
    for(int i=0 ; i<N ; i++)
    {
        if(array[i]==X)
        {
            cout<<i<<endl;
        }
    }
}

int main()
{
   int array[6]={33,2,98,22,10,3};
   int N=sizeof(array)/sizeof(array[0]);
   cout<<"size of array = "<<N<<endl;
   int X;
   cout<<"enter the value you want to find"<<endl;
   cin>>X;
   search(array,N,X);
   return 0;

}
#include<iostream>
using namespace std;

void display ( int arr[] , int size )
{
    cout<<"displaying the array"<<endl;
    for( int i=0 ; i<size ; i++ )
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

void insertion ( int arr[] , int &s )
{
    cout<<"enter the number to be added"<<endl;
    int N , P ;
    cin>>N;
    cout<<"enter the position in which number i to be added"<<endl;
    cin>>P;
    for( int i=s-1 ; i>=P-1 ; i-- )
    {
        if ( i!=P-1 )
        {
            arr[i+1]=arr[i];
        }
        else
        {
            arr[i+1]=arr[i];
            arr[i]=N;
            s=s+1;
        }
    }
}

void deletion (int arr[] , int &si )
{
    cout<<"enter the position whose number is to be deleted"<<endl;
    int d;
    cin>>d;
    for(int i=0 ; i<si ; i++ )
    {
        if(i>=d-1)
        {
            arr[i]=arr[i+1];
        }
    }
    si=si-1;
}

int main()
{
    cout<<"enter the size of array"<<endl;
    int size;
    cin>>size;
    int arr[100];
    cout<<"enter the elements of array"<<endl;
    for( int i=0 ; i<size ; i++ )
    {
        cin>>arr[i];
    }
    cout<<endl;
    insertion(arr,size);
    deletion(arr,size);
    display(arr,size);

    return 0 ;
}
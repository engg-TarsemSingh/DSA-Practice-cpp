#include<iostream>
using namespace std;

void initialization ( int arr[] , int size )
{
    for ( int i=0 ; i<size ; i++ )
    {
        cin>>arr[i];
    }
}

void display ( int arr[] , int size)
{
    cout<<"displaying the array "<<endl;
    for( int i=0 ; i<size ; i++ )
    {
        cout<<arr[i]<<'\t';
    }
    cout<<endl;
}

void insertionsort ( int arr[] , int size )
{
    cout<<"sorting the array with insertionsort algorithem"<<endl;
    for(int i=1 ; i<size ; i++ )
    {
        int temt=arr[i];
        int j=i-1;
        for ( ; j>=0 && arr[j]>temt ; j-- )
        {
            arr[j+1]=arr[j];
        }
        arr[j+1]=temt;
    }
}

int main()
{
    cout<<"the size of array = ";
    int size;
    cin>>size;
    int arr[size];
    initialization(arr,size);
    display(arr,size);
    insertionsort(arr,size);
    display(arr,size);  

    return 0 ;
}
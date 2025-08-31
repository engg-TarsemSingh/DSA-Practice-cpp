#include<iostream>
#include<climits>
using namespace std;

void initialization ( int a[] , int s )
{
    cout<<"enter the values of array "<<endl;
    for ( int i=0 ; i<s ; i++ )
    {
        cin>>a[i];
    }
}

void display (int a[] , int s )
{
    cout<<"displaying the array"<<endl;
    for( int i=0 ; i<s ; i++ )
    {
        cout<<a[i]<<"  ";
    }
    cout<<endl;
}

void sort ( int arr[] , int size )
{
    cout<<"selection sorting the array "<<endl;
    for( int i=0 ; i<size-1 ; i++ )
    {
        int minimum=INT_MAX;                                         
        int index_min;
        for( int j=i ; j<size ; j++ )
        {
            if(arr[j]<minimum)
            {
                minimum=arr[j];
                index_min=j;
            }
        }
        if(index_min!=i)
        {
            arr[index_min]=arr[i];
            arr[i]=minimum;
        }
    }
}

int main()
{
    cout<<"enter the size of array = ";
    int size;
    cin>>size;
    int arr[size];
    initialization(arr,size);
    display(arr,size);
    sort(arr,size);
    display(arr,size);

    return 0 ;
}
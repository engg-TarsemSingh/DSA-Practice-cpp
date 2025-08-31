#include<iostream>
using namespace std;

void initialization ( int arr[] , int size )
{
    cout<<"enter the elements of array"<<endl;
    for(int i=0 ; i<size ; i++ )
    {
        cin>>arr[i];
    }
    cout<<endl;
}

void rotate ( int arr[] , int size )
{
    cout<<"enter the number of element to be rotated"<<endl;
    int ro;
    cin>>ro;
    for( ; ro>0 ; ro-- )
    {
        for(int i=size-1 ; i>=0 ; i-- )
        {
            if(i==0)
            {
                arr[i+1]=arr[i];
                arr[i]=arr[size];
            }else
            {
                arr[i+1]=arr[i];
            }
        }
        arr[size]=0;
    }
    cout<<endl;
}

void display ( int arr[] , int size )
{
    cout<<" displaying the array"<<endl;
    for(int i=0 ; i<size ; i++ )
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

int pivot (int arr[] , int size )
{
    int start=0 , end=size-1 , mid=(start/2)+(end/2);
    for( ; start<end ; )
    {
        if(arr[mid-1]>arr[mid] && arr[mid]<arr[mid+1])
        {
            cout<<" pivot element in sorted and circular array is "<<arr[mid]<<" this lies at "<<mid<<" index";
            return 0 ;
        }
        else if ( arr[mid]>=arr[0])
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
        mid=(start/2)+(end/2);
    }
    return 0 ;
}

int main()
{
    cout<<"enter the size of array"<<endl;
    int size;
    cin>>size;
    int arr[100];
    initialization (arr,size);
    display (arr,size);
    rotate (arr,size);
    display (arr,size);
    pivot (arr,size);

    return 0 ;
}
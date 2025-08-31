#include<iostream>
using namespace std;

void display(int arr[] , int size )
{
    cout<<" displaying the array "<<endl;
    for(int i=0 ;i<size ; i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

int peak (int arr[] , int size )
{
    int start=0 , end=size-1 , mid=(start/2)+(end/2) ;
    for( ; start<=end ; )
    {
        if( arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1] ) 
        {
            return mid ;
        }
        else if(arr[mid]>arr[mid-1])
        {
            start=mid+1;
        }
        else if (arr[mid]<arr[mid-1])
        { 
            end=mid-1;
        }
        mid=(start/2)+(end/2) ;
    }
    return INT_MAX ;
}

int main()
{
    int arr[]={0,1,2,3,4,8,10,12,40,41,50,40,30,20,19,18,17,9,2,1,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    display(arr,size);
    cout<<"find the peak of ountain array"<<endl;
    int p=peak(arr,size);
    cout<<arr[p];

    return 0;
}
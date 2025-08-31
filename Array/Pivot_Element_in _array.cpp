#include<iostream>
using namespace std;

void  display ( int arr[] , int size )
{
    cout<<"displaying the array"<<endl;
    for(int i=0 ; i<size ; i++ )
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

int pivot ( int arr[] , int size )
{
    int start=0 , end=size-1 , mid=(start/2)+(end/2) ;
    for( ; start<=end ; )
    {
        //finding the sum of left and right of mid 
        int left=0 , right=0 ;
        for(int i=0 ; i<mid ; i++)
        {
            left=left+arr[i];
        }
        for(int j=mid+1 ; j<size ; j++)
        {
            right=right+arr[j];
        }

        //checking if mid is pivot number 
        if (left==right)
        {
            cout<<"the pivot element is "<<arr[mid]<<" which is at "<<mid<<" index"<<endl;
            return 0 ;
        }

        //changing the mid
        if(left>right)
        {
            end=mid-1;
        }
        else if (left<right)
        {
            start=mid+1;
        }
        mid=(start/2)+(end/2) ;
    }
    cout<<"pivot number is not found"<<endl;
    return 0;
}

int main()
{
    int arr[]={1,2,3,4,5,10,25,50,-25};
    int size = sizeof(arr)/sizeof(arr[0]);
    display(arr,size);
    pivot(arr,size);

    return 2 ;
}
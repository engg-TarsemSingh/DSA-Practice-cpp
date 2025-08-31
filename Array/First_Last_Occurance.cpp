#include<iostream>
using namespace std;

void display ( int arr[] , int size )
{
    cout<<"displaying the array"<<endl;
    for(int i=0 ; i<size ; i++ )
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

int first ( int arr[] , int size , int find )
{
    int start=0 , end=size-1 , mid=(start/2)+(end/2) , answer=0 ;
    for ( ; start<=end ; )
    {
        if(arr[mid]==find)
        {
            answer=mid;
            end=mid-1;
        }
        else if(arr[mid]>find)
        {
            end=mid-1;
        }
        else if(arr[mid]<find)
        {
            start=mid+1;
        }
        mid=(start/2)+(end/2) ;
    }
    return answer ;
}

int last ( int arr[] , int size , int find )
{
    int start=0 , end=size-1 , mid=(start/2)+(end/2) , answer=0 ;
    for ( ; start<=end ; )
    {
        if(arr[mid]==find)
        {
            answer=mid;
            start=mid+1;
        }
        else if(arr[mid]>find)
        {
            end=mid-1;
        }
        else if(arr[mid]<find)
        {
            start=mid+1;
        }
        mid=(start/2)+(end/2) ;
    }
    return answer ;
}

int main()
{
    int arr[]={1,3,3,3,7,8,8,8,33,33,33,44,47,50,50};
    int size=sizeof(arr)/sizeof(arr[0]);
    display ( arr , size );
    cout<<"enter the element whose first and last accurance is to be found = ";
    int find;
    cin>>find;
    cout<<" first and last accurance of an element are given below respectabely "<<endl;
    cout<<first(arr,size,find)<<"   "<<last(arr,size,find);
}
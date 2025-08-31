#include<iostream>
using namespace std;

int last_accurance(int* arr , int find , int end , int start , int ans=-1)
{   
    if(start>end)
    {
        return ans;
    }

    int mid = (start+end)/2;
    if(arr[mid]==find)
    {
        return last_accurance(arr,find,end,mid+1,mid);
    }
    else if(arr[mid]>find)
    {
        return last_accurance(arr,find,mid-1,start,ans);
    }
    else if(arr[mid]<find)
    {
        return last_accurance(arr,find,end,mid+1,ans);
    }
    return ans ;
}

int first_accurance(int* arr , int find , int end , int start , int ans=-1)
{   
    if(start>end)
    {
        return ans;
    }

    int mid = (start+end)/2;
    if(arr[mid]==find)
    {
        return first_accurance(arr,find,mid-1,start,mid);
    }
    else if(arr[mid]>find)
    {
        return first_accurance(arr,find,mid-1,start,ans);
    }
    else if(arr[mid]<find)
    {
        return first_accurance(arr,find,end,mid+1,ans);
    }
    return ans ;
}

int main()
{
    int size;
    cout<<"enter the size of the array = ";
    cin>>size;
    int* arr = new int[size];
    for(int i=0 ; i<size ;i++)
    {
        cout<<"enter the "<<i+1<<" element of array = ";
        cin>>arr[i];
    }
    int find=0;
    cout<<"enter the number whose first and last accurance is to be found = ";
    cin>>find;
    int end=size-1 , start=0 ;
    int first=first_accurance(arr,find,end,start);
    cout<<"thw first accurance of "<<find<<" is = "<<first<<endl;

    int last=last_accurance(arr,find,end,start);
    cout<<"thw last accurance of "<<find<<" is = "<<last<<endl;

    cout<<"number of accurances = "<<last-first+1<<endl;

    delete []arr;
    return 0;
}
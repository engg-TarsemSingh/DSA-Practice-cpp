#include<iostream>
using namespace std;

bool is_present ( int end, int* arr , int find , int start )
{
    if(end<start)
    {
        return false;
    }

    int mid=(start+end)/2;

    if(arr[mid]==find)
    {
        return true;
    }

    if(arr[mid]>find)
    {
        return is_present(mid-1,arr,find,start);
    }
    if(arr[mid]<find)
    {
        return is_present(end,arr,find,mid+1);
    }

}

int main()
{
    int size ;
    cout<<"enter the array size = ";
    cin>>size;
    int* arr = new int[size];
    for(int i=0 ; i<size ; i++ )
    {
        cout<<"enter the "<<i+1<<" element of array = ";
        cin>>arr[i];
    }
    int find ;
    cout<<"enter the element to be found = ";
    cin>>find;
    int start=0;
    int end=size-1;
    if (is_present(end,arr,find,start))
    {
        cout<<"this element is present in array "<<endl;
    }else{
        cout<<"this is not present "<<endl;
    }
    delete []arr ;

    return 0;
}
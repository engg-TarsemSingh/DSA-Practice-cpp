#include<iostream>
using namespace std;

bool is_sorted ( int size , int* arr )
{
    if(size==1)
    {
        return true ;
    }
    else if(arr[0]>arr[1])
    {
        return false ;
    }

    return is_sorted(size-1 , arr+1);
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
    bool ans = is_sorted(size,arr);
    if(ans==1)
    {
        cout<<"the given array is sorted "<<endl;
    }else{
        cout<<"the given array is not sorted "<<endl;
    }
    delete []arr ;

    return 0;
}
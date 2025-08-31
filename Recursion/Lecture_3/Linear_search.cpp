#include<iostream>
using namespace std;

bool is_present ( int size , int* arr , int find )
{
    if(size==0)
    {
        return false ;
    }
    if(arr[0]==find)
    {
        return true ;
    }

    return is_present(size-1,arr+1,find);
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
    if (is_present(size,arr,find))
    {
        cout<<"this element is present in array "<<endl;
    }else{
        cout<<"this is not present "<<endl;
    }
    delete []arr ;

    return 0;
}
#include<iostream>
using namespace std;

int get_sum ( int size , int* arr )
{
    if(size==1)
    {
        return arr[0];
    }
    int ans = arr[0]+get_sum(size-1 , arr+1);
    return ans ;
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
    int ans = get_sum(size,arr);
    cout<<"the sum of given array = "<<ans<<endl;
    delete []arr ;

    return 0;
}
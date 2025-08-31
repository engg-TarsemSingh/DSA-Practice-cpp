#include<iostream>
using namespace std;

int unique_elements ( int nums[] , int size)
{
    int ans=1 ;
    int i=0 , j=i+1 ;
    for( ; j<size ; )
    {
        if(nums[i]==nums[j])
        {
            j++;
        }
        else if (nums[i]<nums[j])
        {
            i++;
            nums[i]=nums[j];
            ans++;
        }
    }

    return ans ;
}

void display (int given[] , int size )
{
    cout<<"displaying the array "<<endl;
    for(int i=0 ; i<size ; i++ )
    {
        cout<<given[i]<<"  ";
    }
    cout<<endl;
}

int main()
{
    int size ;
    cout<<"enter the size of vector = ";
    cin>>size;
    int given[size];
    for(int i=0 ; i<size ; i++)
    {
        cout<<"enter the "<<i+1<<" element of array = ";
        cin>>given[i];
    }
    display(given,size);
    int end_size = unique_elements(given,size);
    display(given,end_size);

    return 0;
}
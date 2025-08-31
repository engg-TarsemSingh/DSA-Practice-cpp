#include<iostream>
using namespace std ;

void display ( int arr[] )
{
    cout<<"displaying the array "<<endl;
    int size = 11;
    for(int i=0 ; i<size ; i++ )
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

void move_zero( int arr[] )
{
    cout<<"moving the zeroes int the array to left "<<endl;
    int size= 11;
    for( int i=0 ; i<size ; i++ )
    {
        if(arr[i]==0)
        {
            for( int j=i ; j<size ; j++ )
            {
                if(arr[j]!=0)
                {
                    swap(arr[i],arr[j]);
                }
            }
        }
    }
}

int main()
{
    int arr[]={1,0,5,6,0,3,0,7,0,6,8};
    display(arr);
    move_zero(arr);
    display(arr);

    return 0 ;
}
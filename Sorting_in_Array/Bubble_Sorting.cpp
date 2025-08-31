#include<iostream>
using namespace std;

void initialization ( int a[] , int s )
{
    cout<<"enter the values of array "<<endl;
    for ( int i=0 ; i<s ; i++ )
    {
        cin>>a[i];
    }
}

void display (int a[] , int s )
{
    cout<<"displaying the array"<<endl;
    for( int i=0 ; i<s ; i++ )
    {
        cout<<a[i]<<"  ";
    }
    cout<<endl;
}

int bubblesort ( int arr[] , int size )
{
    cout<<"performing bubble sort on an array "<<endl;
    int count;
    do{
        count = 0;
        for(int i=0 ; i<size-1 ; i++){
            if(arr[i]>arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                count++;
            }
        }
    }while(count!=0);

    return 1;
}

int main ()
{
    cout<<"enter the sixe of array = ";
    int size;
    cin>>size;
    int arr[size];
    initialization(arr,size);
    display(arr,size);
    bubblesort(arr,size);
    display(arr,size);

    return 0 ;
}
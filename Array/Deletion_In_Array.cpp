#include<iostream>
using namespace std;

void initialization ( int arr[] , int size )
{
    cout<<"enter the elements of array"<<endl;
    for( int i=0 ; i<size ; i++ )
    {
        cin>>arr[i];
    }
}

void display ( int arr[] , int size )
{
    cout<<"Displaying the array"<<endl;
    for(int i=0 ; i<size ; i++ )
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

void delete_value ( int arr[] , int size )
{
    cout<<"enter the value to be deleted "<<endl;
    int a;
    cin>>a;
    for(int i=0 ; i<size ; i++ )
    {
        if(a==arr[i])
        {
            arr[i]=arr[i+1];
        }
    }
    size=size-1;
}

void delete_position ( int arr[] , int &size )
{
    cout<<"deleting the element by position "<<endl;
    cout<<"enter the position to be deleted "<<endl;
    int a;
    cin>>a;
    for(int i=0 ; i<size ; i++ )
    {
       if(i>(a-1))
       {
            arr[i-1]=arr[i];
       }
    }
    size=size-1;
};

int main()
{
    cout<<"enter the size of array "<<endl;
    int size;
    cin>>size;
    int arr[size];
    initialization(arr,size);
    int a;
    do{
        cout<<" enter 1 if you want to delete by position "<<endl;
        cout<<" enter 2 if you want to delete by value "<<endl;
        cout<<" enter any other number if you want to exit "<<endl;
        cin>>a;
        switch(a)
        {
            case 1 : delete_position(arr,size);
            break;
            case 2 : delete_value(arr,size);
            break;
        }
        display(arr,size);
    }while( a==2 || a==1 );

    return 0 ;
}
#include<iostream>
using namespace std;

void reversing ( int array[] , int size )
{
    for(int i=0,e,d=size-1 ; i<size/2 ; i++,d-- )
    {
        e=array[i];
        array[i]=array[d];
        array[d]=e;
    }
}

void display ( int array[] , int size )
{
    for(int i=0 ; i<size ; i++ )
    {
        cout<<array[i]<<"   ";
    }
    cout<<endl;
}

int main()
{
    cout<<"enter the size of array"<<endl;
    int size;
    cin>>size;

    int array[100];
    cout<<"enter the elements of array"<<endl;
    for(int i=0 ; i<size ; i++ )
    {
        cin>>array[i];
    }

    display(array,size);
    reversing(array,size);
    display(array,size);

    return 0 ;
}
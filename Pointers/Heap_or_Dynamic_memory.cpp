#include<iostream>
using namespace std;

void insertion (int* ar , int s)
{
    cout<<"enter the elements of array "<<endl;
    for( int i=0 ; i<s ; i++ )
    {
        cin>>ar[i];
    }
}

void display (int* arr , int size )
{
    cout<<"displaying the array"<<endl;
    for(int i=0 ; i<size ; i++ )
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

int main()
{
    int s;
    cout<<"enter the size of array = ";
    cin>>s;
    int* array = new int[s];
    insertion(array,s);
    display(array,s);
    delete []array;

    return 0;
}
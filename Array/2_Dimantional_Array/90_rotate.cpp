#include<iostream>
using namespace std ;

void initialization (int r , int c , int array[][5])
{
    for(int i=0 ; i<r ; i++)
    {
        cout<<"enter the elements of "<<i<<" row "<<endl;
        for(int j=0 ; j<c ; j++)
        {
            cin>>array[i][j];
        }
    }
}

void display ( int r , int c , int arr[][5])
{
    cout<<"displaying the array "<<endl;
    for(int i=0 ; i<r ; i++)
    {
        for(int j=0 ; j<c ; j++)
        {
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
}

void rotate ( int r , int c , int array[][5])
{
    int array1[5][5];
    cout<<"rotating the matrix by 90 degree "<<endl;
    for(int i=0  ; i<r ; i++)
    {
        for(int j=r-1,k=0 ; j>=0 ; j--,k++)
        {
            array1[i][k]=array[j][i];
        }
    }
    display(5,5,array1);
}

int main()
{
    int array[5][5];
    initialization(5,5,array);
    display(5,5,array);
    rotate(5,5,array);

    return 0;
}
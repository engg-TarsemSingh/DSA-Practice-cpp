#include<iostream>
using namespace std ;

void initialization(int r , int c , int array1[][3])
{
    for(int i=0 ; i<r ; i++)
    {
        cout<<"enter the elements of "<<i+1<<" row of matrix "<<endl;
        for(int j=0 ; j<c ;j++)
        {
            cin>>array1[i][j];
        }
    }
}

void display ( int r , int c ,int arr[][3])
{
    cout<<"displaying the matrix "<<endl;
    for(int i=0 ; i<r ; i++)
    {
        for(int j=0 ;j<c ; j++)
        {
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
}

int largestrow (int r , int c , int array[][3])
{
    int row =0 ;
    int sum=0;
    for(int i=0 ; i<r ; i++)
    {
        int sum1=0;
        for(int j=0 ; j<c ; j++)
        {
            sum1 += array[i][j];
        }
        if(sum1>sum)
        {
            row=i;
            sum=sum1;
        }
    }
    return row+1;
}

int main()
{
    int array1[3][3];
    initialization(3,3,array1);
    display(3,3,array1);

    int answer =largestrow(3,3,array1);
    cout<<"the row with the largest sum = "<<answer<<endl;

    return 0 ;
}
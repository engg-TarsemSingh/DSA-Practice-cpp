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

int binary_search ( int r , int c , int arr[][5])
{
    cout<<"enter the number to be found = ";
    int target;
    cin>>target;
    cout<<endl;

    cout<<"appling binary search "<<endl;
    int start=0 , end=r*c-1 , mid=(start+end)/2;
    for( ; start<=end ; )
    {
        cout<<" the value of start = "<<start<<endl;
        cout<<" the value of end = "<<end<<endl;
        cout<<" the value of mid = "<<mid<<endl;
        if(target==arr[mid/c][mid%c])
        {
            return mid;
        }
        if(target>arr[mid/c][mid%c])
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
        mid=(start+end)/2;
    }
    return 0;
}

int main()
{
    int array[5][5];
    initialization(5,5,array);
    display(5,5,array);
    int answer=binary_search(5,5,array);
    if(answer==0)
    {
        cout<<"element is not present in matrix"<<endl;
    }
    else
    {
        cout<<"the element is present at ["<<answer/5<<" , "<<answer%5<<"] position "<<endl;
    }

    return 0;
}
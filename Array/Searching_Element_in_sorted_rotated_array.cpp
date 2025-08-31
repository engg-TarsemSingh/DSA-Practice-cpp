#include<iostream>
using namespace std;

void initialization ( int arr[] , int size )
{
    cout<<" enter the elements of array "<<endl;
    for(int i=0 ; i<size ; i++ )
    {
        cin>>arr[i];
    }
    cout<<endl;
}

void display (int arr[] , int size )
{
    cout<<" displaying the element of array "<<endl;
    for ( int i=0 ; i<size ; i++ )
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

void rotate ( int arr[] , int size )
{
    cout<<" enter the element to be reversed = ";
    int reverse;
    cin>>reverse;

    for(int i=0 ; i<reverse ; i++ )
    {
        for( int j=size-1 ; j>=0 ; j-- )
        {
            if(j==0)
            {
                arr[j+1]=arr[j];
                arr[j]=arr[size];
            }
            else
            {
                arr[j+1]=arr[j];
            }
        }
        arr[size]=0;
    }
}

int search_element (int arr[] , int size )
{
    cout<<"enter the element to be found = ";
    int find;
    cin>>find;
    int pivot ; 
    int left=0 , right=size-1 , m=(left/2)+(right/2) ;                 
    for( ; left<=right ; )
    {
        if(arr[m]==find)
        {
            cout<<"the element  "<<find<<"  is present at  "<<m<<"  index "<<endl;
            return 0 ;
        }
        
        if(arr[m-1]>arr[m] && arr[m]<arr[m+1])
        {
            pivot=m;
            cout<<" pivot element in array is "<<arr[pivot]<<" at "<<pivot<<" index"<<endl;
            break;
        }
        else if ( arr[0]<arr[m] )
        {
            left=m+1;
        }
        else
        {
            right=m-1;
        }
        m=(left/2)+(right/2) ;
        
    }

    int start=0 , end=size-1 , mid=(start/2)+(end/2) ;
    for( ; start<=end ; )
    {
        if(arr[mid]==find)
        {
            cout<<"the element  "<<find<<"  is present at  "<<mid<<"  index "<<endl;
            return 0 ;
        }

        if(arr[end]<find && find<arr[pivot-1])
        {
            end=pivot-1;
        }
        else
        {
            start=pivot+1;
        }
        mid=(start/2)+(end/2) ;
    }
    return 1 ;
}

int main()
{
    cout<<"enter the size of array = ";
    int size;
    cin>>size;
    int arr[100];

    initialization(arr,size);
    display(arr,size);
    rotate(arr,size);
    display(arr,size);
    search_element(arr,size);

    return 0;
}
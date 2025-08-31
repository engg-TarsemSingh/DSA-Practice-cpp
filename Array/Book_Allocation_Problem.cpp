#include<iostream>
using namespace std ;

void initialization (int arr[] , int size )
{
    cout<<"enter the pages of every "<<size<<" book"<<endl;
    for (int i=0 ; i<size ; i++ )
    {
        cin>>arr[i];
    }
}

bool isposible ( int arr[] , int size , int students , int mid )
{
    int studentcout = 1;
    int sumpages=0 ;
    for(int i=0 ; i<size ; i++ )
    {
        if(sumpages+arr[i]<=mid)
        {
            sumpages=sumpages+arr[i];
        }
        else
        {
            studentcout++;
            if(studentcout>students || arr[i]>mid )
            {
                return false ;
            }
            sumpages=arr[i];
        }
    }
    return true ;
}

void allocation ( int arr[] , int size , int students )
{
    int start=0 , end=0 ;
    for(int i=0 ; i<size ; i++)
    {
        end=end+arr[i];   
    }
    int mid=(start+end)/2;

    int answer = -1;    
    for( ; end>=start ; )
    {
        if(isposible (arr,size,students,mid))
        {
            answer=mid;
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
        mid=(start+end)/2;
    }
    cout<<"the minimum number of maximum pages a chield can have is "<<endl;
    cout<<answer;
}

int main ()
{
    cout<<"enter the number of books = ";
    int size;
    cin>>size;
    int arr[size];
    initialization(arr,size);
    cout<<"enter the number of students present = ";
    int students ;
    cin>>students;
    allocation(arr,size,students);

    return 0 ;
}
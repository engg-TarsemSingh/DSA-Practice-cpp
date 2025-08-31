#include<iostream>
using namespace std;

void initi(int* given , int size)
{
    for(int i=0 ;i <size ; i++)
    {
        cout<<"enter the value of "<<i+1<<" element = ";
        cin>>given[i];
    }
}

void display( int* given , int size , int start=0)
{
    cout<<"displaying the array"<<endl;
    for(int i=start ; i<size ; i++)
    {
        cout<<given[i]<<"  ";
    }
    cout<<endl;
}

void merge (int* given , int left , int mid , int right)
{
    int first_size=mid-left+1;
    int second_size=right-mid;
    int* first = new int[first_size];
    int* second = new int[second_size];

    for(int i=0 ; i<first_size ; i++)                        //initializating first array
    {
        first[i]=given[left+i];
    }
    for(int j=0 ; j<second_size ; j++)                     //initialization second array
    {
        second[j]=given[mid+1+j];
    }
    int k=left;                                               // main array[given] index 
    int i=0,j=0;
    for( ; i<first_size && j<second_size ; )
    {
        if(first[i]>second[j])
        {
            given[k]=second[j];
            j++;
            k++;
        }
        else
        {
            given[k]=first[i];
            i++;
            k++;
        }
    }
    for( ; i<first_size ; i++,k++)
    {
        given[k]=first[i];
    }
    for( ; j<second_size ; j++,k++)
    {
        given[k]=second[j];
    }

    delete []first;
    delete []second;
}

void merge_sort( int* given , int left , int right)
{
    if(left>=right)
    {
        return ;
    }
    int mid=left+(right-left)/2;

    merge_sort(given,left,mid);
    merge_sort(given,mid+1,right);

    merge(given,left,mid,right);
}

int main()
{
    int size ;
    cout<<"enter the size of array = ";
    cin>>size;
    int* array_given = new int[size];
    initi(array_given,size);
    display(array_given,size);
    merge_sort(array_given,0,size-1);
    display(array_given,size);

    delete []array_given;

    return 0 ;
}
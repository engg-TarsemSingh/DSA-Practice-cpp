#include<iostream>
using namespace std;

void minimumterm ( int array[] , int size )
{
    int min= INT_MAX;
    for(int i=0 ; i<size ; i++)
    {
        if(array[i]<min)
        {
            min=array[i];
        }
    }
    cout<<"minimum value in given array is = "<<min<<endl;
}

void maximumterm ( int array[] , int size )
{
    int min= INT_MIN;
    for(int i=0 ; i<size ; i++)
    {
        if(array[i]>min)
        {
            min=array[i];
        }
    }
    cout<<"maximum value in given array is = "<<min<<endl;
}

int predefined (int array[] , int size )
{
    cout<<"with the help of predefined function"<<endl;
    int mini=INT_MAX , maxe=INT_MIN ;
    for(int i=0 ; i<size ; i++)
    {
        mini=min(mini,array[i]);
        maxe=max(array[i],maxe);
    }
    cout<<"minimum value is = "<<mini<<endl;
    cout<<"maximum value is = "<<maxe<<endl;
    return 0;
}

int main()
{
    cout<<"enter the size of array"<<endl;
    int size;
    cin>>size;

    int array[100];
    cout<<"enter the elements of array "<<endl;
    for(int i=0 ; i<size ; i++)
    {
        cin>>array[i];
    }

    minimumterm(array , size);
    maximumterm(array , size);
    predefined(array,size);

    return 0 ;
}
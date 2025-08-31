#include<iostream>
using namespace std;

void swaparray ( int array[] , int size )
{
    cout<<endl<<"alternative swap of array"<<endl<<endl;
    for(int i=0 ; i<size-1 ; i=i+2)
    {
        //int a=array[i];
        //array[i]=array[i+1];
        //array[i+1]=a;
        //     OR
        swap(array[i],array[i+1]);
    }
}

void display ( int array[] , int size )
{
    cout<<"display of array"<<endl;
    for(int i=0 ; i<size ; i++ )
    {
        cout<<array[i]<<"  ";
    }
    cout<<endl;
}

void uniquenumber (int array[] , int size )
{
    cout<<" the unique number in array is = ";
    int answer = 0 ;
    for(int i=0 ; i<size ; i++ )
    {
        answer=answer^array[i];
    }
    cout<<answer;
    cout<<endl;
}

void duplicant( int array[] , int size )
{
    
}

int main ()
{
    cout<<" enter the size of array "<<endl;
    int size;
    cin>>size;
    int array[100];
    cout<<"enter the elements of array"<<endl;
    for(int i=0 ; i<size ; i++ )
    {
        cin>>array[i];
    }
    cout<<endl;

    //swaparray(array , size);
    //display(array , size);
    //uniquenumber(array , size);
    duplicant(array , size);
    return 0;    
}
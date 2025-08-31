#include<iostream>
using namespace std;

void initialization ( int** main , int* size_column , int row )
{
    for(int i=0 ; i<row ; i++ )
    {
        main[i]=new int[size_column[i]];
        for(int j=0 ; j<size_column[i] ; j++)
        {
            cout<<"enter the element of row["<<i+1<<"] column["<<j+1<<"]  = ";
            cin>>main[i][j];
        }
    }
}

void display ( int** main , int* size_column , int row )
{
    cout<<"displaying the array "<<endl;
    for(int i=0 ; i<row ; i++ )
    {
        for(int j=0 ; j<size_column[i] ; j++)
        {
            cout<<main[i][j]<<"  ";
        }
        cout<<endl;
    }
}

void deleting_memory (int** main , int row )
{
    cout<<"deleting the memory "<<endl;
    for( int i=0 ; i<row ; i++ )
    {
        delete []main[i];
    }
    delete []main;
}

int main()
{
    int row ;
    cout<<"enter the number of rows = ";
    cin>>row;
    int* size_column = new int[row];
    for(int i=0 ; i<row ; i++ )
    {
        cout<<"enter the size of column for "<<(i+1)<<" row = ";
        cin>>size_column[i];
    }

    int** array = new int*[row];                                             //Declaring main array
    

    initialization(array,size_column,row);
    display(array,size_column,row);
    deleting_memory(array,row);
    delete []size_column;

    return 0 ;
}
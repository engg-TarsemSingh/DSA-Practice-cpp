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

int index(int* given , int left , int right )
{
    int right_index =0 ;
    int count=0;
    for(int i=left+1 ; i<=right ; i++)
    {
        if(given[left]>given[i])
        {
            count++;
        }
    }
    right_index=left+count;
    swap(given[left],given[right_index]);

    // making sure that left side of first_element is less than first_element 
    for( int i=left,j=right ; i<right_index && j>right_index ; )
    {
        while(given[i]<given[right_index])
        {
            i++;
        }
        while(given[j]>given[right_index])
        {
            j--;
        }
        if(i<right_index && j>right_index)
        {
            swap(given[i],given[j]);
        }
    }

    return right_index;
}

void quick_sort( int* given , int left , int right )
{
   if(left>=right)
   {
        return ;
   }

   int right_index_of_first_element = index(given,left,right);       

   //sort the left part
   quick_sort(given,left,right_index_of_first_element-1);

   //sort right part
   quick_sort(given,right_index_of_first_element+1,right);

}

int main()
{
    int size ;
    cout<<"enter the size of array = ";
    cin>>size;
    int* array_given = new int[size];
    initi(array_given,size);
    display(array_given,size);
    quick_sort(array_given,0,size-1);
    display(array_given,size);

    delete []array_given;

    return 0 ;
}
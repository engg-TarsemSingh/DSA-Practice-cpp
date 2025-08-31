#include<iostream>
using namespace std;

void initialization ( int arr[] , int size )
{
    cout<<"enter the elements of array"<<endl;
    for( int i=0 ; i<size ; i++ )
    {
        cin>>arr[i];
    }
}

void display ( int arrr[] , int size )
{
    cout<<"displaying the array "<<endl;
    for( int i=0 ; i<size ; i++ )
    {
        cout<<arrr[i]<<"  ";
    }
    cout<<endl;
}

void  merge ( int first[] , int second [] , int fi , int se )
{
    cout<<"merging the two array"<<endl;
    int size = fi+se ;
    int answer[size];
    int i=0 , j=0 , k=0 ;
    for( ; i<fi && j<se ; )
    {
        if(first[i]<=second[j])
        {
            answer[k]=first[i];
            ++i;
            ++k;
        }
        else
        {
            answer[k]=second[j];
            ++j;
            ++k;
        }
    }
    for( ; i<fi ; )
    {
        answer[k]=first[i];
        i++;
        k++;
    }
    for( ; j<se ; )
    {
        answer[k]=second[j];
        k++;
        j++;
    }
    display(answer,size);
}

int main()
{
    cout<<"enter the size of first array "<<endl;
    int fi;
    cin>>fi;
    int first[fi];
    initialization(first,fi);
    cout<<"enter the size of second array "<<endl;
    int se ;
    cin>>se;
    int second[se];
    initialization(second,se);
    merge( first , second , fi , se );

    return 0 ;
}
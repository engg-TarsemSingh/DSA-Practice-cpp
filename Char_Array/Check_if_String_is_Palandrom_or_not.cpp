//this program is not case sensitive 
//and will not considered Special cheracters and symbols
#include<iostream>
#include<vector>
using namespace std;

void initialization ( char arr[] , int size )
{
    cout<<"enter the elements of array "<<endl;
    for( int i=0 ; i<size ; i++ )
    {
        cin>>arr[i];
    }
}

char lowercase ( char L )
{
    char change;
    if(L<='z' && L>='a')
    {
        return L;
    }
    else
    {
        change=(L-'A')+'a';
        return change;
    }
}

int check ( int a )
{
    int A='A' , Z='z' ;
    if( (a>=A && a<=Z) || (a>='0' && a<='9') )
    {
        return 1 ;
    }
    else
    {
        return 0 ;
    }
}

bool palandrom ( char arr[] , int size )
{
    for( int i=0,j=size-1 ; i<j ; )
    {
        int first = check(arr[i]);
        int second = check(arr[j]);

        if( first==1 && second==1 )
        {
            int f = lowercase(arr[i]);
            int s = lowercase(arr[j]);

            if(f!=s)
            {
                return false ;
            }
            else
            {
                i++;
                j--;
            }
        }
        else if( first!= 1 )
        {
            i=i+1;
        }
        else
        {
            j=j-1;
        }
    }
    return true ;
}

//={'@','N','o','o','N','#'} ;

int main()
{
    cout<<"enter size of array to be checked for palandrom"<<endl;
    int size ;
    cin>>size;
    char arr[size];
    initialization(arr,size);
    cout<<"The answer is "<<palandrom(arr,size);

    return 0 ;
}
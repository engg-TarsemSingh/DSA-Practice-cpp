#include<iostream>
using namespace std;

void display (int array[] , int s )
{
    cout<<"desplaying aarray"<<endl;
    for(int i=0 ; i<s ; i++ )
    {
        cout<<array[i]<<"  ";
    }
    cout<<endl;
}

void intersection (int first[] , int second[] , int f , int s )
{
    cout<<"intersecting elements"<<endl;
    for(int i=0 ; i<f ; i++ )
    {
        for( int j=0 ; j<s ; j++ )
        {
            if(first[i]==second[j])
            {
                cout<<first[i]<<"  ";
                second[j]=INT_MIN;
                break;
            }
        }
    }
}

int main()
{
    int first[5];
    cout<<"enter elements of first array "<<endl;
    for(int i=0 ;i<5 ; i++ )
    {
        cin>>first[i];
    }
    int second[8];
    cout<<"enter the elements of second array "<<endl;
    for(int i=0 ; i<8 ; i++ )
    {
        cin>>second[i];
    }
    display(first , 5);
    display(second , 8);
    intersection(first,second ,5,8);

    return 0 ;
}

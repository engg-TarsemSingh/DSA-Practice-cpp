#include<iostream>
#include<vector>
using namespace std;

void initialization ( int array[] , int size )
{
    cout<<"enter the elements of array"<<endl;
    for( int i=0 ; i<size ; i++ )
    {
        cin>>array[i];
    }
}

void display ( vector<int> answer )
{
    cout<<"displaying the answer or resultant array"<<endl;
    int size = answer.size();
    for( int i=0 ; i<size ; i++ )
    {
        cout<<answer.at(i);
    }
    cout<<endl;
}

int max ( int a , int b)
{
    if(a==b)
    {
        return a;
    }
    else if ( a>b )
    {
        return a;
    }
    else
    {
        return b;
    }
}

vector<int> add( int first[] , int second[] , int size1 , int size2 )
{
    vector<int> temp ;
    int R = max(size1,size2);
    int index1 = size1-1;
    int index2 = size2-1;

    int carry=0 ;

    for( int i=(R-1) ; i>=0 ; i-- )
    {
        if( index1>=0 && index2>=0 )
        {
            int sum = first[index1]+second[index2]+carry;
            temp.insert(temp.begin()+0,sum%10);
            carry=sum/10;
            index1=index1-1;
            index2=index2-1;
        }
        else if( index1>=0 )
        {
            int sum = first[index1]+carry;
            temp.insert(temp.begin()+0,sum%10);
            carry=sum/10;
            index1=index1-1;
        }
        else
        {
            int sum = second[index2]+carry;
            temp.insert(temp.begin()+0,sum%10);
            carry=sum/10;
            index2=index2-1; 
        }
    }
    if( carry!=0 )
    {
        temp.insert(temp.begin()+0,carry);
    }

    return temp ;
} 

int main()
{
    cout<<"Size of first array is = ";
    int size_first ;
    cin>>size_first;
    int first[size_first];
    initialization(first,size_first);
    cout<<"Size of second array is = ";
    int size_second;
    cin>>size_second;
    int second[size_second];
    initialization(second,size_second);

    vector<int> answer = add(first,second,size_first,size_second);
    display(answer);

    return 0 ;
}
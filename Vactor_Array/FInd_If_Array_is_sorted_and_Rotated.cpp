#include<iostream>
#include<vector>
using namespace std;

bool checking ( vector<int> given )
{
    cout<<"checking the array if it is sorted and rotated"<<endl;
    int count=0;
    for( int i=0 ; i<given.size() ; i++ )
    {
        if(given[(i+1)%given.size()]<given[i])
        {
            cout<<"the value of i = "<<i<<endl;
            cout<<"the value of (i+1)%size "<<(i+1)%given.size()<<endl;
            count=count+1;
        }
    }
    if(count==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    vector<int> arr ={4,5,6,7,8,1,2,3};
    bool answer = checking(arr);
    cout<<answer;

    return 0 ;
}
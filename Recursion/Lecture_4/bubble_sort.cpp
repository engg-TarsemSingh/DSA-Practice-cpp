#include<iostream>
#include<vector>
using namespace std;

void display(vector<int> given)
{
    cout<<"displaying the vector "<<endl;
    for(int i=0 ; i<given.size() ; i++)
    {
        cout<<given[i]<<"  ";
    }
    cout<<endl;
}

void bubble_sort(vector<int>& given , int end ,int start=0 , int count=0)
{
    if(start==end)
    {
        if(count==0)
        {
            return ;
        }
        end--;
        start=count=0;
    }
    if(given[start]>given[start+1])
    {
        swap(given[start],given[start+1]);
        count++;
    }
    start++;
    bubble_sort(given,end,start,count);
}

int main()
{
    int size ;
    cout<<"enter the size of vector = ";
    cin>>size;
    vector<int> given(size,0);
    for(int i=0 ; i<size ; i++)                           //initializaing the vector
    {
        cout<<"enter the value of "<<i+1<<" element of vector = ";
        cin>>given[i];
    }
    //display(given);
    cout<<endl;
    int end =given.size()-1;
    bubble_sort(given,end);
    display(given);

    return 0;
}
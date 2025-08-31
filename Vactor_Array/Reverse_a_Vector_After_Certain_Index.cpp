#include<iostream>
#include<vector>
using namespace std;

void inilization( vector<int> &vec )
{
    cout<<"Enter the size of vector "<<endl;
    int size;
    cin>>size;
    cout<<"enter the elements to be inserted "<<endl;
    for( int i=0 ; i<size ; i++ )
    {
        int element ;
        cin>>element;
        vec.push_back(element);
    }
}

void display ( vector<int> dis )
{
    cout<<"displaying the vector"<<endl;
    for( int i:dis )
    {
        cout<<i<<"  ";
    }
    cout<<endl;
}

vector<int> answer(vector<int> re )
{
    cout<<"reversing the vector "<<endl;
    cout<<"enter the index after which element is to be reversed "<<endl;
    int start;
    cin>>start;
    int size=re.size()-1;
    for( int i=start+1 , j=size ; i<j ; i++ , j-- )
    {
        swap(re[i],re[j]);
    }
    return re ;
}

int main ()
{
    vector<int> vec ;
    inilization(vec);
    display(vec);
    vector<int> reversed = answer(vec);
    display(reversed);

    return 0 ;
}
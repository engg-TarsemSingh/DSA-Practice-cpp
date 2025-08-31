#include<iostream>
#include<vector>
using namespace std ;

void init ( vector<int> &given , int size )
{
    for(int i=0 ; i<size ; i++)
    {
        cout<<"enter the "<<i+1<<"th element of vector = ";
        int a;
        cin>>a;
        given.push_back(a);
    }
}

void display ( vector<int> given , int size )
{
    cout<<"displaying the vector"<<endl;
    for( int i=0 ; i<size ; i++)
    {
        cout<<given[i]<<"  ";
    }
    cout<<endl;
}

void solve(vector<int> given , int index , vector<int> output , vector<vector<int>> &ans)
{
    //base case
    if(index >= given.size())
    {
        ans.push_back(output);
        return ;
    }

    //exclude
    solve(given,index+1,output,ans);

    //include
    output.push_back(given[index]);
    solve(given,index+1,output,ans);

}

vector<vector<int>> subset(vector<int> given)
{
    vector<vector<int>> ans;
    vector<int> output;
    int index=0;

    solve(given,index,output,ans);
    return ans;
}

int main()
{
    vector<int> given ;
    int size ;
    cout<<"enter the size of vector = ";
    cin>>size;
    init(given,size);
    display(given,size);
    vector<vector<int>> power_set_of_vector = subset(given);
    for( int i=0 ; i<power_set_of_vector.size() ; i++)
    {
        int size = power_set_of_vector[i].size();
        for( int j=0 ; j<size ; j++)
        {
            cout<<power_set_of_vector[i][j];
        }
        cout<<"  ";
    }

    return 0;
}
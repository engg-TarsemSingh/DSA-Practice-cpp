#include<iostream>
#include<vector>
#include<string>
using namespace std ;

void solve (vector<int> given , vector<vector<char>> &ans , vector<char> &output , int index , string mapping[] )
{
    if(index>=given.size())
    {
        ans.push_back(output);
        return ;
    }

    int digit = given[index];
    string value=mapping[digit];

    for(int i=0 ; i<value.length() ; i++)
    {
        output.push_back(value[i]);
        solve(given , ans , output , index+1 , mapping);
        output.pop_back();
    }

}

vector<vector<char>> solution (vector<int> given)
{
    vector<vector<char>> ans ;
    vector<char> output ;
    int index = 0 ;
    string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    solve(given,ans,output,index,mapping);

    return ans ;
}
 
int main()
{
    vector<int> given = {2,3};
    vector<vector<char>> posibility = solution (given);

    for(int i=0 ; i<posibility.size() ; i++)                                       //displaying the answer
    {
        for(int j=0 ; j<posibility[i].size() ; j++)
        {
            cout<<posibility[i][j];
        }
        cout<<"  ";
    }
    cout<<endl;

    return 0 ;
}
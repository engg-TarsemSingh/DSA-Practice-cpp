#include<iostream>
#include<vector>
using namespace std;

int noOfWays(int index , vector<int>& cost , vector<int>& dp){
    if(index>=cost.size()){
        return 0;
    }

    if(dp[index]!=-1){
        return dp[index];
    }

    dp[index] = min(noOfWays(index+1,cost,dp),noOfWays(index+2,cost,dp))+cost[index];
    return dp[index];
}

int main(){
    int stairs;
    cout<<"enter the number of stairs : ";
    cin>>stairs;
    vector<int> cost(stairs);
    for(int i=0 ; i<stairs ; i++){
        cout<<"enter the cost on "<<i+1<<"th stair : ";
        cin>>cost[i];
    }

    vector<int> dp(stairs,-1);
    int result = min(noOfWays(0,cost,dp),noOfWays(1,cost,dp));
    cout<<"minimum cost for climbing the top = "<<result<<endl;

    return 0;
}
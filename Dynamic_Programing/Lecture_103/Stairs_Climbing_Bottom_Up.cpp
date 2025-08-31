#include<iostream>
#include<vector>
using namespace std;

int mincost(vector<int>& cost){
    vector<int> dp(cost.size());

    dp[0] = cost[0];
    dp[1] = cost[1];
    for(int i=2 ; i<cost.size() ; i++){
        dp[i] = min(dp[i-1],dp[i-2])+cost[i];
    }

    return min(*(dp.end()-2),*(dp.end()-1));
}

int main(){
    int stairs;
    cout<<"enter the no. of atairs : ";
    cin>>stairs;
    vector<int> cost(stairs);
    for(int i=0 ; i<stairs ; i++){
        cin>>cost[i];
    }

    int reault = mincost(cost);
    cout<<"minimum cost to climbing on top : "<<result<<endl;

    return 0;
}
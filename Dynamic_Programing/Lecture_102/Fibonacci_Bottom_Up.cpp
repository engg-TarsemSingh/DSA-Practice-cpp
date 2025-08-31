#include<iostream>
#include<vector>
using namespace std;

int factorial(int position , vector<int>& dp){
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2 ; i<=position ; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }

    return dp[position];
}

int main(){
    int position;
    cout<<"enter the position : ";
    cin>>position;

    vector<int> dp(position+1,-1);
    int result = factorial(position,dp);
    cout<<"the value at "<<position<<"th in fibonacci series is : "<<result<<endl;

    return 0;
}
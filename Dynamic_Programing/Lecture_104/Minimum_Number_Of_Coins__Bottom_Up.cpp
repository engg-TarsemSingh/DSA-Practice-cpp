#include<iostream>
#include<climits>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

unordered_set<int> initializeunordered_set(){
    unordered_set<int> ans;
    while(true){
        int element;
        cin>>element;
        if(element<=0) {break;}
        ans.insert(element);
    }
    return ans;
}

int solv(int amount , unordered_set<int>& coins){
    unordered_map<int,int> dp(amount+1,INT_MAX);
    dp[0]=0;
    for(int i=1 ; i<=amount ; i++){
        for(int j=0 ; j<coins.size() ; j++){
            if(i-coins[j]>=0 && dp[i-nums[j]]!=INT_MAX){
                dp[i] = min(dp[i],1+dp[i-coins[j]]);
            }
        }
    }
    if(dp[amount]==INT_MAX) {return -1;}
    return dp[amount];
}

int main(){
    cout<<"----------       ENTER THE VALUES OF COINS       ----------"<<endl;
    unordered_set<int> coins = initializeunordered_set();
    int amount;
    cout<<"----------       ENTER AMOUNT    : ";
    cin>>amount;

    int mincoins = solv(amount,coins);
    cout<<"the minimum no. of coins required to represent "<<amount<<" are : "<<mincoins<<endl<<endl;

    return 0;
}
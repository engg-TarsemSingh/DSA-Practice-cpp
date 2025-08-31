#include<iostream>
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

int solv(int amount , unordered_set<int>& coins , unordered_map<int,int>& dp){
    if(amount==0){
        return 0;
    }
    if(dp[amount]!=0){
        return dp[amount];
    }

    int currentmin = -1;
    for(int i : coins){
        if(amount-i>=0){
            int ans = solv(amount-i,coins,dp);
            if(ans!=-1){
                if(currentmin==-1){
                    currentmin = ans+1;
                }
                else{
                    currentmin = min(currentmin,ans+1);
                }
            }
        }
    }

    dp[amount] = currentmin;
    return dp[amount];
}

int main(){
    cout<<"----------       ENTER THE VALUES OF COINS       ----------"<<endl;
    unordered_set<int> coins = initializeunordered_set();
    int amount;
    cout<<"----------       ENTER AMOUNT    : ";
    cin>>amount;

    unordered_map<int,int> dp;
    int mincoins = solv(amount,coins,dp);
    cout<<"the minimum no. of coins required to represent "<<amount<<" are : "<<mincoins<<endl<<endl;

    return 0;
}
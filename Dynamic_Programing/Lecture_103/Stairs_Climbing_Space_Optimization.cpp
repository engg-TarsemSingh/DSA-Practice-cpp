#include<iostream>
#include<vector>
using namespace std;

int mincost(vector<int>& cost){
    
    int zero = cost[0];
    int one = cost[1];

    for(int i=2 ; i<cost.size() ; i++){
        int temp = cost[i]+min(zero,one);
        zero = one;
        one = temp;
    }

    return min(zero,one);
}

int main(){
    int stairs;
    cout<<"enter the no. of atairs : ";
    cin>>stairs;
    vector<int> cost(stairs);
    for(int i=0 ; i<stairs ; i++){
        cin>>cost[i];
    }

    int result = mincost(cost);
    cout<<"minimum cost to climbing on top : "<<result<<endl;

    return 0;
}
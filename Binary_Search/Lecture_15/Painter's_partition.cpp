#include<iostream>
using namespace std;
#include<vector>

int sum(vector<int> &ans){
    int result = 0;
    for(int i:ans){
        result += i;
    }
    return result;
}

bool ispossible(vector<int> ans,int k,int mid){
    int current = 0;
    int i = 0;
    for(; i<ans.size() ; i++){
        if(current+ans[i]<=mid){
            current += ans[i];
        }
        else{
            current = ans[i];
            if(k<=0 || ans[i]>mid){
                return false;
            }
            k--;
        }
    }
    return true;
}

int allocated(vector<int> ans , int k){
    int result = -1;
    int start = 0;
    int end = sum(ans);
    int mid = start+(end-start)/2;
    while(start<=end){
        if(ispossible(ans,k,mid)){
            result = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
        mid = start+(end-start)/2;
    }
    return result;
}

int main(){
    vector<int> array = {5,5,5,5};
    int painters = 2;
    int ans = allocated(array,painters);
    cout<<"maximum boad allocated to a single painter == "<<ans<<endl;

    return 0;
}
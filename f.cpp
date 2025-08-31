#include<iostream>
#include<vector>
using namespace std;

bool backtrack(int leftsum , vector<int>& array , int rightsum , int index , int size){
    if(index==size){return false;}
    rightsum += array[index];
    leftsum -= array[index];


    if(leftsum==rightsum){return true;}
    cout<<"leftsum = "<<leftsum<<"          "<<"rightsum = "<<rightsum<<endl;
    bool ans1 = backtrack(leftsum,array,rightsum,index+1,size);


    rightsum -= array[index];
    leftsum += array[index];
    cout<<endl;
    cout<<"leftsum = "<<leftsum<<"          "<<"rightsum = "<<rightsum<<endl;
    bool ans2 = backtrack(leftsum,array,rightsum,index+1,size);


    return ans2||ans1;
}

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for(int& i : nums){
        sum += i;
    }
    return backtrack(sum,nums,0,0,nums.size());
}

int main(){
    vector<int> given = {14,9,8,4,3,2};
    bool ans = canPartition(given);
    cout<<"OUTPUT == "<<ans<<endl;
    return -1;
}
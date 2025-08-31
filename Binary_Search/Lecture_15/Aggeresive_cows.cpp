#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxi(vector<int> &distance){
    int max = INT_MIN;
    for(int i=0 ; i<distance.size() ; i++){
        if(distance[i]>max){
            max=distance[i];
        }
    }
    return max;

}

bool possible(vector<int> &distance , int cows , int mid){
    int last = distance[0];
    for(int i=0,c=1 ; i<distance.size() ; i++){
        if(distance[i]-last>=mid){
            c++;
            if(c==cows){
                return true;
            }
            last = distance[i];
        }
    }
    return false;
}

int agressive(vector<int> &distance , int cows){
    
    sort(distance.begin(),distance.end());
    int ans = -1;
    int start = 0;
    int end = maxi(distance);
    int mid = start+(end-start)/2;
    while(end>=start){
        if(possible(distance,cows,mid)){
            ans = mid;
            start = mid+1;
        }
        else{
            end = mid-1;
        }
        mid = start+(end-start)/2;
    }
    return ans;
}

int main(){
    vector<int> distance = {4,2,3,1,6};
    int cows = 2;
    cout<<"maximum minimum distance : "<<agressive(distance,cows)<<endl;

    return 0;
}
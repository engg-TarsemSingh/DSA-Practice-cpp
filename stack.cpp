#include<iostream>
#include<climits>
#include<vector>
using namespace std;

bool possible(pair<int,vector<int>>& current , int rupees){
    int onecoin = current.second[0];
    int twocoin = current.second[1];
    int fivecoin = current.second[2];

    for(int i=1 ; i<=rupees ; i++){
        int temp = i;
        for(int j=0 ; j<fivecoin && temp>=5 ; j++){
            temp -= 5;
        }
        for(int j=0 ; j<twocoin && temp>=2 ; j++){
            temp -= 2;
        }
        for(int j=0 ; j<onecoin && temp>=1 ; j++){
            temp--;
        }
        if(temp!=0){
            return false;
        }
    } 

    return true;
}

void solve(pair<int,vector<int>>& mincoin , int& rupees , pair<int,vector<int>> current = make_pair(0,vector<int>{0,0,0}) , int currentrupees=0){
    if(currentrupees>rupees){
        return;
    }
    if(currentrupees==rupees){
        if(possible(current,rupees)){
            if(mincoin.first>current.first){
                mincoin = current;
            }
        }
        return;
    }

    current.first += 1;

    current.second[0]++;
    solve(mincoin,rupees,current,currentrupees+1);
    current.second[0]--;

    current.second[1]++;
    solve(mincoin,rupees,current,currentrupees+2);
    current.second[1]--;

    current.second[2]++;
    solve(mincoin,rupees,current,currentrupees+5);
    current.second[2]--;
}

int main(){
    cout<<"enter the rupees : ";
    int rupees;
    cin>>rupees;

    pair<int,vector<int>> mincoin = make_pair(INT_MAX,vector<int>{0,0,0});

    solve(mincoin,rupees);

    cout<<mincoin.first<<" ";
    for(int i=0 ; i<3 ; i++){
        cout<<mincoin.second[i]<<" ";
    }
    cout<<endl;

    return 0;
}
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class graph{
    public:
    vector<vector<int>> gp;
    graph(){
        int size;
        cout<<"enter the number of nodes : ";
        cin>>size;
        gp.resize(size);
    }

    void insert(){
        cout<<"ENTER -1 TO END INSERTION"<<endl;
        while(true){
            int first , second;
            cout<<"Enter the value of first node = ";
            cin>>first;
            cout<<"Enter the value of second node = ";
            cin>>second;

            if(first==-1 || second==-1){
                break;
            }

            gp[first].push_back(second);
            gp[second].push_back(first);
        }
    }

    void print(){
        cout<<"----------PRINTING THE ADJENCY LIST----------"<<endl;
        for(int i=0 ; i<gp.size() ; i++){
            cout<<i<<" -> ";
            for(int j=0 ; j<gp[i].size() ; j++){
                cout<<gp[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void deleting(int a , int b){
        cout<<"DELETING LINK BETWEEN NODE : "<<a<<" AND : "<<b<<endl;
        for(int i=0 ; i<gp[a].size() ; i++){
            if(gp[a][i]==b){
                gp[a].erase(gp[a].begin()+i);
            }
        }
        for(int i=0 ; i<gp[b].size() ; i++){
            if(gp[b][i]==a){
                gp[b].erase(gp[b].begin()+i);
            }
        }
    }

    void breathfirstsearch(vector<bool>& visited , int index , bool& ans){
        vector<int> parent(gp.size(),-1);
        parent[index] = -1;
        visited[index] = true;
        queue<int> qu;
        qu.push(index);
        while(!qu.empty()){
            int current = qu.front();
            qu.pop();

            for(int i=0 ; i<gp[current].size() ; i++){
                if(visited[gp[current][i]]==true && gp[current][i]!=parent[current]){
                    ans = true;
                    return;
                }
                else if(visited[gp[current][i]]!=true){
                    qu.push(gp[current][i]);
                    visited[gp[current][i]] = true;
                    parent[gp[current][i]] = current;
                }
            }
        }
    }

    bool findloop(){
        bool ans = false;
        vector<bool> visited(gp.size(),false);
        for(int i=0 ; i<gp.size() ; i++){
            if(visited[i]==false){
                breathfirstsearch(visited,i,ans);
            }
            if(ans==true){
                return true;
            }
        }
        return ans;
    }
};

int main(){
    graph g;
    g.insert();
    g.print();
    // g.deleting(2,3);
    // g.print();

    bool isloop = g.findloop();
    if(isloop){
        cout<<"loop is present in graph"<<endl;
    }
    else{
        cout<<"loop is not present in graph"<<endl;
    }

    return 0;
}

// 0 1 1 2 3 4 4 5 5 7 7 6 7 8 6 4  -1 -1

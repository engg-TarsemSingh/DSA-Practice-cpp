#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

class graph{
    public:
    unordered_map<int,vector<int>> adjList;
    graph(){
        while(1){
            int first , second;
            cout<<"enter the value of first node than second node and press enter : ";
            cin>>first;
            cin>>second;
            if(first==-1 || second==-1){
                break;
            }
            adjList[first].push_back(second);
            adjList[second].push_back(first);
        }
    }

    void print(){
        cout<<"---------    PRINTING THE ADJACENCY LIST   ---------"<<endl;
        for(auto& i : adjList){
            cout<<i.first<<" -> ";
            for(int& j : i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

    vector<int> shortestpath(){
        int source , destination;
        cout<<"---------    FINDING SHORTEST PATH   ---------"<<endl;
        cout<<"enter source == ";
        cin>>source;
        cout<<"enter destination == ";
        cin>>destination;

        unordered_map<int,bool> visited;
        unordered_map<int,int> parent;
        queue<int> qu;

        qu.push(source);
        visited[source] = true;
        parent[source] = -1;
        while(!qu.empty()){
            int element = qu.front();
            qu.pop();

            for(int i=0 ; i<adjList[element].size() ; i++){
                if(visited[adjList[element][i]] != true){
                    qu.push(adjList[element][i]);
                    visited[adjList[element][i]] = true;
                    parent[adjList[element][i]] = element;
                }
            }
        }

        vector<int> ans;
        ans.push_back(destination);
        while(destination!=source){
            destination = parent[destination];
            ans.push_back(destination);
        }

        for(int i=0,j=ans.size()-1 ; i<j ; i++,j--){
            swap(ans[i],ans[j]);
        }
        return ans;
    }
};

void print(vector<int>& vect){
    cout<<"SHORTEST PATH :: "<<endl;
    for(int i=0 ; i<vect.size() ; i++){
        cout<<vect[i]<<" ";
    }
    cout<<endl;
}

int main(){
    graph g;
    g.print();

    vector<int> path = g.shortestpath();
    print(path);

    return 0;
}
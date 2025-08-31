#include<iostream>
#include<vector>
#include<climits>
#include<unordered_map>
using namespace std;

class graph{
    public:
    unordered_map<int,vector<pair<int,int>>> adjList;

    graph(){};

    graph(bool directed){
        cout<<"FIRST SECOND WEIGHT"<<endl;
        while(true){
            int first,second,weight;
            cin>>first;
            cin>>second;
            cin>>weight;

            if(first<0 || second<0){
                break;
            }

            adjList[first].push_back(make_pair(second,weight));
            if(!directed){
                adjList[second].push_back(make_pair(first,weight));
            }
        }
    }

    void print(){
        cout<<endl<<"----------     ADJANCENCY LIST     ----------"<<endl;
        for(auto& i : adjList){
            cout<<i.first<<" -> ";
            for(pair<int,int>& j : i.second){
                cout<<"{"<<j.first<<","<<j.second<<"}"<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    graph shortestSpanningTree(){
        
    }
};

int main(){
    graph g(0);
    g.print();

    graph tree = g.shortestSpanningTree();
    tree.print();

    return 0;
}
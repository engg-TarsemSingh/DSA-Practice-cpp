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
        vector<int> distance(adjList.size(),INT_MAX);
        vector<bool> included(adjList.size(),false);
        vector<int> parent(adjList.size(),-1);

        //starting node
        distance[0]=0;
        parent[0]=-1;

        for(int i=0 ; i<adjList.size() ; i++){
            //node with shortest distance
            int shortnode = -1;
            int shortdistance = INT_MAX;
            for(int i=0 ; i<distance.size() ; i++){
                if(distance[i]<shortdistance && included[i]==false){
                    shortdistance = distance[i];
                    shortnode = i;
                }
            }

            if(shortnode==-1) {break;}

            included[shortnode] = true;

            for(pair<int,int>& i : adjList[shortnode]){
                int child = i.first;
                int currentdistance = i.second;

                if(included[child]==false && currentdistance<distance[child]){
                    parent[child] = shortnode;
                    distance[child] = currentdistance;
                }
            }
        }

        graph ans;
        for(int i=1 ; i<parent.size() ; i++){
            int child = i;
            int node = parent[i];
            int weight = distance[i];
            ans.adjList[node].push_back(make_pair(child,weight));
            ans.adjList[child].push_back(make_pair(node,weight));
        }
        return ans;
    }
};

int main(){
    graph g(0);
    g.print();

    graph tree = g.shortestSpanningTree();
    tree.print();

    return 0;
}
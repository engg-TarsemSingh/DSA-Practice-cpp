#include<iostream>
#include<set>
#include<unordered_map>
#include<vector>
#include<climits>
using namespace std;

class GRAPH{
    public:
    unordered_map<int,vector<pair<int,int>>> adjList;
    GRAPH(bool directed){
        cout<<"FIRST SECOND WEIGHT"<<endl;
        while(true){
            int first,second,distance;
            cin>>first;
            cin>>second;
            cin>>distance;

            if(first<0 || second<0){
                break;
            }

            adjList[first].push_back(make_pair(second,distance));
            if(!directed){
                adjList[second].push_back(make_pair(first,distance));
            }
        }
    }

    void print(){
        cout<<"----------   ADJACENCY LIST  ----------"<<endl;
        for(auto& i : adjList){
            cout<<i.first<<" -> ";
            for(pair<int,int>& j : i.second){
                cout<<"{"<<j.first<<","<<j.second<<"}"<<" ";
            }
            cout<<endl;
        }
    }

    vector<int> shortestpath(int source){
        vector<int> distance(adjList.size(),INT_MAX);
        distance[source] = 0;

        set<pair<int,int>> st;
        st.insert(make_pair(0,source));
        while(!st.empty()){
            pair<int,int> current = *st.begin();
            st.erase(current);
            int currentdistance = current.first;
            int currentnode = current.second;
            for(pair<int,int> i : adjList[currentnode]){
                int childnodedistance = i.second;
                int childnode = i.first;
                if(distance[childnode]>childnodedistance+currentdistance){
                    auto it = st.find({distance[childnode],childnode});
                    if(it!=st.end()){
                        st.erase(it);
                    }
                    distance[childnode] = childnodedistance+currentdistance;
                    st.insert(make_pair(distance[childnode],childnode));
                }
            }
        }

        return distance;
    }

};

int main(){
    GRAPH g(0);
    g.print();

    int source;
    cout<<"enter the value of source node : ";
    cin>>source;

    vector<int> shortpath = g.shortestpath(source);

    cout<<"shortest path from "<<source<<" to other nodes "<<endl;
    for(int i=0 ; i<shortpath.size() ; i++){
        cout<<i<<" -> "<<shortpath[i];
        cout<<endl;
    }

    return 0;
}

// 0 1 5 0 2 8 1 2 9 2 3 6 1 3 2-1 4 5
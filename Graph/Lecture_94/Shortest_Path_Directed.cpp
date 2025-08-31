#include<iostream>
#include<map>
#include<unordered_map>
#include<climits>
#include<stack>
#include<vector>
using namespace std;

class graph{
    public:
    map<char,vector<pair<char,int>>> adjList;
    graph(bool directed){
        cout<<"#############    ENTER small TO QUIT    #############"<<endl;
        cout<<" FIRST   SECOND  WEIGHT"<<endl;
        while(1){
            char first,second;
            int third;
            cin>>first;
            cin>>second;
            cin>>third;

            if((first>='a' && first<='z') || (second>='a' && second<='z')){
                break;
            }

            adjList[first].push_back(make_pair(second,third));
            if(!directed){
                adjList[second].push_back(make_pair(first,third));
            }
        }
    }

    void print(){
        cout<<"----------------     PRINTING ADJACENCY LIST       -------------------"<<endl;
        for(auto& i : adjList){
            cout<<i.first<<" -> ";
            for(pair<char,int>& j : i.second){
                cout<<"{"<<j.first<<","<<j.second<<"}"<<" ";
            }
            cout<<endl;
        }
    }

    void deapthfirstsearch(unordered_map<char,bool>& visited , stack<char>& st , char currentnode){
        visited[currentnode]=true;
        for(int i=0 ; i<adjList[currentnode].size() ; i++){
            if(visited[adjList[currentnode][i].first]==false){
                deapthfirstsearch(visited,st,adjList[currentnode][i].first);
            }
        }
        st.push(currentnode);
    }

    vector<char> topologicalsort(){
        stack<char> st;
        unordered_map<char,bool> visited;
        for(auto& i : adjList){
            visited[i.first]=false;
        }

        for(auto& i : adjList){
            if(visited[i.first]==true){
                continue;
            }
            deapthfirstsearch(visited,st,i.first);
        }

        vector<char> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }

    map<char,int> shortpath(){
        vector<char> topological = topologicalsort();

        char source;
        cout<<"enter the source node : ";
        cin>>source;

        //make a distence vector which represent distence of each node fron source
        map<char,int> distance;
        for(int i=0 ; i<topological.size() ; i++){
            distance[topological[i]]=INT_MAX;
        }

        //make the distance from source to source 0
        distance[source] = 0;

        //find the distance of other nodes fron source
        for(auto& i : distance){
            if(i.second!=INT_MAX){
                //find adjecent nodes and their weight
                for(auto& j : adjList[i.first]){
                    char adjecentnode = j.first;
                    int weight = j.second;
                    //if weight of adjecent node id more than weight to reach parent and parent to adjecent node
                    if(distance[adjecentnode]>(distance[i.first]+weight)){
                        distance[adjecentnode] = distance[i.first]+weight;
                    }
                }
            }
        }

        return distance;
    }
};

int main(){
    graph g(1);
    g.print();

    map<char,int> shortestpath = g.shortpath();

    cout<<"SHORTEST PATH : ";
    for(auto& i : shortestpath){
        cout<<"{"<<i.first<<","<<i.second<<"}"<<"  ";
    }
    cout<<endl;

    return 0;
}

// A B 5A C 5B D 10C E 20B E 7C D 30 D F 50E F 20a b 4
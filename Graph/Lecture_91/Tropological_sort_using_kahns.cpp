#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

class graph{
    public:
    vector<vector<int>> gp;
    bool directed;
    graph(int nodes , bool dir){
        this->directed = dir;
        gp.resize(nodes);
    }

    void insert(){
        cout<<"-------enter negative number to end loop-----"<<endl;
        while(true){
            int first , second;
            cin>>first>>second;
            if(first<0 || second<0){
                break;
            }

            gp[first].push_back(second);
            if(!directed){
                gp[second].push_back(first);
            }
        }
    }

    void print(){
        cout<<"--------ADJENCY LIST OF GRAPH IS GIVEN BELOW---------"<<endl;
        for(int i=0 ; i<gp.size() ; i++){
            cout<<i<<" -> ";
            for(int j : gp[i]){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

    vector<int> findindegree(){
        vector<int> ans(gp.size());
        
        for(int i=0 ; i<gp.size() ; i++){
            int degree=0;
            for(vector<int>& j : gp){
                for(int& k : j){
                    if(k==i){
                        degree++;
                    }
                }
            }
            ans[i]=degree;
        }

        return ans;
    }

    void BreathFirstSearch(vector<int>& sort , vector<int>& indegree , vector<bool>& visited , int currentnode){
        queue<int> qu;
        visited[currentnode]=true;
        qu.push(currentnode);

        while(!qu.empty()){
            int element = qu.front();
            sort.push_back(element);
            qu.pop();

            for(int i=0 ; i<gp[element].size() ; i++){
                int currentchild = gp[element][i];
                indegree[currentchild]--;
                if(indegree[currentchild]==0 && visited[currentchild]==false){
                    qu.push(currentchild);
                    visited[currentchild]=true;
                }
            }
        }
    }

    vector<int> tropologicalsort(){
        vector<int> indegree = findindegree();
        vector<bool> visited(gp.size(),false);
        vector<int> sort;
        for(int i=0 ; i<indegree.size() ; i++){
            if(indegree[i]==0 && visited[i]==false){
                BreathFirstSearch(sort,indegree,visited,i);
            }
        }
        return sort;
    }
};

int main(){
    graph g(5,1);

    g.insert();
    g.print();

    vector<int> sort = g.tropologicalsort();
    cout<<"TROPOLOGICAL SORT : ";
    for(int& i : sort){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}
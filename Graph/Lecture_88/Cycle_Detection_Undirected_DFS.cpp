#include<iostream>
#include<vector>
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

    void deapthfirstsearch (vector<bool>& visited , vector<int>& parent , bool& ans , int currentnode){
        for(int i=0 ; i<gp[currentnode].size() ; i++){
            if(visited[gp[currentnode][i]]==true && gp[currentnode][i]!=parent[currentnode]){
                ans = true;
                break;
            }
            else if(visited[gp[currentnode][i]]==false){
                parent[gp[currentnode][i]] = currentnode;
                visited[gp[currentnode][i]] = true;
                deapthfirstsearch(visited,parent,ans,gp[currentnode][i]);
            }
        }     
    }

    bool loopdetection(){
        vector<bool> visited(gp.size(),false);
        vector<int> parent(gp.size());
        bool ans = false;
        for(int i=0 ; i<gp.size() ; i++){
            if(ans==true) {break;}
            if(visited[i]!=true){
                parent[i] = -1;
                visited[i] = true;
                deapthfirstsearch(visited,parent,ans,i);
            }
        }
        return ans;
    }
};

int main(){
    graph g(5,0);

    g.insert();
    g.print();

    if(g.loopdetection()){
        cout<<"THERE IS A LOOP PRESENT IN GRAPH"<<endl;
    }
    else{
        cout<<"THERE IS NO LOOP PRESENT IN GRAPH"<<endl;
    }

    return 0;
}
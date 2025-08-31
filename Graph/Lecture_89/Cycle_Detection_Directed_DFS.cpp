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

    void deapthfirstsearch(vector<bool>& visited , vector<bool> tempvisited , int& ans , int currentnode){
        visited[currentnode]=true;
        tempvisited[currentnode]=true;
        for(int i=0 ; i<gp[currentnode].size() ; i++){
            if(visited[gp[currentnode][i]]==true && tempvisited[gp[currentnode][i]]==true){
                ans = true;
                break;
            }
            else if(tempvisited[gp[currentnode][i]]==false){
                deapthfirstsearch(visited,tempvisited,ans,gp[currentnode][i]);
            }
        }
    }

    bool cycledetect(){
        vector<bool> visited(gp.size(),false);
        vector<bool> tempvisited(gp.size(),false);
        int ans = false;
        for(int i=0 ; i<gp.size() ; i++){
            if(ans==true) {break;}
            if(visited[i]!=true){
                deapthfirstsearch(visited,tempvisited,ans,i);
            }
        }
        return ans;
    }
};

int main(){
    graph g(5,1);

    g.insert();
    g.print();

    if(g.cycledetect()){
        cout<<"THERE IS A CYCLE PRESENT IN GRAPH"<<endl;
    }
    else{
        cout<<"NO CYCLE PRESENT IN GRAPH"<<endl;
    }

    return 0;
}
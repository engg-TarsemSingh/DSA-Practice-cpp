#include<iostream>
#include<vector>
#include<stack>
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

    void deapthfirstsearch(vector<bool>& visited , stack<int>& st , int currentnode){
        visited[currentnode] = true;
        for(int i=0 ; i<gp[currentnode].size() ; i++){
            if(visited[gp[currentnode][i]]==false){
                deapthfirstsearch(visited,st,gp[currentnode][i]);
                st.push(gp[currentnode][i]);
            }
        }
    }

    vector<int> tropological_sort(){
        vector<bool> visited(gp.size(),false);
        stack<int> st;
        for(int i=0 ; i<gp.size() ; i++){
            if(visited[i]==false){
                deapthfirstsearch(visited,st,i);
                st.push(i);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

int main(){
    graph g(5,1);

    g.insert();
    g.print();

    vector<int> sort = g.tropological_sort();
    cout<<"TROPOLOGICAL SORT --- ";
    for(int& i : sort){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}
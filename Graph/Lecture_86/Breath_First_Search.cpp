#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;

class graph{
    public:
    unordered_map<char,list<char>> adjlist;
    int isdirectional;
    int nodes;
    graph(int nodes , bool ss){
        this->nodes = nodes;
        this->isdirectional = ss;
        for(int i=0 ; i<nodes ; i++){
            char nod;
            cout<<" enter "<<i+1<<" th node : ";
            cin>>nod;
            adjlist[nod];
        }
    }

    void insert(){
        while(true){
            char first , second;
            cout<<"enter the first node of edge : ";
            cin>>first;
            cout<<"enter the second node of edge: ";
            cin>>second;
            
            cout<<endl<<endl;

            if(first=='a' || second=='a'){
                break;
            }

            adjlist[first].push_back(second);
            if(!isdirectional){
                adjlist[second].push_back(first);
            }
        }
    }

    void print(){
        cout<<"-------PRINTING ADJENCYLIST--------"<<endl;
        for(auto i : adjlist){
            cout<<i.first<<" -> ";
            for(auto j : i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    void Breath_First_Search(char starting){
        cout<<"------BREATH FIRST SEARCH------"<<endl;
        unordered_map<char,bool> visited;
        for(auto i : adjlist){
            visited[i.first] = false;
        }

        queue<char> qu;
        qu.push(starting);
        visited[starting] = true;
        while(!qu.empty()){
            char front = qu.front();
            cout<<front<<" ";
            qu.pop();
            for(auto i : adjlist[front]){
                if(visited[i] == false){
                    qu.push(i);
                    visited[i] = true;
                }
            }
        }
        cout<<endl;
    }
};

int main(){
    graph g1(5,1);
    g1.insert();
    g1.print();
    
    char starting;
    cout<<"enter the starting character : "<<endl;
    cin>>starting;
    g1.Breath_First_Search(starting);

    return 0;
}

// A B C D E A C A D D B B E C B C D a A
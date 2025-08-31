#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class graph{
    public:
    unordered_map<char,list<char>> adjlist;
    bool flag;
    graph(bool flag){
        this->flag = flag;
    }

    void insert(char a , char b){
        adjlist[a].push_back(b);
        if(flag){
            adjlist[b].push_back(a);
        }
    }

    void create(){
        int nodes ;
        cout<<"enter the number of nodes : ";
        cin>>nodes;
        for(int i=0 ; i<nodes ; i++){
            char temp;
            cout<<"enter "<<i+1<<"th node = ";
            cin>>temp;
            for(int i=0 ; i>-1 ; i++){
                char edge;
                cout<<"for "<<temp<<" node enter the "<<i+1<<" th edge : ";
                cin>>edge;
                if(edge=='a'){
                    break;
                }
                insert(temp,edge);
            }
        }
    }

    void print(){
        cout<<"printng the adjecency list "<<endl;
        for(auto i : adjlist){
            cout<<i.first<<" -> ";
            for(auto j : i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};

int main(){
    graph g1(0);
    g1.create();
    g1.print();

    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

class graph{
    public:
    vector<vector<int>> adjmetrix;
    int vertix;
    bool isdirectional;
    graph(int vertix , bool isdirectional){
        this->vertix = vertix;
        this->isdirectional = isdirectional;
        for(int i=0 ; i<vertix ; i++){
            vector<int> row(vertix,0);
            adjmetrix.push_back(row);
        }
    }

    void insert(){
        int a,b;
        do{
            cout<<"enter the value of first node : ";
            cin>>a;
            cout<<"enter the value of second node : ";
            cin>>b;
            if(a==-1 || b==-1){
                break;
            }
            adjmetrix[a][b] = 1;
            if(!isdirectional){
                adjmetrix[b][a] = 1;
            }
        }while(true);
    }

    void print(){
        cout<<endl;
        cout<<"-----------ADJENCYMETRIX-----------"<<endl;
        for(int i=0 ; i<vertix ; i++){
            cout<<"            ";
            for(int j=0 ; j<vertix ; j++){
                cout<<adjmetrix[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
};

int main(){
    graph g1(5,0);
    g1.insert();
    g1.print();

    return 0;
}
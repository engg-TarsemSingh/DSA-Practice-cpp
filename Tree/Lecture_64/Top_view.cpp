#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* createtree(Node* root){
    int data;
    if(root==nullptr){
        cout<<"enter the root node data : ";
        cin>>data;
    }
    else{
        cout<<"Data -> "<<data;
    }

    if(data==-1){
        return nullptr;
    }

    root = new Node(data);

    cout<<"enter the data for left of "<<root->data<<endl;
    root->left = createtree(root->left);
    cout<<"enter the data for right of "<<root->data<<endl;
    root->right = createtree(root->right);

    return root;
}

void printlist(vector<pair<int,int>> giv){
    sort(giv.begin(),giv.end());
    for(auto i : giv){
        cout<<i.second<<" ";
    }
    cout<<endl;
}

vector<pair<int,int>> Top_View(Node* root){
    vector<pair<int,int>> ans;
    queue<pair<int,pair<int,Node*>>> qu;
    qu.push(make_pair(0,make_pair(0,root)));

    while(!qu.empty()){
        int distance = qu.front().first;
        int level = qu.front().second.first;
        Node* node = qu.front().second.second;

        bool flag = true;
        for(int i=0 ; i<ans.size() ; i++){
            if(distance==ans[i].first){
                flag = false;
            }
        }

        if(flag == true){
            ans.push_back(make_pair(distance,node->data));
        }

        if(node->left!=nullptr){
            qu.push(make_pair(distance-1,make_pair(level+1,node->left)));
        }
        if(node->right!=nullptr){
            qu.push(make_pair(distance+1,make_pair(level+1,node->right)));
        }

        qu.pop();
    }
    return ans;
}

int main(){
    Node* Root = nullptr;
    Root  = createtree(Root);
    vector<pair<int,int>> ans = Top_View(Root);
    printlist(ans); 
    return 0;
}
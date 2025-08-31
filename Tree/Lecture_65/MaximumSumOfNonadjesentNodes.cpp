#include<iostream>
#include<vector>
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

Node* createtree(){
    int data;
    cout<<"enter data : ";
    cin>>data;

    if(data==-1){
        return nullptr;
    }

    Node* node = new Node(data);

    cout<<"------Left of "<<data<<endl;
    node->left = createtree();

    cout<<"------Right of "<<data<<endl;
    node->right = createtree();

    return node;
}

pair<int,int> solve(Node* root , bool flag=true){
    if(root==nullptr) { return make_pair(0,0); }

    pair<int,int> left = solve(root->left,!flag);
    pair<int,int> right = solve(root->right,!flag);

    pair<int,int> ans = make_pair(left.first+right.first,left.second+right.second);
    if(flag){
        ans.first += root->data;
    }
    else{
        ans.second += root->data;
    }

    return ans;
}

int main(){
    Node* root = createtree();
    pair<int,int> Maxsum = solve(root);
    cout<<"Maximum Sum Of Non-Adjecent Nodes == "<<max(Maxsum.first,Maxsum.second)<<endl;

    return 0;
}
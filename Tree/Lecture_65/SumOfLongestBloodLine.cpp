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

pair<int,int> solve(Node* root , pair<int,int> current=make_pair(1,0) , pair<int,int> ans=make_pair(0,0)){

    if(current.first>ans.first){
        ans = current;
    }

    pair<int,int> left,right;
    
    if(root->left==nullptr){
        left = current;
    }
    else{
        left = solve(root->left,make_pair(current.first+1,current.second+root->data),ans);
    }

    if(root->right==nullptr){
        right = current;
    }
    else{    
        right = solve(root->right,make_pair(current.first+1,current.second+root->data),ans);
    }

    if(left.first>right.first){
        ans = left;
    }
    else if(left.first<right.first){
        ans = right;
    }
    else{
        ans = (left.second>right.second) ? left : right ;
    }

    return ans;
}

int main(){
    Node* root = createtree();
    pair<int,int> ans = solve(root);
    cout<<"maximum length : "<<ans.first<<endl;
    cout<<"maximum sum : "<<ans.second<<endl;
    return 0;
}
#include<iostream>
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

Node* buildTree(Node* root){
    cout<<"enter the value ==== ";
    int data;
    cin>>data;
    if(data==-1){
        return nullptr;
    }

    root = new Node(data);

    cout<<"enter at left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"enter at right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

int height(Node* node){
    if(node==nullptr){
        return 0;
    }

    int left = height(node->left);
    int right = height(node->right);

    return max(right,left)+1;
}

bool is_balance(Node* root){
    if(root==nullptr){
        return true;
    }
    
    bool l = is_balance(root->left);
    bool r = is_balance(root->right);
    int left = height(root->left);
    int right = height(root->right);

    bool difference = (abs(left-right)<=1) ? true : false ;

    if(difference && l && r){
        return true;
    }
    return false;
}

//optimize solution
pair<bool,int> isBalance(Node* root){
    if(root==nullptr){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    pair<bool,int> l = isBalance(root->left);
    pair<bool,int> r = isBalance(root->right);

    pair<bool,int> ans;
    ans.first = (abs(l.second-r.second)<=1) && l.first && r.first;
    ans.second = max(l.second,r.second)+1;

    return ans;
}

int main(){
    Node* root = buildTree(nullptr);
    cout<<"given tree is balance tree : "<<is_balance(root)<<endl;
    cout<<"given tree is balance tree : "<<isBalance(root).first<<endl;
    return 0;
}
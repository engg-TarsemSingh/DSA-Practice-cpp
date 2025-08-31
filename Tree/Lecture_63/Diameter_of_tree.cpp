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

    return max(left,right)+1;
}

int diameter(Node* root){

    if(root==nullptr){
        return 0;
    }

    //if maximum distance between nodes is in left sub tree
    int left_tree = diameter(root->left);

    //if maximum distance between nodes is in right sub tree
    int right_tree = diameter(root->right);

    //if maximum diatance is between left and right sub tree nodes
    int left_most_node = height(root->left);
    int right_most_node = height(root->right);
    int combo = left_most_node+right_most_node+1;

    return max(left_tree,max(right_tree,combo));
}

//optimize solution
pair<int,int> diameter_(Node* root){
    if(root==nullptr){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    //if maximum distance between nodes is in left sub tree
    pair<int,int> l = diameter_(root->left);
    int left_tree = l.first;

    //if maximum distance between nodes is in right sub tree
    pair<int,int> r = diameter_(root->right);
    int right_tree = r.first;

    //if maximum diatance is between left and right sub tree nodes
    int combo = r.second+l.second+1;

    pair<int,int> ans;
    ans.first = max(left_tree,max(right_tree,combo));
    ans.second = max(l.second,r.second)+1;
    return ans;
}

int main(){
    Node* root = buildTree(nullptr);
    cout<<"diameter_ of given tree : "<<diameter_(root).first<<endl;
    cout<<"diameter of given tree : "<<diameter(root)<<endl;
    return 0;
}
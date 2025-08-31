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

    Node* new_node = new Node(data);

    cout<<"enter at left of "<<data<<endl;
    new_node->left = buildTree(new_node->left);
    cout<<"enter at right of "<<data<<endl;
    new_node->right = buildTree(new_node->right);

    return root;
}

int main(){
    Node* root = nullptr;
    root = buildTree(root);

    return 0;
}
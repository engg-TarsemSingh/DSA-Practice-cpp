#include<iostream>
#include<queue>
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

void InOrder_Travesal(Node* root){
    if(root == nullptr){
        return;
    }

    InOrder_Travesal(root->left);
    cout<<root->data<<" ";
    InOrder_Travesal(root->right);
}

void PreOrder_Travesal(Node* root){
    if(root == nullptr){
        return;
    }

    cout<<root->data<<" ";
    InOrder_Travesal(root->left);
    InOrder_Travesal(root->right);
}

void PostOrder_Travesal(Node* root){
    if(root == nullptr){
        return;
    }

    InOrder_Travesal(root->left);
    InOrder_Travesal(root->right);
    cout<<root->data<<" ";
}

int main(){
    Node* root = nullptr;
    root = buildTree(root);
    cout<<"InOrder Travesal : ";
    InOrder_Travesal(root);
    cout<<endl;

    cout<<"PreOrder Travesal : ";
    PreOrder_Travesal(root);
    cout<<endl;

    cout<<"PostOrder Travesal : ";
    PostOrder_Travesal(root);
    cout<<endl;

    return 0;
}
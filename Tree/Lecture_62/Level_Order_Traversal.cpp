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

void Level_traversal(Node* root){
    queue<Node*> qu;
    qu.push(root);
    qu.push(NULL);

    while(!qu.empty()){
        Node* temp = qu.front();
        qu.pop();

        if(temp==NULL){
            cout<<endl;
            if(!qu.empty()){
                qu.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left!=nullptr){
                qu.push(temp->left);
            }
            if(temp->right!=nullptr){
                qu.push(temp->right);
            }
        }
    }
}

int main(){
    Node* root = nullptr;
    root = buildTree(root);
    Level_traversal(root);

    return 0;
}
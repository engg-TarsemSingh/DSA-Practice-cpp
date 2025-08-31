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

void printlist(Node* given){
    while(given!=nullptr){
        cout<<given->data<<" ";
        given = given->right;
    }
    cout<<endl;
}

void preordertraversal(Node* root , vector<Node*>& array){
    if(root==nullptr) {return;}

    array.push_back(root);
    preordertraversal(root->left,array);
    preordertraversal(root->right,array);
}

void printvector(vector<Node*> array){
    for(int i=0 ; i<array.size() ;i++){
        cout<<array[i]->data<<" ";
    }
    cout<<endl;
}

void flatten(Node* root){
    vector<Node*> preorder;
    preordertraversal(root,preorder);
    cout<<"printing preorder array : ";
    printvector(preorder);

    Node* temp = root;
    for(int i=0 ; i<preorder.size()-1 ; i++){
        cout<<"value of i = "<<i<<endl;
        cout<<"current element of vector = "<<preorder[i]->data<<endl;
        temp->left = nullptr;
        temp->data = preorder[i]->data;
        temp->right = preorder[i+1];
        temp = temp->right;
    }
}

void flattened(Node* root){
    vector<Node*> preorder;
    preordertraversal(root,preorder);

    for(int i=0 ; i<preorder.size()-1 ; i++){
        preorder[i]->left = nullptr;
        preorder[i]->right = preorder[i+1];
    }

    root = preorder[0];
}

int main(){
    Node* root = buildTree(nullptr);
    flattened(root);
    cout<<"linked list : ";
    printlist(root);

    return 0;
}
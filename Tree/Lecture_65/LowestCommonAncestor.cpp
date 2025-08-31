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

int solve(Node* root,int first , int second ){
    if(root==nullptr){
        return -1;
    }
    if(root->data==first){
        return 0;
    }
    if(root->data==second){
        return 0;
    }

    int fir = solve(root->left,first,second);
    int sec = solve(root->right,first,second);

    if(fir==0 && sec==0){
        return root->data;
    }
    else if(fir==0 || sec==0){
        return 0;
    }

    return -1;
}

int main(){
    Node* root = createtree();
    int first,second;
    cout<<"enter first value : ";
    cin>>first;
    cout<<"enter second value : ";
    cin>>second;
    int leastcommon = solve(root,first,second);
    cout<<"Least common Ancestor of this tree = "<<leastcommon<<endl;
    return 0;
}
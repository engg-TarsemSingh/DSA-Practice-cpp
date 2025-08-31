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

Node* tree(){
    queue<Node*> que;
    cout<<"enter data for root : ";
    int data;
    cin>>data;
    if(data==-1) {return nullptr;}
    Node* root = new Node(data);
    que.push(root);

    while(!que.empty()){
        Node* temp = que.front();
        que.pop();

        cout<<"enter dta for left child of "<<temp->data<<"  : ";
        cin>>data;
        if(data!=-1){
            temp->left = new Node(data);
            que.push(temp->left);
        }

        cout<<"enter dta for right child of "<<temp->data<<"  : ";
        cin>>data;
        if(data!=-1){
            temp->right = new Node(data);
            que.push(temp->right);
        }
    }

    return root;
}

void LevelOrderTraversal(Node* root){
    queue<Node*> qu;
    qu.push(root);
    qu.push(nullptr);
    while(!qu.empty()){
        Node* temp = qu.front();
        qu.pop();
        if(temp==nullptr){
            cout<<endl;
            if(!qu.empty()){
                qu.push(nullptr);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left!=nullptr)  qu.push(temp->left);
            if(temp->right!=nullptr)  qu.push(temp->right);
        }
    }
}

int main(){
    Node* root = tree();
    LevelOrderTraversal(root);
    return 0;
}
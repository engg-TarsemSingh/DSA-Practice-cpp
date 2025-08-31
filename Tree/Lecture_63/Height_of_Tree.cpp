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

int Height(Node* root){
    if(root==nullptr){
        return 0;
    }

    int left_height = Height(root->left);
    int right_height = Height(root->right);

    return max(left_height,right_height)+1;
}

int main(){
    Node* root = tree();
    int height = Height(root);
    cout<<"Height of given tree : "<<height<<endl;
    return 0;
}
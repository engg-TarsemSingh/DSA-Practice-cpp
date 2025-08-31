#include<iostream>
#include<stack>
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

Node* tree(Node* root){
    cout<<"enter the value : ";
    int data;
    cin>>data;
    if(data==-1){
        return nullptr;
    }

    root = new Node(data);

    cout<<"enter value of left child of "<<root->data<<endl;
    root->left = tree(root->left);
    cout<<"enter value of right child of "<<root->data<<endl;
    root->right = tree(root->right);

    return root;
}

void PreOrder(Node* root){
    cout<<"      PRE-ORDER TRAVERSAL"<<endl;
    stack<Node*> stak;
    stak.push(root);
    cout<<root->data<<" ";
    while(!stak.empty()){
        Node* top = stak.top();
        
        //rech left most node
        while(top->left != nullptr){
            top = top->left;
            cout<<top->data<<" ";
            stak.push(top);
        }
        stak.pop();

        if(!stak.empty()){
            stak.top()->left = nullptr;
        }

        //checking if left most node has right child
        if(top->right != nullptr) { stak.push(top->right); cout<<top->right->data<<" "; }
    }
}

int main(){
    Node* root = nullptr;
    root = tree(root);

    PreOrder(root);

    return 0;
}


// 10 5 0 -1 -1 1 -1 -1 50 40 -1 -1 30 15 -1 -1 20 -1 -1
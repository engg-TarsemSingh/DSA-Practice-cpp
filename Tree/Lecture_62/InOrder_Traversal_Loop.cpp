#include<iostream>
#include<vector>
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

void InOrder(Node* root){
    cout<<"      IN-ORDER TRAVERSAL"<<endl;
    vector<Node*> ans;
    stack<Node*> stak;
    stak.push(root);
    while(!stak.empty()){
        Node* top = stak.top();

        //finding left most node
        while(top->left!=nullptr){
            top = top->left;
            stak.push(top);
        }
        ans.push_back(top);
        cout<<top->data<<" ";
        stak.pop();

        //if stack is not empty
        if(!stak.empty()){
            stak.top()->left = nullptr;
        }

        //if there are elements on right side of left most node
        if(top->right!=nullptr){
            stak.push(top->right);
        }

    }
}

int main(){
    Node* root = nullptr;
    root = tree(root);

    InOrder(root);

    return 0;
}
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node {
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

Node* create_tree(Node* root){
    cout<<"enter data = ";
    int data;
    cin>>data;
    if(data==-1){
        return nullptr;
    }

    root = new Node(data);
    cout<<"enter the value of left child of "<<root->data<<endl;
    root->left = create_tree(root->left);
    cout<<"enter the value of right child of "<<root->data<<endl;
    root->right = create_tree(root->right);

    return root;
}

void reverse_level_order_traversal(Node* root){
    cout<<"########################################"<<endl;
    queue<Node*> qu;
    stack<Node*> st;
    qu.push(root);
    qu.push(nullptr);
    while(!qu.empty()){
        Node* temp = qu.front();
        qu.pop();
        if(temp!=nullptr){
            if(temp->right) {qu.push(temp->right);}
            if(temp->left) {qu.push(temp->left);}
        }
        else{
            if(!qu.empty()){
                qu.push(nullptr);
            }
        }
        st.push(temp);
    }

    while(!st.empty()){
        Node* temp = st.top();
        st.pop();
        if(temp!=nullptr){
            cout<<temp->data<<" ";
        }
        else{
            cout<<endl;
        }
    }
    cout<<endl;
    cout<<"########################################"<<endl;
}

int main(){
    Node* root = nullptr;
    cout<<"***************************************"<<endl<<endl;
    root = create_tree(root);
    cout<<endl<<endl;
    cout<<"***************************************"<<endl<<endl;
    reverse_level_order_traversal(root);

    return 0;
}
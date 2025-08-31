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
    cout<<"enter value : ";
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

void PostOrder(Node* root){
    cout<<"       POST-ORDER TRAVERSAL"<<endl;
    stack<Node*> stak;
    Node* current = root;
    Node* last = nullptr;
    while(!stak.empty() || current!=nullptr){
        if(current!=nullptr){
            stak.push(current);
            current = current->left;
        }
        else{
            Node* temp = stak.top();
            if(temp->right!=nullptr && last!=temp->right){
                current = temp->right;
            }
            else{
                cout<<temp->data<<" ";
                stak.pop();
                last = temp;
            }
        }
    }
}

int main(){
    Node* root = nullptr;
    root = tree(root);

    PostOrder(root);

    return 0;
}
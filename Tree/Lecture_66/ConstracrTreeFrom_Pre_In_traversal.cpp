#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->left = nullptr;
        this->right = nullptr;
        this->data = data;
    }
};

void printtree(Node* root){
    cout<<"-----------------LEVEL ORDER TRAVERSAL-------------------"<<endl;
    queue<Node*> qu;
    qu.push(root);
    qu.push(nullptr);
    while(!qu.empty()){
        Node* current = qu.front();
        qu.pop();
        if(current==nullptr){
            cout<<endl;
            if(!qu.empty()) { qu.push(nullptr); }
            continue;
        }

        cout<<current->data<<" ";

        if(current->left!=nullptr){
            qu.push(current->left);
        }
        if(current->right!=nullptr){
            qu.push(current->right);
        }
    }
}

Node* createtree(vector<int>& inorder , vector<int>& preorder , int start , int end , int index){
    if(start<end){
        return nullptr;
    }

    int index = 0;
    for(int i=start , i<=end , i++){
        if(preorder[start]==inorder[i]){
            break;
        }
        index++;
    }

    Node* root = createtree(preorder[index]);

    index++;

    root->left = createtree(inorder,preorder,start,index)
}

int main(){
    vector<int> inorder = {0,10,5,20,15,30,35,40,50};
    vector<int> preorder = {30,20,10,0,5,15,40,35,50};
    int size = inorder.size();

    Node* root = createtree(inorder,preorder,0,size-1,0);

    printtree(root);
    return 0;
}
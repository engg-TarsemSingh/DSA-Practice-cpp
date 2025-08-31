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
        this->left = this->right = nullptr;
    }
};

Node* buildtree(){
    int data;
    cout<<"data : ";
    cin>>data;

    if(data==-1){
        return nullptr;
    }

    Node* root = new Node(data);

    cout<<"--------------LEFT OF "<<data<<endl;
    root->left = buildtree();
    cout<<"--------------RIGHT OF "<<data<<endl;
    root->right = buildtree();

    return root;
}

void postordertraversal(Node* root){
    if(root==nullptr) {return;}
    
    postordertraversal(root->left);
    postordertraversal(root->right);
    cout<<root->data<<" ";
}

void inordertraversal(Node* root){
    if(root==nullptr) {return;}

    inordertraversal(root->left);
    cout<<root->data<<" ";
    inordertraversal(root->right);
}

void inordertraversall(Node* root , vector<int>& arr){
    if(root==nullptr){
        return;
    }
    
    inordertraversall(root->left,arr);
    arr.push_back(root->data);
    inordertraversall(root->right,arr);
}

void preordertraversall(Node* root , vector<int>& inorder , int& index){
    if(root==nullptr) {return;}
    
    root->data = inorder[index];
    index++;
    preordertraversall(root->left,inorder,index);
    preordertraversall(root->right,inorder,index);
}

void printvector(vector<int> array){
    for(int i=0 ; i<array.size() ; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

void converttoheap(Node* root){
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
    vector<int> inorder;

    inordertraversall(root,inorder);
    cout<<"inorder array = ";
    printvector(inorder);
    
    for(int i=0,j=inorder.size()-1 ; i<j ; i++,j--){
        swap(inorder[i],inorder[j]);
    }

    cout<<"inorder array after reversal = ";
    printvector(inorder);

    int index = 0;
    preordertraversall(root,inorder,index);
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
}

int main(){
    Node* root = buildtree();
    cout<<"inorder traversal of BST = ";
    inordertraversal(root);
    cout<<endl;

    converttoheap(root);
    cout<<"postorder traversal of HEAP = ";
    postordertraversal(root);
    cout<<endl;

    return 0;
}
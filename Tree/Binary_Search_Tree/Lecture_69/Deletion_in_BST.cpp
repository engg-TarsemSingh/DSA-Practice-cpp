#include<iostream>
#include<vector>
using namespace std;

vector<int> createarray(){
    vector<int> array;
    cout<<"--------------------ENTER -1 TO EXIT ------------------"<<endl;
    int data = 0;
    while(true){
        cout<<"enter value : ";
        cin>>data;
        if(data==-1) {return array;}
        array.push_back(data);
    }
    return array;
}

void printarray(vector<int>& given){
    for(int i=0 ; i<given.size() ; i++){
        cout<<given[i]<<" ";
    }
    cout<<endl;
}

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

Node* insertintoBST(Node* root , int data){
    if(root==nullptr){
        return new Node(data);
    }

    if(root->data>data){
        root->left = insertintoBST(root->left,data);
    }
    else{
        root->right = insertintoBST(root->right,data);
    }

    return root;
}

Node* createBST(vector<int> array){
    int size = array.size();
    Node* root=nullptr;
    if(size==0) {return nullptr;}
    
    for(int i=0 ; i<size ; i++){
        root = insertintoBST(root,array[i]);
    }

    return root;
}

void preordertraversal(Node* root){
    if(root==nullptr) {return;}

    cout<<root->data<<" ";

    preordertraversal(root->left);
    preordertraversal(root->right);
}

Node* minimum(Node* root){
    if(root->left==nullptr){
        return root;
    }
    
    return minimum(root->left);
}

Node* deletefromBST(Node* root , int data){
    if(root==nullptr) {return nullptr;}
    else if((root->data)==data){
        if((root->left)==nullptr && (root->right)==nullptr) {delete root; return nullptr;}
        else if((root->left)!=nullptr && (root->right)==nullptr) {Node* temp=root->left; delete root; return temp;}
        else if((root->left)==nullptr && (root->right)!=nullptr) {Node* temp=root->right; delete root; return temp;}
        else{
            Node* root_left_min = minimum(root->right);
            root->data = root_left_min->data;
            root->right = deletefromBST(root->right,root->data);
            return root;
        }
    }
    else if((root->data)>data){
        root->left = deletefromBST(root->left,data);
    }
    else{
        root->right = deletefromBST(root->right,data);
    }
    return root;
}

int main(){
    vector<int> array = createarray();
    cout<<"print array === ";
    printarray(array);

    Node* BST = createBST(array);

    cout<<"preorder traversal : ";
    preordertraversal(BST);
    cout<<endl;

    int element;
    cout<<"enter the element you want to delete : ";
    cin>>element;
    BST = deletefromBST(BST,element);

    cout<<"preorder traversal : ";
    preordertraversal(BST);
    cout<<endl;
    
    return 0;
}
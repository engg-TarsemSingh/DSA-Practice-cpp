#include<iostream>
#include<vector>
using namespace std;

vector<int> createarray(){
    vector<int> array;
    cout<<"--------------------ENTER -1 TO EXIT ------------------"<<endl;
    int data = 0;
    while(data!=-1){
        cout<<"enter value : ";
        cin>>data;
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

bool BSTsearch(Node* root , int data){

    while(true){
        if(root==nullptr){
            return false;
        }
        else if((root->data)==data){
            return true;
        }
        else if((root->data)>data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
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
    cout<<"enter the element you want to search : ";
    cin>>element;
    if(BSTsearch(BST,element)){
        cout<<element<<" is present in BST"<<endl;
    }
    else{
        cout<<element<<" is not present in BST"<<endl;
    }
    return 0;
}
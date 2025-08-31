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
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* createtree(){
    int data;
    cout<<"enter data : ";
    cin>>data;

    if(data==-1){
        return nullptr;
    }

    Node* node = new Node(data);

    cout<<"------Left of "<<data<<endl;
    node->left = createtree();

    cout<<"------Right of "<<data<<endl;
    node->right = createtree();

    return node;
}

int solve(Node* root , int k , vector<int> array={} ){
    if(root==nullptr){
        return 0;
    }

    array.push_back(root->data);
    int sum = 0 , current_path=0 ;
    for(int i=array.size()-1 ; i>=0 ; i--){
        sum += array[i];
        if(sum==k){
            current_path += 1;
            break;
        }
    }

    int left_path = solve(root->left,k,array);
    int right_path = solve(root->right,k,array);

    array.pop_back();

    return left_path+right_path+current_path;
}

int main(){
    Node* root = createtree();
    cout<<"enter the value of K : ";
    int k;
    cin>>k;
    int Ksumpaths = solve(root,k);
    cout<<"the tree have ["<<k<<"] paths : "<<Ksumpaths<<endl;

    return 0;
}
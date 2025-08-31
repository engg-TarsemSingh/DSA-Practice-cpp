#include<iostream>
#include<queue>
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

Node* createtree(Node* root){
    int data;
    if(root==nullptr){
        cout<<"enter the root node data : ";
        cin>>data;
    }
    else{
        cout<<"Data -> "<<data;
    }

    if(data==-1){
        return nullptr;
    }

    root = new Node(data);

    cout<<"enter the data for left of "<<root->data<<endl;
    root->left = createtree(root->left);
    cout<<"enter the data for right of "<<root->data<<endl;
    root->right = createtree(root->right);

    return root;
}

vector<int> zig_zag_traversal(Node* root){
    vector<int> result;
    queue<Node*> qu;
    qu.push(root);

    bool lefttoright = true;
    while(!qu.empty()){
        int size = qu.size();
        vector<int> temp(size);

        for(int i=0 ; i<size ; i++){
            int index = lefttoright ? i : size-i-1;
            temp[index] = qu.front()->data;

            Node* left = qu.front()->left;
            Node* right = qu.front()->right;

            if(left!=nullptr){
                qu.push(left);
            }
            if(right!=nullptr){
                qu.push(right);
            }

            qu.pop();
        }

        lefttoright = !lefttoright;

        for(int i:temp){
            result.push_back(i);
        }
    }

    return result;
}

void print_vector(vector<int>& result){
    for(int i=0 ; i<result.size() ; i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
}

int main(){
    Node* Root = createtree(nullptr);
    vector<int> result = zig_zag_traversal(Root);
    print_vector(result);
    return 0;
}
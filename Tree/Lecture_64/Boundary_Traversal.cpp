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

void left_view (Node* root , vector<int>& ans){
    Node* temp = root;
    while(true){
        if(temp->left!=nullptr){
            ans.push_back(temp->data);
            temp = temp->left;
            continue;
        }
        else if(temp->right!=nullptr){
            ans.push_back(temp->data);
            temp = temp->right;
            continue;
        }
        else{
            break;
        }
    }
}

void leaf_nodes(Node* root , vector<int>& ans){
    if(root==nullptr){
        return ;
    }
    else if(root->left==nullptr && root->right==nullptr){
        ans.push_back(root->data);   
    }

    leaf_nodes(root->left,ans);
    leaf_nodes(root->right,ans);
}

void right_view(Node* root , vector<int>& ans){
    if(root->right!=nullptr){
        right_view(root->right,ans);
        ans.push_back(root->data);
    }
    else if(root->left!=nullptr){
        right_view(root->left,ans);
        ans.push_back(root->data);
    }
}

vector<int> Boundry_traverse(Node* root){
    vector<int> ans;
    
    left_view(root,ans);
    leaf_nodes(root,ans);
    right_view(root->right,ans);

    return ans;
}

void print_vector(vector<int>& result){
    for(int i=0 ; i<result.size() ; i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
}

int main(){
    Node* Root = createtree(nullptr);
    vector<int> result = Boundry_traverse(Root);
    cout<<"boundry traversal : ";
    print_vector(result);
    return 0;
}
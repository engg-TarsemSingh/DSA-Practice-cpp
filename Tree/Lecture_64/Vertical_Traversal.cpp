#include<iostream>
#include<vector>
#include<map>
#include<queue>
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

void print_map(map<Node*,int> given){
    for(auto i : given){
        cout<<"Node = "<<i.first->data<<"   level : "<<i.second<<endl;
    }
}

vector<int> Vertical_traverse(Node* root){
    if(root==nullptr) {return {};}
    map<int,map<int,vector<int>>> result;
    queue<pair<Node*,pair<int,int>>> qu;
    qu.push(make_pair(root,make_pair(0,0)));

    while(!qu.empty()){
        pair<Node*,pair<int,int>> current = qu.front();
        qu.pop();

        Node* current_node = current.first;
        int distance = current.second.first;
        int level = current.second.second;
        
        result[distance][level].push_back(current_node->data);
        Node* left = current_node->left;
        Node* right = current_node->right;

        if(left!=nullptr){
            qu.push(make_pair(left,make_pair(distance-1,level+1)));
        }
        if(right!=nullptr){
            qu.push(make_pair(right,make_pair(distance+1,level+1)));
        }
    }

    vector<int> ans;
    for(const auto& i : result){
        for(const auto& j : i.second){
            for(const auto& k : j.second){
                ans.push_back(k);
            }
        }
    }

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
    vector<int> result = Vertical_traverse(Root);
    cout<<"boundry traversal : ";
    print_vector(result);
    return 0;
}
#include<iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isterminal;
    TrieNode(char data){
        this->data = data;
        this->isterminal = false;
        for(int i=0 ; i<26 ; i++){
            children[i] = nullptr;
        }
    }
};

class Trie{
    public:
    TrieNode* root = new TrieNode('\0');

    void insertword(TrieNode* root , string word){
        if(word.size()==0) {root->isterminal=true; return;}

        TrieNode* next = nullptr;
        if(root->children[word[0]-'a']!=nullptr){
            next = root->children[word[0]-'a'];
        }
        else{
            next = new TrieNode(word[0]);
            root->children[word[0]-'a'] = next;
        }

        insertword(next,word.substr(1));
    }

    void insert(string word){
        insertword(root,word);
    }

    bool searching(TrieNode* root , string word){
        if(word.size()==0){
            if(root->isterminal==true){
                return true;
            }
            else{
                return false;
            }
        }

        TrieNode* next =nullptr;
        int index = word[0]-'a';
        bool ans = false;
        if(root->children[index]!=nullptr){
            next = root->children[index];
            ans = searching(next,word.substr(1));
        }
        
        return ans;
    }

    bool search(string word){
        return searching(root,word);
    }

    void deleting(TrieNode* root , string word){
        if(word.size()==0){root->isterminal=false; return;}

        int index = word[0]-'a';
        TrieNode* next = root->children[index];
        deleting(next,word.substr(1));

    }

    void delet(string word){
        return deleting(root,word);
    }
};

int main(){
    Trie t;
    t.insert("tarsem");
    t.insert("singh");
    cout<<"is tarsem present in trie : "<<t.search("tarsem")<<endl;
    cout<<"is singh present in trie : "<<t.search("singh")<<endl;
    t.delet("singh");
    cout<<"is singh present in trie : "<<t.search("singh")<<endl;

    return 0;
}
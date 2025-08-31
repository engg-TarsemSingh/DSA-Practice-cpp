//                                leetcode 138                                   // SC=O(n)  TC=O(n)
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a Node.
struct Node {
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

// Function to create a linked list with random pointers from a given input.
Node* createList(vector<pair<int, int>>& input) {
    if (input.empty()) return nullptr;

    // Create all nodes with just values (without connections)
    unordered_map<int, Node*> nodes;
    Node* head = new Node(input[0].first);
    nodes[0] = head;

    Node* prev = head;
    for (int i = 1; i < input.size(); i++) {
        Node* newNode = new Node(input[i].first);
        prev->next = newNode;
        nodes[i] = newNode;
        prev = newNode;
    }

    // Set random pointers
    Node* current = head;
    for (int i = 0; i < input.size(); i++) {
        int random_index = input[i].second;
        if (random_index != -1) {
            current->random = nodes[random_index];
        }
        current = current->next;
    }

    return head;
}

// Function to display the list (val and random pointer)
void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << "Node value: " << current->val << ", Random points to: ";
        if (current->random)
            cout << current->random->val;
        else
            cout << "null";
        cout << endl;
        current = current->next;
    }
}

void print(Node* head) {
    while(head != NULL) {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node* copied(Node* head) {
    Node* new_head = new Node(head->val);
    Node* tail = new_head;
    head = head->next;
    while(head!=NULL) {
        Node* new_node = new Node(head->val);
        tail->next = new_node;
        tail = tail->next;
        head = head->next;
    }
    return new_head;
}

void print_array(vector<Node*> given){
    for(int i=0 ; i<given.size() ; i++){
        cout<<given[0]->val<<" ";
    }
    cout<<endl;
}

Node* copyRandomList(Node* head) {
    if(head==NULL) {return NULL;}
        Node* copy = copied(head);
        
        Node* f = head;
        Node* s = copy;
        while(f!=NULL){
            Node* temp = f->next;
            f->next = s;

            f = s;
            s = temp;
        }
        cout<<"**************************************"<<endl;
        cout<<"given list : "; print(head);
        displayList(head);
        cout<<"**************************************"<<endl;
        cout<<"copied list : "; print(copy);
        displayList(copy);
        cout<<"**************************************"<<endl;
        cout<<endl<<endl;

        Node* temp = head;
        while(temp!=NULL){
            if(temp->random == NULL){
                temp->next->random = NULL;
            }
            else{
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        cout<<"**************************************"<<endl;
        cout<<"given list : "; print(head);
        displayList(head);
        cout<<"**************************************"<<endl;
        cout<<"copied list : "; print(copy);
        displayList(copy);
        cout<<"**************************************"<<endl;
        cout<<endl<<endl;

        f = head;
        s = copy;
        Node* f_next = NULL;
        Node* s_next = NULL;
        while(s!=NULL && s->next!=NULL){
            f_next = f->next->next;
            s_next = s->next->next;
            f->next = f_next;
            s->next = s_next;
            f = f_next;
            s = s_next;
        }
        f->next = NULL;

    cout<<"**************************************"<<endl;
    cout<<"given list : "; print(head);
    displayList(head);
    cout<<"**************************************"<<endl;
    cout<<"copied list : "; print(copy);
    displayList(copy);
    cout<<"**************************************"<<endl;
    cout<<endl<<endl;

    return copy;
}

int main() {
    // Example input: Each pair represents (val, random_index)
    vector<pair<int, int>> input = {{1, 2}, {2, -1}, {3, 1}, {4, 0}};

    // Create the list
    Node* head = createList(input);

    Node* copy =copyRandomList(head);

    return 0;
}
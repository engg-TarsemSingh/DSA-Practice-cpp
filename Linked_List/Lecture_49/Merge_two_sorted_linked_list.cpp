#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insert(Node* &head , int data , int position=1) {
    Node* new_node = new Node(data);
    if(head == NULL) {
        head = new_node;
        return;
    }
    else if(position == 1) {
        new_node->next = head;
        head = new_node;
        return;
    }

    Node* temp = head;
    int current_position = 1;
    while(temp != NULL) {
        if(current_position = position-1) {
            new_node->next = temp->next;
            temp->next = new_node;
            return;
        }
        temp = temp->next;
        current_position++;
    }
}

void print(Node* head) {
    cout<<"linked list : ";
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void merge_sorted_lists(Node* &f , Node* &s) {
    if(f == NULL) {
        f=s;
        return;
    }
    else if(s == NULL) {
        s=f;
        return;
    }
    
    Node* f_current = NULL;
    Node* f_previous = NULL;
    Node* s_current = NULL;

    if(f->data < s->data){
        f_current = f;
        s_current = s;
    }
    else {
        f_current = s;
        s_current = f;
    }

    f = f_current;
    if(f_current->next == NULL){
        f_current->next = s_current;
        s=f;
    }
    f_previous = f_current;
    f_current = f_current->next;
    cout<<"*****************************************"<<endl;
    cout<<endl;
    cout<<"first linked list ***********************"<<endl;
    print(f_current);
    cout<<"second linked list **********************"<<endl;
    print(s_current);
    cout<<endl;
    cout<<"*****************************************"<<endl<<endl;

    while(f_current != NULL && s_current != NULL) {

        if(f_current->data > s_current->data){
            f_previous->next = s_current;
            s_current = s_current->next;
            f_previous->next->next = f_current;
            f_previous = f_previous->next;
        }
        else{
            f_previous = f_current;
            f_current = f_current->next;
        }
    }

    if(f_current == NULL){
        f_previous->next = s_current;
    }

    s=f;
}

int main() {
    Node* first_head = NULL;
    insert(first_head,7);
    print(first_head);
    insert(first_head,7);
    print(first_head);
    insert(first_head,4);
    print(first_head);
    insert(first_head,0);
    print(first_head);

    Node* second_head = NULL;
    insert(second_head,3);
    print(second_head);
    insert(second_head,2);
    print(second_head);
    insert(second_head,1);
    print(second_head);
    insert(second_head,1);
    print(second_head);

    cout<<endl;
    merge_sorted_lists(first_head,second_head);
    print(second_head);

    return 0;
}
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

void sort_0s_1s_2s(Node* &head) {
    //according to second approach don't change data within nodes
    //in this approach we will make three linked lints for 0's 1's and 2's
    //and after inserting values we will combine tham
    //initializing dummy nodes
    Node* zero_head = new Node(-1);
    Node* first_head = new Node(-1);
    Node* second_head = new Node(-1);

    //initializating tails
    Node* zero_tail = zero_head;
    Node* first_tail = first_head;
    Node* second_tail = second_head;

    //inserting values in the three linked lists
    Node* temp = head;
    while(temp != NULL) {
        if(temp->data == 0) {
            zero_tail->next = new Node(0);
            zero_tail = zero_tail->next;
        }
        else if(temp->data == 1) {
            first_tail->next = new Node(1);
            first_tail = first_tail->next;
        }
        else {
            second_tail->next = new Node(2);
            second_tail = second_tail->next;
        }
        temp = temp->next;
    }

    //merging the three lists
    if(first_head->next != NULL){
        zero_tail->next = first_head->next;
    }
    else if(second_head->next != NULL){
        zero_tail->next = second_head->next;
    }
    first_tail->next = second_head->next;
    head = zero_head->next;

    //deleting unwanted nodes
    delete zero_head;
    delete first_head;
    delete second_head;
}

int main() {
    Node* head = NULL;
    insert(head,2);
    print(head);
    insert(head,0,2);
    print(head);
    insert(head,1,2);
    print(head);
    insert(head,0,1);
    print(head);
    insert(head,0);
    print(head);
    cout<<endl<<"head ===== "<<head->data<<endl<<endl;

    sort_0s_1s_2s(head);
    print(head);

    return 0;
}
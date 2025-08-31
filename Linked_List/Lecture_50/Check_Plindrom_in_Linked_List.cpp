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

Node* middle(Node* head) {
    Node* fast = head;
    Node* slow = head;

    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

bool ispalindrom(Node* head) {
    bool ans = true;
    Node* mid = middle(head);

    //if only one element present
    if(mid == NULL){
        return false;
    }
    else if(mid->next == NULL) {
        return true;
    }

    //reversing list after middle
    Node* current = mid->next;
    Node* previous = NULL;
    while(current != NULL) {
        Node* temp = current->next;
        current->next = previous;
        previous = current;
        if(temp == NULL) {
            mid->next = current;
        }
        current = temp;
    }

    //comparing linked list before and after mid
    Node* first_head  = head;
    Node* second_head = mid->next;
    while(second_head != NULL) {
        if(first_head->data != second_head->data) {
            ans = false;
        }
        first_head = first_head->next;
        second_head = second_head->next;
    }

    //reversing list after middle
    current = mid->next;
    previous = NULL;
    while(current != NULL) {
        Node* temp = current->next;
        current->next = previous;
        previous = current;
        if(temp == NULL) {
            mid->next = current;
        }
        current = temp;
    }

    return ans;
}

int main() {
    Node* head = NULL;
    insert(head,1);
    print(head);
    insert(head,1);
    print(head);
    insert(head,3);
    print(head);
    insert(head,1);
    print(head);
    insert(head,1);
    print(head);

    cout<<endl<<"is the given liked list palandrom : "<<ispalindrom(head)<<endl<<endl;
    print(head);

    return 0;
}
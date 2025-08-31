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

void sort_0s_1s_2s(Node* head) {
    //in first approach count all 0's 1's and 2's
    //then insert all 0's first and than 1's and 2's
    int array[3] = {0};

    Node* current_node = head;
    while(current_node != NULL) {
        if(current_node->data == 0) {
            array[0] += 1;
        }
        else if(current_node->data == 1) {
            array[1] += 1;
        }
        else {
            array[2] += 1;
        }
        current_node = current_node->next;
    }

    current_node = head;
    while(array[0] != 0) {
        current_node->data = 0;
        current_node = current_node->next;
        array[0] -= 1;
    }
    while(array[1] != 0) {
        current_node->data = 1;
        current_node = current_node->next;
        array[1] -= 1;
    }
    while(array[2] != 0) {
        current_node->data = 2;
        current_node = current_node->next;
        array[2] -= 1;
    }
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
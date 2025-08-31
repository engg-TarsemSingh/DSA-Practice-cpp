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
        if(current_position == position-1) {
            new_node->next = temp->next;
            temp->next = new_node;
            return;
        }
        temp = temp->next;
        current_position++;
    }
}

void print(Node* head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node* middle(Node* head){
    Node* fast = head;
    Node* slow = head;
    
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    if(slow->next == NULL){
        return head;
    }

    return slow;
}

Node* joining(Node* f , Node* s){
    if(f==NULL) {return s;}
    if(s==NULL) {return f;}

    Node* head_1 = f->data<=s->data ? f : s;
    Node* head_2 = f->data>s->data ? f : s;

    Node* current = head_1->next;
    Node* previous = head_1;
    while(current!=NULL && head_2!=NULL){
        if(head_2->data<current->data){
            Node* temp = head_2->next;
            previous->next = head_2;
            previous = head_2;
            previous->next = current;
            head_2 = temp;
        }
        else{
            previous = current;
            current = current->next;
        }
    }
    while(head_2!=NULL){
        previous->next = head_2;
        previous = head_2;
        head_2 = head_2->next;
    }

    return head_1;
}

Node* merge_sort(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* mid = middle(head);
    //Dividing linked list in two parts
    Node* first_half = head;
    Node* second_half = mid->next;
    mid->next = NULL;

    //sorting both parts
    first_half = merge_sort(first_half);
    second_half = merge_sort(second_half);

    //joining two sorted linked list
    return joining(first_half,second_half);
}

int main() {
    Node* head = NULL;
    insert(head,1);
    insert(head,38);
    insert(head,0);
    insert(head,4);
    insert(head,1);
    cout<<"original linked list : "; print(head);

    head = merge_sort(head);

    cout<<"sorted linked list : "; print(head);
    return 0;
}
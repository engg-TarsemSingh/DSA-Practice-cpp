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
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node* get_reversed(Node* head) {
    if(head == NULL) { return head; }
    if(head->next == NULL) { return head; }

    Node* previous = NULL;
    while(head != NULL) {
        Node* temp = head->next;
        head->next = previous;
        previous = head;
        head = temp;
    }

    return previous;
}

int adding(int a , int b , int &carry) {
    int sum = a+b+carry;
    carry = sum/10;

    return sum%10;
}

Node* sum_number(Node* f , Node* s) {
    //first step check weather any list is empty
    if(f == NULL) { return s; }
    if(s == NULL) { return f; }

    //second step reverse both lists
    Node* f_reversed = get_reversed(f);
    Node* s_reversed = get_reversed(s);

    cout<<endl;
    cout<<"************************"<<endl;
    cout<<"firse reversed : ";print(f_reversed);
    cout<<"second reversed : ";print(s_reversed);
    cout<<"************************"<<endl;
    cout<<endl;

    //adding the two lists
    Node* answer = NULL;
    int carry = 0;
    while(f_reversed != NULL && s_reversed != NULL) {

        int sum = adding(f_reversed->data,s_reversed->data,carry);
        insert(answer,sum);

        f_reversed = f_reversed->next;
        s_reversed = s_reversed->next;
    }

    //if first number ends
    while(s_reversed != NULL){

        int sum = adding(s_reversed->data,0,carry);
        insert(answer,sum);

        s_reversed = s_reversed->next;
    }

    //if second number ends
    while(f_reversed != NULL){

        int sum = adding(f_reversed->data,0,carry);
        insert(answer,sum);

        f_reversed = f_reversed->next;
    }

    //if carry remains
    if(carry != 0){
        insert(answer,carry);
    }

    return answer;
}


int main() {
    Node* first_head = NULL;
    insert(first_head,9);
    insert(first_head,9,2);
    cout<<"First Linked List : ";
    print(first_head);
    
    Node* second_head = NULL;
    insert(second_head,9);
    insert(second_head,9);
    cout<<"Second Linked List : ";
    print(second_head);

    Node* ans = sum_number(first_head,second_head);

    cout<<"***********************************"<<endl;
    cout<<"answer : ";
    print(ans);

    return 0;
}
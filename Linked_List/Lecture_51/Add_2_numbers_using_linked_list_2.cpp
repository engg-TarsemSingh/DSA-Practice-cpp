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
   
    //make generic code which uses while loop for all cases
    while(f_reversed!=NULL || s_reversed!=NULL || carry!=0) {

        int first_value = 0;
        if(f_reversed != NULL){
            first_value = f_reversed->data;
            f_reversed = f_reversed->next;
        }

        int second_value = 0;
        if(s_reversed != NULL) {
            second_value = s_reversed->data;
            s_reversed = s_reversed->next;
        }

        int sum = adding(first_value,second_value,carry);
        insert(answer,sum);
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
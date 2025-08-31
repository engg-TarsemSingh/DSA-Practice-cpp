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

void insert_At_Start(Node* &head , int data) {
    Node* to_be_inserted = new Node(data);
    to_be_inserted->next = head;
    head = to_be_inserted;
}

void insert_At_End(Node* &tail , int data) {
    Node* to_be_inserted = new Node(data);
    tail->next = to_be_inserted;
    tail = to_be_inserted;
}

void insert_At_Given(Node* &head , Node* &tail , int data , int position) {
    int length = 0;
    Node* before = NULL;
    Node* after = NULL;

    Node* temp = head;
    while(temp != NULL) {
        length = length+1;

        if(length == position-1) {
            before = temp;
            after = temp->next;
        }

        tail = temp;
        temp = temp->next;
    }

    if(position < 1 or position > length) {
        cout<<"OUT_OF_BOUND (please enter valid position)"<<endl;
    }

    else if(position == length) {
        insert_At_End(tail,data);
    }

    else if(position == 1) {
        insert_At_Start(head,data);
    }

    else {
        Node* to_be_inserted = new Node(data);
        before->next = to_be_inserted;
        to_be_inserted->next = after;
    }
}

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    Node* obj = new Node(10);
    Node* head = obj;
    Node* tail = obj;

    print(head);
    insert_At_End(tail,40);
    cout<<"inserting 40 at end"<<endl;
    print(head);
    insert_At_Start(head,4);
    cout<<"inserting 4 at start"<<endl;
    print(head);
    insert_At_Given(head,tail,34,2);
    cout<<"inserting 34 at 2nd position"<<endl;
    print(head);
    cout<<"inserting 55 at 4th position"<<endl;
    insert_At_Given(head,tail,55,4);
    print(head);
    insert_At_Given(head,tail,5,1);
    cout<<"inserting 5 at 1st position"<<endl;
    print(head);
    cout<<"tail = "<<tail->data<<endl;
    cout<<"head = "<<head->data;

    return 0;
}
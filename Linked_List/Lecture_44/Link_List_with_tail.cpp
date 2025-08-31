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

void insert(Node* &tail , int data) {
    Node* to_be_inserted = new Node(data);
    tail->next = to_be_inserted;
    tail = to_be_inserted;
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

    Node* obj = new Node(4);
    Node* tail = obj;

    print(obj);
    insert(tail,30);
    print(obj);
    insert(tail,54);
    print(obj);
    insert(tail,75);
    print(obj);

    delete obj ;
    return 0;
}
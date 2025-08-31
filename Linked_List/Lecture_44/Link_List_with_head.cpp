#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insert(Node* &head, int data) {
    Node *obj = new Node(data);
    obj->next = head;
    head = obj;
};

void print(Node* &head) {
    Node* temp = head;
    
    for( ; temp != NULL ; ) {
        cout<<temp->data<<" ";
        temp=temp->next;
    };
    cout<<endl;
};

int main() {
    Node* obj_1 = new Node(5) ;
    Node* head = obj_1 ;

    print(head);
    insert(head,20);
    print(head);
    insert(head,2);
    print(head);
    insert(head,584);
    print(head);

    delete obj_1 ;
    return 0;
};
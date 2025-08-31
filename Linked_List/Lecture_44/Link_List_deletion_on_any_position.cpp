#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node() {
        cout << "memory is free for node with data = " << this->data << endl;
    }
};

void insert(Node *&tail, int data)
{
    Node *to_be_inserted = new Node(data);
    tail->next = to_be_inserted;
    tail = to_be_inserted;
}

void print(Node *&head)
{
    cout << "printing linked list" << endl;
    Node *temp = head;
    for (; temp != NULL;)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void delete_first(Node* &head) {
    Node* temp = head;
    head = head->next;
    delete temp;
}

void delete_middle(Node* &temp , Node* &previous) {
    previous->next = temp->next;
    delete temp;
}

void delet_by_value(Node* &head, Node* &tail, int value)
{
    bool is_deleted = false;

    if( head->data == value) {
        delete_first(head);
        is_deleted = true;
    }

    Node* temp = head->next;
    Node* previous = head;
    
    for(; temp != NULL and is_deleted == false ;) {
        if(temp->data == value) {
            //checking if the node to be deleted is last node
            if(temp->next == NULL) { 
                tail = previous ;
            }
            delete_middle(temp,previous);
            is_deleted = true;
        }
        temp = temp->next;
        previous = previous->next;
    }
}

int main()
{
    Node *head = new Node(5);
    Node *tail = head;

    cout<<endl;
    cout<<"head = "<<head->data<<endl;
    cout<<"tail = "<<tail->data<<endl<<endl;

    insert(tail, 564);
    insert(tail, 55);
    insert(tail, 4);
    insert(tail, 85);
    insert(tail, 07);
    print(head);

    cout<<endl;
    cout<<"head = "<<head->data<<endl;
    cout<<"tail = "<<tail->data<<endl<<endl;

    cout<<"calling function to delete 4"<<endl;
    delet_by_value(head,tail,4);
    print(head);
    cout<<"calling function to delete 564"<<endl;
    delet_by_value(head,tail,564);
    print(head);
    cout<<"calling function to delete 07"<<endl;
    delet_by_value(head,tail,07);
    print(head);

    cout<<endl;
    cout<<"head = "<<head->data<<endl;
    cout<<"tail = "<<tail->data<<endl<<endl;

    return 0;
}
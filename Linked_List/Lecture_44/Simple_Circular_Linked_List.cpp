#include<iostream>
using namespace std;

class Node 
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insert(Node* &head , Node* &tail , int data , int position = 1)
{
    if(position <= 0)
    {
        cout<<"invalid position : please enter correct position"<<endl;
    }
    else if(head == NULL and position == 1)                                 //inserting when list is empty
    {
        Node* to_insert = new Node(data);
        head = to_insert;
        tail = to_insert;
        tail->next = to_insert;                                        
        return;
    }
    else if(position == 1)                                                  //inserting in first position
    {
        Node* to_insert = new Node(data);
        tail->next = to_insert;
        to_insert->next = head;
        head = to_insert;
        return;
    }

    Node* temp = head;
    int current_position = 1;
    while(temp->next != head)                                               //inserting in meddle
    {
        if(current_position == position-1)
        {
            Node* to_insert = new Node(data);
            to_insert->next = temp->next;
            temp->next = to_insert;
            return;
        }
        ++current_position;
        temp = temp->next;
    }

    if(current_position == position-1)                                       //inserting at end
    {
        Node* to_insert = new Node(data);
        to_insert->next = temp->next;
        temp->next = to_insert;
        tail = to_insert;
        return;
    }

    if(current_position < position)
    {
        cout<<"invalid position : please enter correct position"<<endl;        
    }
}

void deleting (Node* &head , Node* &tail , int value)
{
    cout<<endl;
    cout<<"deleting "<<value<<" from linked list"<<endl;

    Node* temp = head;
    if(head->data == value)                                                 //if you want to delete first element
    {
        head = head->next;
        tail->next = head;
        temp->next = NULL;
        delete temp;
        return;
    }

    while(temp->next != head)
    {                                         
        if(temp->next->data == value)                                      //deleting at middle
        {
            if(temp->next == tail)                                         //deleting at end
            {
                Node* to_delete = temp->next;

                tail = temp;
                tail->next = head;
                to_delete->next = NULL;
                delete to_delete;
                return;
            }
            else
            {
                Node* to_delete = temp->next;
                temp->next = temp->next->next;
                to_delete->next = NULL;
                delete to_delete;
                return;
            }
        }
        temp = temp->next;
    }

}

void display(Node* &head)
{
    cout<<"displaying the circullar linked list"<<endl;
    Node* temp = head;
    int count = 0;
    while(count != 2)
    {
        cout<<temp->data<<" ";
        if(temp->next == head)
        {
            ++count;
            cout<<"  ";
        }
        temp = temp->next;
    }
    cout<<endl;
}

void delete_all(Node* &head , Node* &tail)
{
    cout<<"deleting the list"<<endl;
    Node* temp = head;
    while(temp->next != head)
    {
        Node* next_node = temp->next;
        delete temp;
        temp = next_node;
    }
    delete temp;
    head = NULL;
    tail = NULL;
}

int main() 
{
    Node* head = NULL;
    Node* tail = NULL;

    cout<<"head = "<<head<<endl;
    cout<<"tail = "<<tail<<endl;
    cout<<endl;

    insert(head,tail,22);
    display(head);
    insert(head,tail,66);
    display(head);
    insert(head,tail,89);
    display(head);
    insert(head,tail,90,2);
    display(head);
    insert(head,tail,200,5);
    display(head);

    cout<<endl;
    cout<<"head->data = "<<head->data<<endl;
    cout<<"tail->data = "<<tail->data<<endl;
    cout<<endl;

    deleting(head,tail,22);
    display(head);
    deleting(head,tail,89);
    display(head);
    deleting(head,tail,200);
    display(head);

    cout<<endl;
    cout<<"head->data = "<<head->data<<endl;
    cout<<"tail->data = "<<tail->data<<endl;
    cout<<endl;

    delete_all(head,tail);
    return 0;
}
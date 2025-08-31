#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* previous;
    Node* next;
    Node(int data) {
        this->data = data;
        this->previous = NULL;
        this->next = NULL;
    }
};

void delete_list (Node* &head)
{
    while(head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void insert(Node* &head , Node* &tail , int data , int position = 1)
{
    if(position <= 0)
    {
        cout<<"INVALID POSITION : Please enter correct position"<<endl;
        return;
    }

    else if(head == NULL and position == 1) {
        Node* new_node = new Node(data);
        head = new_node;
        tail = new_node;
    }

    else if(position == 1)
    {
        Node* new_node = new Node(data);
        new_node->next = head;
        head->previous = new_node;
        head = new_node;
        return;
    }

    int current_position = 1;
    Node* temp = head;
    while (temp != NULL and head != NULL)
    {
        if(current_position == position-1)
        {
            Node* new_node = new Node(data);
            new_node->next = temp->next;
            new_node->previous = temp;
            if(temp->next == NULL)
            {
                tail = new_node;
            }
            else
            {
                temp->next->previous = new_node;
            }
            temp->next = new_node;
            return;
        }
        temp = temp->next;
        ++current_position;
    }

    if(position > current_position)
    {
        cout<<"INVALID POSITION : Please enter correct position"<<endl;
    }
}

void delete_by_position(Node* &head , Node* &tail , int position = 1)
{
    if(position <= 0)
    {
        cout<<"INVALID POSITION : Please enter correct position"<<endl;
        return;
    }
    else if(head == NULL)
    {
        cout<<"DOUBLY LINK_LIST IS EMPTY"<<endl;
        return;
    }
    else if(position == 1)
    {
        Node* temp = head;
        if(temp->next == NULL)
        {
            head = NULL;
            delete temp;
        }
        else
        {
            temp->next->previous = NULL;
            head = temp->next;
            delete temp;
        }
    }

    Node* temp = head->next;
    int current_position = 2;
    while(temp != NULL)
    {
        if(current_position == position)
        {
            if(temp->next == NULL)
            {
                tail = temp->previous;
                temp->previous->next = NULL ;
                delete temp;
                return;
            }
            else{
                temp->next->previous = temp->previous;
                temp->previous->next = temp->next;
                delete temp;
                return;
            }
        }
        temp = temp->next;
        ++current_position;
    }
    
    if(current_position < position )
    {
        cout<<"INVALID POSITION : Please enter correct position"<<endl;
    }
}

void print (Node* &head) 
{
    cout<<"Printing the Doubly Linked List"<<endl;
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void print_reverse(Node* &tail)
{
    cout<<"printing the doubly linked list in reverse"<<endl;
    Node* temp = tail;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->previous;
    }
    cout<<endl;
}

int main()
{
    Node* HEAD = NULL;
    Node* TAIL = NULL;

    //inserting into doubly linked list
    print(HEAD);
    insert(HEAD,TAIL,8);
    print(HEAD);
    insert(HEAD,TAIL,64,1);
    print(HEAD);
    insert(HEAD,TAIL,0,3);
    print(HEAD);
    insert(HEAD,TAIL,32,2);
    print(HEAD);
    insert(HEAD,TAIL,8,6);
    print(HEAD);
    print_reverse(TAIL);

    cout<<endl;
    cout<<"head = "<<HEAD->data<<endl;
    cout<<"tail = "<<TAIL->data<<endl;
    cout<<endl;

    //deleting into doubly linked list
    delete_by_position(HEAD,TAIL);
    print(HEAD);
    delete_by_position(HEAD,TAIL,3);
    print(HEAD);
    delete_by_position(HEAD,TAIL,2);
    print(HEAD);

    cout<<endl;
    cout<<"head = "<<HEAD->data<<endl;
    cout<<"tail = "<<TAIL->data<<endl;
    cout<<endl;

    delete_list(HEAD);
    return 0;
}
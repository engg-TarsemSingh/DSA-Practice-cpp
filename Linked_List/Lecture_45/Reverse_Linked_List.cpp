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

void display(Node* head)
{
    cout<<"displaying the linked list"<<endl;
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void reverse_list(Node* &head)
{
    cout<<"reversing linked list"<<endl;

    if(head->next == NULL)
    {
        return;
    }

    Node* current = head->next;
    Node* current_next = current->next;
    Node* previous = head;
    head->next = NULL;

    while(current->next != NULL)
    {
        current->next = previous;
        previous = current;
        current = current_next;
        current_next = current->next;
    }

    head = current;
    head->next = previous;
}

void insert(Node* &head , int data , int position=1)
{
    cout<<"inserting "<<data<<" at position "<<position<<endl;
    if(head == NULL)
    {
        Node* new_node = new Node(data);
        head = new_node;
        return;
    }
    else if(position == 1)
    {
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
        return;
    }

    int current_position = 1;
    Node* temp = head;
    while(temp != NULL)
    {
        if(current_position == position-1)
        {
            Node* new_node = new Node(data);
            new_node->next = temp->next;
            temp->next = new_node;
            return;
        }
        temp = temp->next;
        current_position++;
    }
};

int main()
{
    Node* head = NULL;

    insert(head,23);
    display(head);
    insert(head,55);
    display(head);
    insert(head,00,2);
    display(head);
    insert(head,34,4);
    display(head);
    insert(head,11);
    display(head);

    cout<<endl<<"head = "<<head->data<<endl<<endl;

    reverse_list(head);
    display(head);
    cout<<endl<<"head = "<<head->data<<endl;

    return 0;
}
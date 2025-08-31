#include<iostream>
using namespace std;

class Node 
{
    public:
    int data;
    Node* next;
    Node* previous;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->previous = NULL;
    }
};

void insert(Node* &head , int data , int position=1)
{
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
        head->previous = new_node;
        head = new_node;
        return;
    }

    Node* temp = head;
    int current_position = 1;
    while(temp->next != NULL)
    {
        if(current_position == position-1)
        {
            Node* new_node = new Node(data);
            new_node->next = temp->next;
            new_node->previous = temp;
            temp->next->previous = new_node;
            temp->next = new_node;
            return;
        }
        temp = temp->next;
        current_position++;
    }

    if(current_position == position-1)
    {
        Node* new_node = new Node(data);
        new_node->previous = temp;
        temp->next = new_node;
    }
}

void reverse_list_loop(Node* &head)
{
    cout<<"reversing the doubly linked list"<<endl;
    if(head == NULL)
    {
        cout<<"Doubli list is empty"<<endl;
        return;
    }
    else if(head->next == NULL)
    {
        return;
    }
    Node* current = head;
    Node* previous = current->previous;
    Node* current_next = current->next;
    while(current != NULL)
    {
        current->previous = current_next;
        current->next = previous;

        current = current_next;
        if(current->next == NULL)
        {
            current->next = current->previous;
            current->previous = NULL;
            head = current;
            return;
        }
        previous = current->previous;
        current_next = current->next;
    }
}

Node* reverse_list_recursion(Node* &head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    Node* Reversed_head = reverse_list_recursion(head->next);

    if(head->next == Reversed_head)
    {
        head->next->next = head->next->previous;
        head->next->previous = NULL;
    }

    Node* temp = head->next;
    head->next = head->previous;
    head->previous = temp;

    return Reversed_head;
}

void display(Node* head)
{
    cout<<"displaying the doubly linked list"<<endl;
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main()
{
    Node* HEAD = NULL;

    insert(HEAD,4);
    insert(HEAD,54,1);
    insert(HEAD,90,2);
    insert(HEAD,721,4);
    insert(HEAD,4);
    display(HEAD);

    cout<<endl<<"HEAD = "<<HEAD->data<<endl<<endl;

    reverse_list_loop(HEAD);
    display(HEAD);

    cout<<endl<<"HEAD = "<<HEAD->data<<endl<<endl;

    cout<<"reversing the doubly linked list through recurssion"<<endl;
    HEAD = reverse_list_recursion(HEAD);
    display(HEAD);

    cout<<endl<<"HEAD = "<<HEAD->data<<endl<<endl;

    return 0;
}
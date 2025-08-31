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

bool present(Node* head , int k) {
    if(k == 0) {
        return true;
    }
    else if(head == nullptr) {
        return false;
    }

    return present(head->next,--k);
}

void reverse_in_k_group(Node* &head , int k)
{
    if(head == NULL)       
    {
        return ;
    }

    Node* next_head = head;
    while(present(next_head,k))
    {
        Node* current = head;
        Node* previous = NULL;
        Node* next = NULL;
        
        for(int count=0 ; count<k ; count++)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        head->next = current;
        next_head = current;
        head = previous;
    }
}

void insert(Node* &head , int data , int position = 1)
{
    cout<<"inserting "<<data<<" at "<<position<<" position"<<endl;
    if(head == NULL)
    {
        Node* new_node = new Node(data);
        head = new_node;
        return;
    }
    if(position == 1)
    {
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
        return;
    }

    Node* temp = head;
    int current_position = 1;
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
}

void print_(Node* head)
{
    cout<<"displaying the list"<<endl;
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main()
{
    Node* head = NULL;
    insert(head,89);
    insert(head,94,2);
    insert(head,3,2);
    insert(head,55,4);
    insert(head,123,2);
    print_(head);
    cout<<"head = "<<head->data<<endl;

    cout<<"enter the value of K = ";
    int k;
    cin>>k;

    reverse_in_k_group(head,k);
    print_(head);
    
    return 0;
}
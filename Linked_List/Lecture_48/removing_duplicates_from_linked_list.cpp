#include<iostream>
#include<vector>
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

bool ispresent(vector<int> given , int data) {
    for(int dd : given) {
        if(dd == data) {
            return true;
        }
    }
    return false;
}

vector<int> remove_duplicates(Node* &head)
{
    cout<<"removing duplicate elements from linked list"<<endl;
    vector<int> result;
    if(head == NULL) {
        cout<<"list is empty"<<endl;
        return result;
    }

    for(Node* current=head ; current!=NULL ; current=current->next) 
    {
        Node* previous = current;
        for(Node* next=current->next ; next!=NULL ; )
        {
            if(current->data == next->data) {
                if(!ispresent(result,current->data)) {
                    result.push_back(current->data);
                }
                Node* temp = next;
                previous->next = next->next;
                next = previous->next;
                delete temp;
            }
            else {
                previous = next;
                next = next->next;
            }
        }
    }
    return result;
}

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

int main()
{
    Node* head = NULL;

    insert(head,23);
    insert(head,55);
    insert(head,00,2);
    insert(head,34,4);
    insert(head,0,5);
    insert(head,34,6);
    insert(head,34,1);
    insert(head,11,3);
    insert(head,23);
    insert(head,11);
    display(head);

    cout<<endl<<"head = "<<head->data<<endl<<endl;

    vector<int> duplicate_elements = remove_duplicates(head);

    cout<<"duplicate elements = ";
    for(int i : duplicate_elements)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    display(head);

    return 0;
}
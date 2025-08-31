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

bool ispresent ( int data , vector<int> given) {
    for(int i : given) {
        if(i == data) {
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
        cout<<"linked list is empty"<<endl;
        return result;
    }

    Node* current = head;
    Node* next = head->next;

    while(next != NULL) {
        if(current->data == next->data) {
            Node* temp = next;
            if(!ispresent(next->data,result)) {
                result.push_back(next->data);
            }
            current->next = next->next;
            delete temp;
        }
        else {
            current = next;
        }
        next = current->next;
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

    insert(head,20);
    insert(head,20);
    insert(head,18);
    insert(head,16);
    insert(head,15);
    insert(head,15);
    insert(head,10);
    insert(head,9);
    insert(head,9);
    insert(head,9);
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
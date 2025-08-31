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

vector<int> middle_of_list(Node* &head)
{
    if(head == NULL)
    {
        return vector<int> {0,0,0};
    }
    else if(head->next == NULL)
    {
        return vector<int> {1,1,head->data};
    }

    Node* length_ptr = head->next;
    Node* middle_ptr = head;
    int length = 2;
    int middle = 1;
    int data = 0;
    while(length_ptr != NULL && length_ptr->next != NULL)
    {
        length += 2;
        length_ptr=length_ptr->next->next;
        middle_ptr=middle_ptr->next;
        middle++;
    }

    if(length_ptr == NULL)
    {
        length--;
    }else{
        length++;
    }

    data = middle_ptr->data;
    return vector<int> {length,middle,data};
}

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

    vector<int> middle_of_linked_list = middle_of_list(head);
    cout<<"length of linked list = "<<middle_of_linked_list[0]<<endl;
    cout<<"middle position of linked list = "<<middle_of_linked_list[1]<<endl;
    cout<<"middle value of linked list = "<<middle_of_linked_list[2]<<endl; 

    return 0;
}
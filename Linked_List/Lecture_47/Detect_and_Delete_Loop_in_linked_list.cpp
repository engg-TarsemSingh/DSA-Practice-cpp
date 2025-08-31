#include<iostream>
#include<map>
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
        cout<<"head = NULL"<<endl;
        Node* new_node = new Node(data);
        head = new_node;
        return;
    }
    else if (head->next == NULL && position == 1)
    {
        cout<<"head->next == NULL && position ==1"<<endl;
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
        return;
    }

    Node* current_node = head;
    int current_position = 1;
    while(current_node != NULL)
    {
        if(current_position == position-1)
        {
            cout<<"inserting in middle"<<endl;
            Node* new_node = new Node(data);
            new_node->next = current_node->next;
            current_node->next = new_node;
        }
        current_node = current_node->next;
        current_position++;
    }
}

Node* looping_list(Node* head , int node_data)
{
    cout<<"looping the list at "<<node_data<<endl;
    Node* to_point = NULL;
    Node* temp = head;

    while(head != NULL)
    {
        if(head->next == NULL && head->data == node_data)
        {
            head->next = head;
            return head;
        }
        else if(head->data == node_data)
        {
            to_point = head;
            while(head->next != NULL)
            {
                head = head->next;
            }
            head->next = to_point;
            return head;
        }
        head = head->next;
    }

    return head;
}

bool is_looped(Node* head)
{
    if(head == NULL)
    {
        return false;
    }

    map<Node*,bool> visited;
    while(head != NULL)
    {
        if(visited[head] == true)
        {
            return true;
        }
        visited[head] = true;
        head = head->next;
    }
    return false;
}

bool is_looped_floyds(Node* head)
{
    if(head == NULL)
    {
        return false;
    }

    //according to floyd's algorithm if linked list is looped at some point both slow and fast will point to same node
    Node* slow = head;
    Node* fast = head;
    while(slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if(fast->next != NULL)
        {
            fast = fast->next;
        }

        if(slow == fast)
        {
            return true;
        }

        slow = slow->next;
    }
    return false;
}

int head_loop(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while(slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if(fast->next != NULL)
        {
            fast = fast->next;
        }

        if(slow == fast)
        {
            break;
        }

        slow = slow->next;
    }
    
    slow = head;
    while(slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow->data;
}

void end_looping(Node* head)
{
    cout<<"ending the loop in linked list"<<endl;
    Node* slow = head;
    Node* fast = head;
    while(slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if(fast->next != NULL)
        {
            fast = fast->next;
        }

        if(slow == fast)
        {
            break;
        }

        slow = slow->next;
    }
    
    slow = head;
    while(slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = NULL;
}

void print(Node* head)
{
    cout<<"displaying the linked list"<<endl;
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void display(Node* head , Node* tail)
{
    cout<<"displaying the looped linked list"<<endl;
    int count = 0;
    while(count != 2)
    {
        if(head == tail)
        {
            count++;
        }
        cout<<head->data<<" ";

        head = head->next;
    }
    cout<<endl;
}

int main()
{
    Node* head = NULL;

    insert(head,55);
    insert(head,9,2);
    insert(head,34,3);
    insert(head,765,2);
    cout<<endl<<"head = "<<head->data<<endl;
    print(head);
    cout<<endl;

    cout<<"enter the value to which last node point = ";
    int node_data;
    cin>>node_data;
    Node* tail = looping_list(head,node_data);
    cout<<endl<<"head = "<<head->data<<endl;
    display(head,tail);
    cout<<endl;
    
    cout<<"is the given linked list looped = "<<is_looped(head)<<endl;
    cout<<"is the given linked list looped = "<<is_looped_floyds(head)<<endl;

    cout<<"starting node of loop = "<<head_loop(head)<<endl;

    end_looping(head);
    print(head);

    return 0;
}
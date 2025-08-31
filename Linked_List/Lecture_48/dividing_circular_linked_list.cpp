#include<iostream>
#include<vector>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insert(Node* &head , int data , int position=0) {
    if(head == NULL) {
        Node* new_node = new Node(data);
        head = new_node;
        head->next = head;
        return;
    }

    Node* current_node = head;
    int current_position = 1;
    while(current_node->next != head) {
        if(current_position == position-1) {
            Node* new_node = new Node(data);
            new_node->next = current_node->next;
            current_node->next = new_node;
            return; 
        }
        current_position++;
        current_node = current_node->next;
    }

    if(current_position == position-1 || position == 0) {
        Node* new_node = new Node(data);
        new_node->next = head;
        current_node->next = new_node;
        return;
    }
    if(position == 1) {
        Node* new_node = new Node(data);
        new_node->next = head;
        current_node->next = new_node;
        head = new_node;
        return;
    }
}

void display(Node* head) {
    cout<<"displaying the circular list : ";
    int count = 0;
    Node* temp=head;
    do {
        cout<<temp->data<<" ";
        if(temp->next == head) {
            count++;
            cout<<" ";
        }
        temp = temp->next;
    }while(count != 2);
    cout<<endl;
}

vector<Node*> split_list(Node* head) {
    vector<Node*> answers;
    if(head == NULL) {
        cout<<"Given circular list is empty so, can't be split"<<endl;
        return answers;
    }
    Node* slow = head;
    Node* fast = head;
    int length = 1;
    while(fast->next != head) {
        fast = fast->next;
        length++;
        if(fast->next != head) {
            fast = fast->next;
            length++;
            slow = slow->next;
        }
    }

    if(length == 1) {
        cout<<"only one element present so can't split"<<endl;
        return answers;
    }
    else if(length%2 != 0) {
        answers.push_back(head);
        answers.push_back(slow->next);
        slow->next = head;
        fast->next = answers[1];
    }
    else {
        answers.push_back(head);
        answers.push_back(slow->next);
        slow->next = head;
        fast->next = answers[1];
    }

    return answers;
}

int main() {
    Node* head = NULL;

    insert(head,34);
    insert(head,5);
    insert(head,75);
    insert(head,90);
    insert(head,0,1);
    insert(head,1,5);
    insert(head,142);
    display(head);

    cout<<endl<<"head ==== "<<head->data<<endl<<endl;

    vector<Node*> answer = split_list(head);
    cout<<"first half of circular list "<<endl;
    cout<<"head of first half : "<<answer[0]->data<<endl;
    display(answer[0]);
    cout<<"second half of circular list "<<endl;
    cout<<"head of second half : "<<answer[1]->data<<endl;
    display(answer[1]);

    return 0;
}
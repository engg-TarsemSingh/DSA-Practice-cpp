#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class stack{
    public:
    Node* head;
    Node* tail;
    int length;
    stack(){
        this->head = new Node(-1);
        this->tail = head;
        this->length = 0;
    }

    bool isempty(){
        if(length==0){
            return true;
        }
        return false;
    }

    int top(){
        if(length==0){
            cout<<endl;
            cout<<"**************************************"<<endl;
            cout<<"INVALID TOP :stack is empty"<<endl;
            cout<<"**************************************"<<endl;
            return -1;
        }
        return tail->data;
    }

    void push(int data){
        tail->next = new Node(data);
        tail = tail->next;
        length++;
    }

    void pop(){
        if(length==0){
            cout<<"**************************************"<<endl;
            cout<<"INVALID POP :stack is empty"<<endl;
            cout<<"**************************************"<<endl;
            return;
        }
        Node* temp = head;
        while(temp->next!=tail){
            temp = temp->next;
        }
        delete temp->next; 
        temp->next = NULL;
        length--;

        if(length==0){
            tail = head;
        }
        else{
            tail = temp;
        }
    }
};

void delete_(stack* &given){
    while(given->head!=NULL){
        Node* temp = given->head;
        given->head = given->head->next;
        delete temp;
    }
    given->length = 0;
    delete given;
    given = NULL;
}

int main(){

    stack* first = new stack();

    cout<<endl;
    cout<<"############################################################"<<endl;
    cout<<"is stack empty = "<<first->isempty()<<endl;
    cout<<"top of stack = "<<first->top()<<endl;
    cout<<"############################################################"<<endl;
    cout<<endl;
    cout<<"inserting 5,6,7,8,9 in stack in order"<<endl;
    first->push(5);
    first->push(6);
    first->push(7);
    first->push(8);
    first->push(9);
    cout<<endl;
    cout<<"############################################################"<<endl;
    cout<<"is stack empty = "<<first->isempty()<<endl;
    cout<<"top of stack = "<<first->top()<<endl;
    cout<<"############################################################"<<endl;
    cout<<endl;
    cout<<"poping two times"<<endl;
    first->pop();
    first->pop();
    cout<<endl;
    cout<<"############################################################"<<endl;
    cout<<"is stack empty = "<<first->isempty()<<endl;
    cout<<"top of stack = "<<first->top()<<endl;
    cout<<"############################################################"<<endl;
    cout<<endl;
    cout<<"deleting stack"<<endl;
    delete_(first);
    cout<<"############################################################"<<endl;
    cout<<"is stack empty = "<<first->isempty()<<endl;
    cout<<"top of stack = "<<first->top()<<endl;
    cout<<"############################################################"<<endl;
    cout<<endl;
    

    return 0;
}
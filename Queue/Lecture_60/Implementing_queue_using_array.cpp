#include<iostream>
#include<queue>
using namespace std;

class Queue{
    public:
    int* array;
    int front;
    int rare;
    int size;
    Queue(int size=10){
        this->size = size;
        this->array = new int[size];
        this->front = -1;
        this->rare = -1;
        for(int i=0 ;i<size ; i++){
            array[i]=-1;
        }
    }

    bool empty(){
        if(rare == -1){
            return true;
        }
        return false;
    }

    void del_element(){
        if(front == -1 || front>rare){
            cout<<"INVALID OPERATION : to delete empty queue"<<endl;
        }
        else{
            array[front] = -1;
            front++;
        }
    }

    void insert_element(int given){
        if(front == -1){
            front++;
        }
        if(rare == size-1){
            cout<<"INVALID OPERATION : overflow queue is full"<<endl;
        }
        else{
            rare++;
            array[rare] = given;
        }
    }

    int size_(){
        return size;
    }

    int front_(){
        return front;
    }

    void display(){
        cout<<"[ ";
        for(int i=0 ; i<size ; i++){
            cout<<array[i]<<" ";
        }
        cout<<" ]"<<endl;
    }
};

int main(){
    Queue queue_1;

    cout<<"size of queue : "<<queue_1.size_()<<endl;
    cout<<"is queue empty : "<<queue_1.empty()<<endl;
    cout<<"front of queue : "<<queue_1.front_()<<endl;
    cout<<"displaying the queue : ";
    queue_1.display();
    cout<<"inserting 3,6,3,9,17,3 in order"<<endl;
    queue_1.insert_element(3);
    queue_1.insert_element(6);
    queue_1.insert_element(3);
    queue_1.insert_element(9);
    queue_1.insert_element(17);
    queue_1.insert_element(3);
    cout<<"displaying the queue : ";
    queue_1.display();
    cout<<"front of queue : "<<queue_1.front_()<<endl;
    cout<<"is queue empty : "<<queue_1.empty()<<endl;
    queue_1.del_element();
    queue_1.del_element();
    queue_1.del_element();
    queue_1.del_element();
    queue_1.del_element();
    queue_1.del_element();
    cout<<"deleting the two elements "<<endl;
    cout<<"front of queue : "<<queue_1.front_()<<endl;
    cout<<"is queue empty : "<<queue_1.empty()<<endl;
    cout<<"displaying the queue : ";
    queue_1.display();

    return 0;
}
#include<iostream>
using namespace std;

class stack{
    public:
    int top_n;
    int* array;
    int size;
    stack(int size){
        this->size = size;
        this->array = new int[size];
        this->top_n = -1;
    }

    int top(){
        if(top_n == -1){
            cout<<"ENVALID TOP : the stack is already empty"<<endl;
            return 0;
        }
        return array[top_n];
    }

    void pop(){
        if(top_n==-1){
            cout<<"ENVALID POP : the stack is already empty"<<endl;
        }
        else{
            array[top_n] = 0;
            top_n = top_n-1;
        }
    }

    void push(int data){
        if(top_n==size-1){
            cout<<"ENVALID : the stack is already full"<<endl;
        }
        else{
            top_n++;
            array[top_n] = data;
        }
    }
    
};

int main(){
    cout<<"enter the size required for stack : ";
    int size;
    cin>>size;

    stack stack_1(size);
    stack_1.top();
    stack_1.push(4);
    cout<<"top of stack = "<<stack_1.top()<<endl;
    stack_1.pop();
    stack_1.top();

    return 0;
}
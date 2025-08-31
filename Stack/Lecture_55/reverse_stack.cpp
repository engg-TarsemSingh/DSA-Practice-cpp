#include<iostream>
#include<stack>
using namespace std;

void print(stack<int> given){
    while(!given.empty()){
        cout<<given.top()<<" ";
        given.pop();
    }
    cout<<endl;
}

void insert_at_bottom(stack<int> &given , int k){
    if(given.empty()){
        given.push(k);
        return;
    }

    int top = given.top();
    given.pop();
    insert_at_bottom(given,k);
    given.push(top);
}

void reverse_stack(stack<int> &given){
    if(given.empty()){
        return;
    }
    int top = given.top();
    given.pop();
    reverse_stack(given);

    insert_at_bottom(given,top);
}

int main(){

    stack<int> given;
    given.push(33);  given.push(33);  given.push(8);  given.push(23);  given.push(85);  given.push(15); given.push(8);
    cout<<"given stack : ";
    print(given);

    reverse_stack(given);

    cout<<"given stack : ";
    print(given);

    return 0;
}
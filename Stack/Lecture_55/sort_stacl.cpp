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

void sorted_insert(stack<int> &given , int top){
    if(given.empty() || given.top()<top){
        given.push(top);
        return;
    }

    int top1 = given.top();
    given.pop();

    sorted_insert(given,top);

    given.push(top1);

}

void sort_stack(stack<int> &given){
    if(given.size()==1){
        return;
    }
    int top = given.top();
    given.pop();

    sort_stack(given);

    sorted_insert(given,top);
}

int main(){

    stack<int> given;
    given.push(33);  given.push(33);  given.push(8);  given.push(23);  given.push(85);  given.push(15); given.push(8);
    cout<<"given stack : ";
    print(given);

    sort_stack(given);

    cout<<"given stack : ";
    print(given);

    return 0;
}
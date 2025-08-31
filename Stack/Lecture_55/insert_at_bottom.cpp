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

void insert_at_bottom(stack<int> &given , int insert){
    if(given.empty()){
        given.push(insert);
        return;
    }

    int top = given.top();
    given.pop();

    insert_at_bottom(given,insert);

    given.push(top);
}

int main(){

    stack<int> given;
    given.push(33);  given.push(33);  given.push(8);  given.push(23);  given.push(85);  given.push(15); given.push(8);
    cout<<"given stack : ";
    print(given);

    cout<<"enter the value to be inserted at bottom : ";
    int insert;
    cin>>insert;
    insert_at_bottom(given,insert);

    cout<<"given stack : ";
    print(given);

    return 0;
}
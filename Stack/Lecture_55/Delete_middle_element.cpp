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

void deleting_middle(stack<int> &given){
    int middle = given.size()/2;
    cout<<"*********************************************************"<<endl;
    cout<<"size = "<<given.size()<<endl<<"middle = "<<middle<<endl;

    stack<int> temp;
    while(given.size()>middle+1){
        temp.push(given.top());
        given.pop();
    }
    given.pop();

    while(!temp.empty()){
        given.push(temp.top());
        temp.pop();
    }
    cout<<"*********************************************************"<<endl;
}

int main(){

    stack<int> given;
    given.push(33);  given.push(33);  given.push(8);  given.push(23);  given.push(85);  given.push(15); given.push(8);
    cout<<"given stack : ";
    print(given);

    deleting_middle(given);

    cout<<"given stack : ";
    print(given);

    return 0;
}
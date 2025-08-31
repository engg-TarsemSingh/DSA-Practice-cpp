#include<iostream>
#include<stack>
using namespace std;

int main(){

    stack<int> stack_1;

    cout<<"is stack empty : "<<stack_1.empty()<<endl;
    cout<<"size of stack : "<<stack_1.size()<<endl;
    cout<<endl;
    cout<<"insert 4,5,6,7 in stack "<<endl;
    cout<<endl;
    stack_1.push(4);
    stack_1.push(5);
    stack_1.push(6);
    stack_1.push(7);
    cout<<"is stack empty : "<<stack_1.empty()<<endl;
    cout<<"peak of stack : "<<stack_1.top()<<endl;
    cout<<"size of stack : "<<stack_1.size()<<endl;
    cout<<endl;
    cout<<"deleting 7 from top "<<endl;
    cout<<endl;
    stack_1.pop();
    cout<<"is stack empty : "<<stack_1.empty()<<endl;
    cout<<"peak of stack : "<<stack_1.top()<<endl;
    cout<<"size of stack : "<<stack_1.size()<<endl;
    

    return 0;
}
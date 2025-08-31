#include<iostream>
#include<stack>
#include<climits>
using namespace std;

stack<int> ini(){
    stack<int> st;
    cout<<"enter elements : ";
    while(1){
        int a;
        cin>>a;
        if(a<0){break;}
        st.push(a);
    }
    return st;
}

void print(stack<int>& st){
    cout<<"print stak :";
    for(int& i : st){
        cout<<i<<" ";
    }
    cout<<endl;
}

void sorting(stack<int>& st , int previous=INT_MAX){
    
}

int main(){
    stack<int> st = ini();
    
    print(st);
    cout<<"---------------REVERSING STACK-----------"<<endl;
    sorting(st);
    print(st);

    return 0;
}
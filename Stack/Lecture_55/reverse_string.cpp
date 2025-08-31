#include<iostream>
#include<string>
#include<stack>
using namespace std;

string reverse_string(string given){
    stack<int> st;
    for(char ch : given){
        st.push(ch);
    }
    string reverse_ = "";
    while(!st.empty()){
        char a = st.top();
        reverse_ = reverse_ + a;
        st.pop();
    }
    return reverse_;
}

int main(){
    cout<<"enter the string : ";
    string given;
    cin>>given;
    
    string reverse = reverse_string(given);
    cout<<"reversed string : "<<reverse<<endl;

    return 0;
}
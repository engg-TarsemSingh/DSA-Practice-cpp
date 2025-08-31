#include<iostream>
#include<stack>
#include<string>
using namespace std;

void print(stack<char> given){
    while(!given.empty()){
        cout<<given.top()<<" ";
        given.pop();
    }
    cout<<endl;
}

bool isredundant(string &given){
    stack<char> stak;
    int size = given.size();
    for(int i=0 ; i<size ; i++){
        char character = given[i];
        if(character=='(' || character=='+' || character=='-' || character=='*' || character=='/' || character=='%'){
            stak.push(character);
        }
        else if(character==')'){
            bool redundant = true;
            char top = stak.top();
            while(top != '('){
                if(top=='+' || top=='-' || top=='*' || top=='/' || top=='%'){
                    redundant = false;
                }
                stak.pop();
                top = stak.top();
            }
            if(redundant==true) {return true;}
            stak.pop();
        }
    }
    return false;
}

int main(){

    cout<<"enter the expression : ";
    string given;
    cin>>given;

    cout<<"does the given expression redundent : "<<isredundant(given)<<endl;

    return 0;
}
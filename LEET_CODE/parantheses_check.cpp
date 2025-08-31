#include<iostream>
#include<stack>
using namespace std;

void display(stack<char> given){
    cout<<"[ ";
    while(!given.empty()){
        cout<<given.top()<<" ";
        given.pop();
    }
    cout<<" ]"<<endl;
}

int checking(string s) {
    int ans = 0;
    int size = s.size();
    stack<char> stak;
    int flag = 0;
    cout<<"**********************************************"<<endl;
    cout<<"                 before loop "<<endl;
    cout<<"size of string : "<<size<<endl;
    cout<<"ans            : "<<ans<<endl;
    cout<<"flag           : "<<flag<<endl;
    cout<<"stack          : ";
    display(stak);
    for(int i=0 ; i<size ; i++){
        char current = s[i];
        cout<<endl;
        if(current == ')'){
            if(flag==0){
                flag ++;
            }
            else if(flag>=1){
                stak.pop();
                flag--;
            }
        }
        else{
            stak.push(current);
        }
        cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
        cout<<"string         : "<<s<<endl;
        cout<<"value of i     : "<<i<<endl;
        cout<<"ans            : "<<ans<<endl;
        cout<<"flag           : "<<flag<<endl;
        cout<<"stack          : ";
        display(stak);
        cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
        cout<<endl;
    }
    cout<<endl;
    cout<<"**********************************************"<<endl;
    cout<<endl;
    while(!stak.empty()){
        if(stak.top()=='('){
            ans += 2;
            stak.pop();
        }
        else{
            ans++;
            stak.pop();
        }
    }
    cout<<endl;
    cout<<"**********************************************"<<endl;
    cout<<endl;
    while(flag!=0){
        if(flag%2==0){
            ans++;
            flag -=2 ;
        }
        else{
            ans+=2;
            flag--;
        }
    }
    cout<<endl;
    cout<<"**********************************************"<<endl;
    cout<<endl;
    return ans;
}

int main(){
    cout<<"enter string : ";
    string given;
    cin>>given;

    cout<<"no. of checks to make = "<<checking(given)<<endl;

    return 0;
}
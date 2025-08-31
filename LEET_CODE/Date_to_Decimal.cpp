#include<iostream>
#include<string>
#include<stack>
using namespace std;

int to_num(int start , int end , string given){
    int ans = 0;
    for(int i=start ; i<=end ; i++){
        ans = ans*10 + (given[i]-'0');
    }
    return ans;
}

string to_binary(int given){
    if(given == 0) return 0;
    stack<int> stak;
    while(given!=0){
        stak.push(given&1);
        given /= 2;
    }
    
    string ans ="";
    while(!stak.empty()){
        ans += stak.top()==1 ? '1' : '0';
        stak.pop();
    }
    return ans;
}

string date_in_binary(string given){
    string ans = "";
    int year = to_num(0,3,given);
    int month = to_num(5,6,given);
    int date = to_num(8,9,given);
    
    ans += to_binary(year);
    ans += '-';
    ans += to_binary(month);
    ans += '-';
    ans += to_binary(date);

    
    return ans;
}

int main(){
    string date;
    cout<<"enteer date : ";
    cin>>date;

    string ans = date_in_binary(date);

    cout<<"date in binary : "<<ans;

    return 0;
}
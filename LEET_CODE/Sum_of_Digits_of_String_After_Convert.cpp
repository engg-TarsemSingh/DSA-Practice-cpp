#include<iostream>
#include<string>
using namespace std;

int sum(string s , int k){
    long long number = 0;
    cout<<"*********************************************"<<endl;
    cout<<"given string : "<<s<<endl;
    for(int i=0 ; i<s.size() ; i++){
        int digit = (s[i]-'a')+1;
        cout<<"ascii valuse of "<<s[i]<<" : "<<digit<<endl;
        while(digit!=0){
            number = digit%10 + number*10;
            digit = digit/10;
        }
        cout<<"current value of number = "<<number<<endl;
        cout<<endl<<endl;
    }
    cout<<"*********************************************"<<endl;
    
    cout<<"*********************************************"<<endl;
    cout<<"value of k : "<<k<<endl;
    for(int j=0 ; j<k ; j++){
        int temp = 0;
        cout<<"current loop : "<<j+1<<endl;
        while(number!=0){
            temp = number%10 + temp;
            number = number/10;
        }
        number = temp;
        cout<<"current number = "<<number<<endl;
    }
    cout<<"*********************************************"<<endl;
    return (int)number;
}

int main() {
    cout<<"enter the string :";
    string given;
    cin>>given;
    cout<<"enter the value of k : ";
    int k ;
    cin>>k;

    int ans = sum(given,k);
    cout<<"Sum of Digits of String After Convert : "<<ans<<endl;

    return 0;
}
#include<iostream>
using namespace std;

void bit(long a){
    for(int i=63 ; i>=0 ; i--){
        if((i+1)%8==0) {cout<<"  ";}
        else if((i+1)%4==0) {cout<<" ";}
        cout<<((a>>i)&1);
    }
}

void chan(long& a , int position){
    a = (1<<position-1) | a;
}

long flip(long n) {
    long ans = 0;
    cout<<"---------------------------------------------------------------"<<endl;
    cout<<"ans == ";
    bit(ans);
    cout<<endl;
    for(int i=0 ; i<32 ; i++){
        bool bits = (n>>i)&1;
        if(!bits){
            ans = (1<<i) | ans;
            cout<<"ans == ";
            bit(ans);
            cout<<"     i == "<<i;
            cout<<endl;
        }
    }
    cout<<"---------------------------------------------------------------"<<endl;
    return ans;
}

int main(){
    long a = 4;

    cout<<"decimal == "<<a<<endl;
    cout<<"bits    == ";
    bit(a);
    cout<<endl;

    int position;
    cout<<"enter the position of bit you want to chage == ";
    cin>>position;
    chan(a,position);
    cout<<"bits    == ";
    bit(a);
    cout<<endl;

    long d = a;
    d = flip(d);
    cout<<"bits    == ";
    bit(d);
    cout<<endl;

    return 0;
}
#include<iostream>
using namespace std;

void bit(long a){
    for(int i=63 ; i>=0 ; i--){
        if((i+1)%8==0) {cout<<"  ";}
        else if((i+1)%4==0) {cout<<" ";}
        cout<<((a>>i)&1);
    }
    cout<<endl;
}

long Bits(long n) {
    cout<<"----------------------------------------------------"<<endl;
    for(int i=0 ; i<32 ; i++){
        bool bits = (n>>i)&1;
        if(bits){
            n = ~(1<<i) & n;
        }
        else{
            n = (1<<i) | n;
        }
        bit(n);
    }
    cout<<"----------------------------------------------------"<<endl;
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    for(int i=32 ; i<64 ; i++){
        long k = 1;
        n = ~(k<<i)&n ;
        bit(n);
    }
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    return n;
}

int main(){
    long a=3;
    
    cout<<"decimal == "<<a<<endl;
    cout<<"binary  == ";
    bit(a);

    cout<<"-------FLIPPINT 32 BITS-----------"<<endl;
    long ans = Bits(a);
    cout<<"decimal == "<<ans<<endl;;
    cout<<"binary  == ";
    bit(ans);

    return 1;
}
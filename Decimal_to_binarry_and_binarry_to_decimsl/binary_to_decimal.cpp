#include<iostream>
using namespace std;

int bton(int binary){
    int ans = 0;
    int count=0;
    while(binary!=0){
        int digit = binary%10;
        ans |= (digit<<count);
        binary /= 10;
        count++;
    }
    return ans;
}

int main(){
    int binary;
    cout<<"enter binary number == ";
    cin>>binary;

    int number = bton(binary);
    cout<<"decimal of binary == "<<number<<endl;

    return 0;
}
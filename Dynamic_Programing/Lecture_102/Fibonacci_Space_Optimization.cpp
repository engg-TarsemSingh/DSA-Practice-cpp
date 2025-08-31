#include<iostream>
using namespace std;

int febonacci(int position){
    int prev2=1;
    int prev1=0;

    for(int i=2 ; i<position ; i++){
        int temp = prev1+prev2;
        prev1 = prev2;
        prev2 = temp;
    }

    return prev1+prev2;
}

int main(){
    int position;
    cout<<"enter the position : ";
    cin>>position;

    int result = febonacci(position);
    cout<<"the febonacci number at "<<position<<"th position is : "<<result<<endl;

    return 0;
}
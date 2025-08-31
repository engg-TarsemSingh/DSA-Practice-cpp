#include<iostream>
#include<vector>
using namespace std;

long fibo(int position , vector<long>& array){
    if(position==0 || position==1){
        array[position] = position;
        return position;
    }

    if(array[position]!=-1) {return array[position];}
    array[position] = fibo(position-1,array) + fibo(position-2,array);

    return array[position];
}

int main(){
    int position;
    cout<<"enter the position : ";
    cin>>position;

    vector<long> array(position+1,-1);
    long fibonacci = fibo(position,array);

    cout<<"the value at "<<position<<"th position in fibonacci series is : "<<fibonacci<<endl;
    return 0;
}
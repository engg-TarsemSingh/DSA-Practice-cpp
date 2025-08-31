#include<iostream>
#include<stack>
using namespace std;

void initialize(int* given , int size){
    for(int i=0 ; i<size ; i++){
        cout<<"enter "<<i+1<<" element of array = ";
        int aa;
        cin>>aa;
        given[i]=aa;
    }
}

void display(int* given , int size){
    cout<<"[ ";
    for(int i=0 ; i<size ; i++){
        cout<<given[i]<<" ";
    }
    cout<<"]"<<endl;
}

int find_m(stack<int>& stak , int f){
    if(stak.empty()){
        return -1;
    }
    else if(f>stak.top()){
        return stak.top();
    }

    int top = stak.top();
    stak.pop();

    int ans = find_m(stak,f);

    stak.push(top);
    return ans;
}

int* find_next_min(int* given , int size){
    int* ans = new int[size];
    stack<int> stak;
    for(int i=size-1 ; i>=0 ; i--){
        ans[i] = find_m(stak,given[i]);
        
        stak.push(given[i]);
    }

    return ans;
}

int main(){
    cout<<"enter the length of array : ";
    int size;
    cin>>size;
    int* array = new int[size];
    initialize(array,size);
    cout<<"displaing the array : ";
    display(array,size);

    int* ans = find_next_min(array,size);

    cout<<"displaying the next minimum of every element : ";
    display(ans,size);

    delete[] ans;
    delete[] array;
    return 0;
}
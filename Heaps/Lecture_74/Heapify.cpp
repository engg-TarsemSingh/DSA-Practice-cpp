#include<iostream>
using namespace std;

void initialize(int arr[] , int size){
    cout<<"+++++++++++++++ENTER THE ELEMENTS OF ARRAY+++++++++++++++"<<endl;
    for(int i=1 ; i<=size ; i++){
        int data;
        cout<<"enter value at "<<i<<" index : ";
        cin>>data;
        arr[i]=data;
    }
}

void print(int arr[] , int size){
    cout<<"%%%%%%%%%%%%%%%PRINTING THE ARRAY%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
    for(int i=1 ; i<=size ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void singleheapify(int arr[] , int size , int i){

    int target = i;
    int leftchild = i*2;
    int rightchild = i*2+1;

    if((leftchild<=size) && (arr[leftchild]>arr[target])){
        target = leftchild;
    }
    if((rightchild<=size) && (arr[rightchild]>arr[target])){
        target = rightchild;
    }

    if(target!=i){
        swap(arr[target],arr[i]);
        singleheapify(arr,size,target);
    }
}

void heapify(int arr[] , int size){
    cout<<"****************HEAPIFY THE ARRAY*********************"<<endl;
    for(int i=size/2 ; i>0 ; i--){
        singleheapify(arr,size,i);
    }
}

int main(){
    cout<<"enter size of array : ";
    int size;
    cin>>size;
    int arr[size+1];
    initialize(arr,size);
    print(arr,size);

    heapify(arr,size);

    print(arr,size);

    return 0;
}
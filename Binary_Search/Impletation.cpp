#include<iostream>
using namespace std;

void initialize(int array[] , int size){
    cout<<"---------INITIALIZING THE ARRAY---------"<<endl;
    for(int i=0 ; i<size ; i++){
        cout<<"enter element at "<<i+1<<"th position : ";
        cin>>array[i];
    }
}

int binarysearch(int array[] , int size , int key){
    int start = 0;
    int end = size-1;
    while(start<=end){
        int mid = (start+end)/2;
        if(array[mid]==key){
            return mid;
        }
        else if(array[mid]>key){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }

    return -1;
}

int main(){
    int size;
    cout<<"enter the size of array = ";
    cin>>size;
    int array[size];
    initialize(array,size);

    int key;
    cout<<"enter the element to be found = ";
    cin>>key;

    int index = binarysearch(array,size,key);

    if(index==-1){
        cout<<"element not found"<<endl;
    }
    else{
        cout<<key<<" is at index = "<<index<<endl;
    }

    return 0;
}
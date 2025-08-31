#include<iostream>
using namespace std;

void initialize(int array[] , int size){
    cout<<"---------------INITIALIZATING THE ARRAY-----------------"<<endl;
    for(int i=0 ; i<size ; i++){
        cout<<"enter data at position "<<i+1<<" : ";
        cin>>array[i];
    }
}

void diaplay(int array[] , int size){
    for(int i=0 ; i<size ; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

class minheap{
    public:
    int array[100];
    int size;
    minheap(){
        this->size = 0;
    }

    void print(){
        for(int i=0 ; i<size ; i++){
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }

    void corectposition(){
        int parent = 0;
        while(parent<size){
            int temp = parent;
            int leftchild = temp*2 +1;
            int rightchild =  temp*2 +2;
            if(leftchild<size && array[leftchild]>array[temp]){
                temp = leftchild;
            }
            if(rightchild<size && array[rightchild]>array[temp]){
                temp = rightchild;
            }
            
            if(parent!=temp){
                swap(array[parent],array[temp]);
                parent = temp;
            }
            else{break;}
        }
    }

    int top(){
        return array[0];
    }

    void pop(){
        swap(array[0],array[--size]);
        corectposition();
    }

    void insert(int data){
        array[size] = data;
        int current = size;
        int parent = (current-1)/2;
        while(current>=0){
            if(array[parent]<array[current]){
                swap(array[current],array[parent]);
            }
            if(current==0){break;}
            current = parent;
            parent = (current-1)/2;
        }
        size++;
    }
};

int ksmallest(int array[] , int size , int k){
    cout<<"---------------INSIDE KSMALLEST------------"<<endl;
    minheap h;
    for(int i=0 ; i<k ; i++){
        h.insert(array[i]);
    }
    cout<<"printing the heap after first loop = ";
    h.print();
    for(int i=k ; i<size ; i++){
        if(h.top()>array[i]){
            h.pop();
            h.insert(array[i]);
        }
    }
    cout<<"printing the heap after answer loop = ";
    h.print();
    return h.top();
}

int main(){
    int size;
    cout<<"enter the size of array : ";
    cin>>size;
    int array[size];
    initialize(array,size);

    int k;
    cout<<"enter the value of K : ";
    cin>>k;

    int kth_smallestelement = ksmallest(array,size,k);
    cout<<k<<"th smallest element in array == "<<kth_smallestelement<<endl;

    return 0;
}
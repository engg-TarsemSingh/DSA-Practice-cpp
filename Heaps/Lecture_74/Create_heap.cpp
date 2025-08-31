#include<iostream>
#include<vector>
using namespace std;

class Heap{
    public:
    int array[100];
    int size;

    Heap(){
        this->size = 1;
    }

    void insert(int data){
        array[size] = data;
        int i=size/2;
        while(i>0){
            if(array[i*2]>array[i]){
                swap(array[i],array[i*2]);
            }
            i = i/2;
        }
        size++;
    }

    void deleteroot(){
        if(size==1){
            cout<<"the heap is empty"<<endl;
            return;
        }

        array[1] = array[size-1];
        size--;

        int i=1;
        while(i<size){
            if( (i*2)<size && array[i]<array[i*2]){
                swap(array[i],array[i*2]);
            }
            if( (i*2)<size && array[i]<array[i*2+1]){
                swap(array[i],array[i*2+1]);
            }
            i = i*2;
        }
    }

    void print(){
        for(int i=1 ; i<size ; i++){
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Heap heap1;
    heap1.insert(10);
    cout<<"printing Heap = ";
    heap1.print(); 
    heap1.insert(30);
    cout<<"printing Heap = ";
    heap1.print(); 
    heap1.insert(40);
    cout<<"printing Heap = ";
    heap1.print(); 
    heap1.insert(100);
    cout<<"printing Heap = ";
    heap1.print(); 

    cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
    
    heap1.deleteroot();
    cout<<"printing after deleting root ";
    heap1.print();
    heap1.deleteroot();
    cout<<"printing after deleting root ";
    heap1.print();

    return 0;
}
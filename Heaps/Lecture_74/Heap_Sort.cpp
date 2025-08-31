#include<iostream>
using namespace std;

class Heap{
    public:
    int size;
    int array[100];
    Heap(){
        this->size = 0;
    }

    void insert(int data){
        array[size] = data;

        int temp = size;
        int parent = (temp-1)/2;

        while(parent>=0){
            if(array[parent]<array[temp]){
                swap(array[parent],array[temp]);
            }
            temp = parent;
            parent = (temp-1)/2;
            if(parent==0){break;}
        }
        size++;
    }

    void correctheap(int s){
        if(size==0){return;}
        int start = 0;
        int leftchild = start*2 +1;
        int rightchild = start*2 +2;
        while(start<=(s-1)/2){
            int temp =start;

            if(leftchild<=s && array[leftchild]>array[temp]){
                temp = leftchild;
            }
            if(rightchild<=s && array[rightchild]>array[temp]){
                temp = rightchild;
            }

            if(temp!=start){
                swap(array[temp],array[start]);
            }
            start++;
        }
    }

    void sort(){
        int i = size-1;
        while(i>0){
            swap(array[i],array[0]);
            cout<<"value of i = "<<i<<" array = ";
            print();
            correctheap(i-1);
            i--;
        }
    }

    void print(){
        for(int i=0 ; i<size ; i++){
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }

    int tellsize(){
        return size;
    }
};

int main(){
    Heap h;
    h.insert(-1);
    cout<<"heap after inserting -1 = ";
    h.print();
    h.insert(100);
    cout<<"heap after inserting 100 = ";
    h.print();
    h.insert(39);
    cout<<"heap after inserting 39 = ";
    h.print();
    h.insert(50);
    cout<<"heap after inserting 50 = ";
    h.print();
    h.insert(49);
    cout<<"heap after inserting 49 = ";
    h.print();

    h.sort();
    cout<<"heap after heap sort = ";
    h.print();

    return 0;
}
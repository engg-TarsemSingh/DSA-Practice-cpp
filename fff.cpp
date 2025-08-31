#include<iostream>
#include<vector>
using namespace std;

class MinHeap{
    public:
    vector<int> array;

    void insert(int data){
        array.push_back(data);
        int child = array.size()-1;
        while(child){
            int parent = (child-1)/2;
            if(array[parent]>array[child]){
                swap(array[parent],array[child]);
            }
            child = parent;
        }
    }

    void print(){
        for(int i=0 ; i<array.size() ; i++){
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }

    void correctpositionofroot(vector<int>& array , int parent=0){
        while(parent<array.size()){
            int minimum_child = parent;
            if(parent*2+1<array.size() && array[parent*2+1]<array[minimum_child]){
                minimum_child = parent*2+1;
            }
            if(parent*2+2<array.size() && array[parent*2+2]<array[minimum_child]){
                minimum_child = parent*2+2;
            }
            if(minimum_child==parent){
                break;
            }
            swap(array[parent],array[minimum_child]);
            parent = minimum_child;
        }
    }

    void heapify(vector<int>& given){
        int size = given.size();
        for(int i=(size/2)+1 ; i>=0 ; i--){
            correctpositionofroot(given,i);
        }
    }

    void remove(){
        if(array.size()==0){return;}
        array[0] = array[array.size()-1];
        array.pop_back();
        correctpositionofroot(array);
    }
};

void print(vector<int>& array){
    for(int i=0 ; i<array.size() ; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int main(){
    MinHeap first;

    // first.insert(39);
    // first.insert(-1);
    // first.insert(20);
    // first.insert(6);
    // first.insert(7);

    // cout<<"--------PRINTING THE MINHEAP------------"<<endl;
    // first.print();

    // first.remove();
    // first.remove();

    // cout<<"--------PRINTING THE MINHEAP------------"<<endl;
    // first.print();

    vector<int> given = {5,7,0,-1,-60,-30,100,1,2,3,4,600};
    cout<<"given vector : ";
    print(given);
    first.heapify(given);
    cout<<"after heapify : ";
    print(given);

    return 0;
}
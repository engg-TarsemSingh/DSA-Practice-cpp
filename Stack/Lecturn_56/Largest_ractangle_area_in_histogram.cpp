#include<iostream>
#include<stack>
#include<vector>
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

vector<int> smallernext(int* given , int size){
    vector<int> ans(size);
    stack<int> stak;
    stak.push(-1);
    for(int i=size-1 ; i>=0 ; i--){
        while(stak.top() != -1 && ans[stak.top()]>=given[i]){
            stak.pop();
        }
        ans[i]=stak.top();
        stak.push(i);
    }
    return ans;
}

vector<int> smallerprevious(int* given , int size){
    vector<int> ans(size);
    stack<int> stak;
    stak.push(-1);
    for(int i=0 ; i<size ; i++){
        while(stak.top() != -1 && ans[stak.top()]>=given[i]){
            stak.pop();
        }
        ans[i]=stak.top();
        stak.push(i);
    }
    return ans;
}

int largest_area(int* given , int size){
    cout<<endl;
    cout<<"***************************************"<<endl;
    int area = INT_MIN;
    vector<int> right_most(size);
    right_most = smallernext(given,size);

    cout<<"right_most : ";
    int* ptr_1 = &right_most[0];
    display(ptr_1,size);

    vector<int> left_most(size);
    left_most = smallerprevious(given,size);

    cout<<"left_most : ";
    int* ptr_2 = &left_most[0];
    display(ptr_2,size);

    for(int i=0 ; i<size ; i++){
        int height = given[i];
        if(right_most[i] == -1){
            right_most[i] = size;
        }
        int width = right_most[i] - left_most[i] -1;
        int current_area = height*width;
        area = max(area,current_area);
    }

    cout<<"***************************************"<<endl;
    cout<<endl;
    return area;
}

int main(){
    cout<<"enter the length of array : ";
    int size;
    cin>>size;
    int* array = new int[size];
    initialize(array,size);
    cout<<"displaing the array : ";
    display(array,size);

    cout<<"length of rectangle with max area = "<<largest_area(array,size)<<endl;    

    delete[] array;
    return 0;
}
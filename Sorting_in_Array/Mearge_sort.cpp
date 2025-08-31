#include<iostream>
#include<vector>
using namespace std;

vector<int> initialize(){
    vector<int> ans;
    cout<<"if you want to exit press -1"<<endl;
    while(true){
        int data;
        cout<<"enter data = ";
        cin>>data;
        if(data==-1){
            break;
        }
        ans.push_back(data);
    }
    return ans;
}

void printing(vector<int> sorted){
    for(int i=0 ; i<sorted.size() ; i++){
        cout<<sorted[i]<<" ";
    }
    cout<<endl;
}

vector<int> mergesort(vector<int> giv){
    int size = giv.size();
    if(size==1){
        return giv;
    }

    vector<int> first;
    for(int i=0 ; i<size/2 ; i++){
        first.push_back(giv[i]);
    }

    vector<int> second;
    for(int i=size/2 ; i<size ; i++){
        second.push_back(giv[i]);
    }

    first = mergesort(first);
    second = mergesort(second);

    int i=0 , j=0 , k=0;
    for( ; i<first.size() && j<second.size() ; k++ ){
        if(first[i]>second[j]){
            giv[k]=second[j];
            j++;
        }
        else{
            giv[k]=first[i];
            i++;
        }
    }

    while(i<first.size()){
        giv[k] = first[i];
        k++;
        i++;
    }
    while(j<second.size()){
        giv[k] = second[j];
        k++;
        j++;
    }

    return giv;
}

int main(){
    vector<int> giv = initialize();
    cout<<"preanting sorted array";
    vector<int> sorted = mergesort(giv);
    printing(sorted);

    return 0;
}
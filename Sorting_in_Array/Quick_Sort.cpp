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

void quicksort(vector<int>& array , int start , int end){
    if(start>=end) {return;}
    int key = array[start];

    int j=end , i=start+1 ;
    while(i<=j){
        if(array[i]>=key && array[j]<key){
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
        else if(array[i]<key){
            i++;
        }
        else if(array[j]>=key){
            j--;
        }
    }
    
    swap(array[start],array[j]);

    quicksort(array,start,j-1);
    quicksort(array,j+1,end);
}

int main(){
    vector<int> giv = initialize();
    int size = giv.size();
    cout<<"preanting sorted array";
    quicksort(giv,0,size-1);
    printing(giv);

    return 0;
}
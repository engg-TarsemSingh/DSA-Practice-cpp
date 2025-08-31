#include<iostream>
using namespace std;
int main()
{
    //initializing and declarinf arrray
    int array[6]={23,4,11,44,75,1};
    //accessing element using aaray
    cout<<array[0]<<endl;
    cout<<array[5]<<endl;
   

    //we can also change value of given element
    array[0]=1;
    cout<<"new value of 0 index = "<<array[0]<<endl;

    //traversing in array
    int N=sizeof(array)/sizeof(array[0]);
    int i;
    cout<<"array"<<endl;
    for(i=0;i<N;i++){
        cout<<array[i]<<" ";
    }
   
     return 0;
}

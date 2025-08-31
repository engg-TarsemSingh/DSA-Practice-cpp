#include<iostream>
using namespace std;

int search(int start , int end , int number ){
    int ans = 0;
    while(start<=end){
        int  mid = start+(end-start)/2;
        if(mid*mid<=number){
            ans = mid;
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return ans;
}

double sroot(int number){
    int start = 0;
    int end = number/2;
    double ans = search(start,end,number);
    if(ans*ans!=number){
        cout<<"number of decimalpoint required : ";
        int point;
        cin>>point;
        double temp = 10;
        while(point!=0){
            for(int i=0 ; i<10 ; i++){
                double current = ans+i/temp;
                cout<<"current == "<<current<<endl;
                if(current*current<=number){
                    ans=current;
                }
                else{
                    break;
                }
            }
            point--;
            temp = temp*10;
        }
    }

    return ans;
}

int main(){
    cout<<"enter number : ";
    int number;
    cin>>number;
    double sqroot = sroot(number);
    cout<<"square root of "<<number<<" ==== "<<sqroot<<endl;
    return 0;
}
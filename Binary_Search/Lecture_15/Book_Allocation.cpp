#include<iostream>
using namespace std;

int sum(int books[] , int n){
    int sum = 0;
    for(int i=0 ; i<n ; i++){
        sum += books[i];
    }
    return sum;
}

int is_posibal_to_allocate (int books[] , int n , int m , int max_pages_to_student){
    int ans = 0;
    int current_page = 0;
    int i=0;
    for(; i<n ; i++){
        cout<<"\t i = "<<i+1<<endl;
        cout<<"\t m = "<<m<<endl;
        cout<<"\t current_page = "<<current_page<<endl;
        cout<<"\t current_page+books["<<i<<"] = "<<current_page+books[i]<<endl;
        if(current_page+books[i]<max_pages_to_student){
            current_page += books[i];
        }
        else{
            ans = max(current_page,books[i]);
            current_page = books[i];
            m--;
        }
        if(m==0){
            return 0;
        }
    }

    if(i==n){
        ans = max(ans,current_page);
        return ans;
    }
    return 0;
}

//maximum page allocated to a student should me minimum
int allocation(int books[] , int n , int m){
    int maximum_page_to_student = -1;
    int start = 0;                                       //minimum no. of page allocated to a student
    int end = sum(books,n);                              //maximum no. of page allocated to a student
    int mid = start+(end-start)/2;

    while(start<=end){
        cout<<endl;
        cout<<"************************************************"<<endl;
        cout<<"start : end : mid ::::: "<<start<<" : "<<end<<" : "<<mid<<endl;
        int possible = is_posibal_to_allocate(books,n,m,mid);
        if(possible!=0){
            cout<<"inside posible"<<endl;
            end = mid-1;
            maximum_page_to_student = possible;
        }
        else{
            cout<<"inside not possible"<<endl;
            start = mid+1;
        }
        mid = start+(end-start)/2;

        cout<<"************************************************"<<endl;
        cout<<endl;
    }

    return maximum_page_to_student;
}

int main(){
    cout<<"enter no. of students : ";
    int m;
    cin>>m;
    cout<<"enter no. of books : ";
    int n;
    cin>>n;
    int books[n];
    for(int k=0 ; k<n ; k++){
        cout<<"enter no. of pages in "<<k+1<<" book : ";
        cin>>books[k];
    }

    int maximumpagetostudent = allocation(books,n,m);
    cout<<"maximum pages allocated to a student : "<<maximumpagetostudent<<endl;
    return 0;
}
#include<iostream>
using namespace std;

int main()
{
    int value=30;
    int* ptr_1 = &value;            //ptr_1 is pointer which stores address of int data type
    int** ptr_2 = &ptr_1;           //ptr_2 is pointer which stores address of int*(pointer) data type
    
    cout<<endl<<"value = "<<value<<endl;
    cout<<"address of value = "<<&value<<endl;

    cout<<endl<<"ptr_1 = "<<ptr_1<<endl;
    cout<<"*ptr_1 = "<<*ptr_1<<endl;
    cout<<"address of ptr_1 = "<<&ptr_1<<endl;
  
    cout<<endl<<"ptr_2 = "<<ptr_2<<endl;
    cout<<"*ptr_2 = "<<*ptr_2<<endl;
    cout<<"**ptr_2 = "<<**ptr_2<<endl;
    cout<<"address of **ptr_2 = "<<&ptr_2<<endl;

    return 0 ;
}
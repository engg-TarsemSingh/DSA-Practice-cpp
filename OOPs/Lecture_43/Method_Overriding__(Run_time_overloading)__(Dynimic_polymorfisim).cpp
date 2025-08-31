#include<iostream>
using namespace std ;

class Parent {
    public :
    void print() {
        cout<<"we are in parent class "<<endl;
    }
};

class Child : public Parent {
    public :
    void print() {
        cout<<"we are in child class "<<endl;
    }
};

int main() {
    Parent obj_1 ;
    Child obj_2 ;
    obj_1.print();
    obj_2.print();

    return 1;
}
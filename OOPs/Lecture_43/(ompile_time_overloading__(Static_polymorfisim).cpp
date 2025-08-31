#include<iostream>
using namespace std ;

class Base {
    
    public :

    void print() {
        cout << "my name is '  ' " << endl ;
    }

    void print(string name) {
        cout << "my name is " << name << endl ;
    }

    void print(string name , int age ) {
        cout << "my name is " << name << endl ;
        cout << "my age is " << age << endl ;
    }

    int print ( int age ) {
        return age ;
    }

    int a;
    int b;

    void operator + ( Base ba ) {
        int a = this -> a ;
        int b = ba.b ;
        cout << a-b << endl ;
    }
};

int main () {

    Base obj_1 ;

    //function overloading
    obj_1.print();
    cout << endl ;
    obj_1.print("tarsem");
    cout << endl ;
    obj_1.print("tarsem",20);
    cout << endl ;
    cout << "my age is " << obj_1.print(20) << endl ;
    cout << endl ;

    //operatur overloading
    Base obj_2 ;
    obj_1.a=10;
    obj_2.b=2;
    obj_1+obj_2;

    return 1 ;
}
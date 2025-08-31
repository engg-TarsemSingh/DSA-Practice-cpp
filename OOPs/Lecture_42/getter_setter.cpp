#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class hero {

    //All are Private Variables and Methods
    //Properties of object of hero class
    char name[100] ;
    int health ;
    int level ;

    public :

    char* getname () {
        return name ;
    }

    int gethealth () {
        return health ;
    }

    int getlevel () {
        return level ;
    }

    void setname ( char nam[] ) {
        strcpy(name,nam) ;
    }

    void sethealth ( int healt ) {
        health = healt ;
    }

    void setlevel (int leve ) {
        level = leve ;
    }

};

int main() {

    hero obj_1 ;           //obj_1 is object of class hero
    cout<< "name of hero = " << obj_1.getname() << endl ;
    cout<< "health of hero = " << obj_1.gethealth() << endl ;
    cout<< "level of hero = " << obj_1.getlevel() << endl ;
    
    cout<< "enter the name of hero = " ;
    char name[100] ;
    cin>>name ;
    obj_1.setname(name) ;

    cout<< "enter health of hero = " ;
    int health ;
    cin>>health ;
    obj_1.sethealth(health) ;

    cout<< "enter level of hero = " ;
    int level ;
    cin>>level ;
    obj_1.setlevel(level) ;

    cout<< "name of hero = " << obj_1.getname() << endl ;
    cout<< "health of hero = " << obj_1.gethealth() << endl ;
    cout<< "level of hero = " << obj_1.getlevel() << endl ;

}
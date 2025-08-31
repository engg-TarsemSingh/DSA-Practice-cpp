#include<iostream>
#include<deque>
using namespace std;

int main ()
{
    deque<int> de ;                                //a deque is created of data type int and name de

    de.push_back(5);                               //5 is added at the end of deque
    de.push_front(1);                              //1 is added at the front of deque 
    de.push_front(3);  de.push_front(6);
    for ( int i :de )                              //to print deque
    {
        cout<<i<<"  ";
    }

    de.pop_back();                                  //last element of deque is deleted
    cout<<endl<<"last element is deleted"<<endl;
    for ( int i :de )                         
    {
        cout<<i<<"  ";
    }

    cout<<endl<<"the first element of deque - ";
    cout<<de.at(0)<<endl;                                 //to print element at any position

    cout<<"first element - "<<de.front()<<endl;
    cout<<"last element - "<<de.back()<<endl;

    cout<<"deleting the elements "<<endl;
    de.erase(de.begin(),de.begin()+1);             //this will delete element from beginning to bignning + 1
    for ( int i :de )                         
    {
        cout<<i<<"  ";
    }

    return 0 ;
}
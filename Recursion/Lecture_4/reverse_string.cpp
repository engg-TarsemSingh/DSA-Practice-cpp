#include<iostream>
#include<string>
using namespace std ;

void reverse_string(string& given , int start)
{
    if(start>=given.size()/2)
    {
        return ;
    }
    swap(given[start],given[given.size()-1-start]);
    reverse_string(given,start+1);
}

int main()
{
    string given ;
    cout<<"enter the string which is to be reversed = ";
    getline(cin,given);
    int start=0;;
    reverse_string(given,start);
    cout<<"reversed string = "<<given<<endl;

    return 0;
}
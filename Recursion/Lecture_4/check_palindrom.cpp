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

bool is_palindrom(string given , int start=0)
{
    if(start>given.size()/2)
    {
        return true;
    }
    if(given[start]!=given[given.size()-1-start])
    {
        return false;
    }

    return is_palindrom(given,start+1);
}

int main()
{
    string given ;
    cout<<"enter the string which is to be reversed = ";
    getline(cin,given);
    int start=0;;
    reverse_string(given,start);
    cout<<"the reversed string = "<<given<<endl;
    if(is_palindrom(given))
    {
        cout<<"the given string is palindrom "<<endl;
    }
    else{
        cout<<"the given string is not palindrom "<<endl;
    }

    return 0;
}
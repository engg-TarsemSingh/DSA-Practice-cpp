#include<iostream>
using namespace std;

int a= 5 , b=5 , c=2;

void continue_statement()
{
    int d;
    for(d=1;d<10;d++) {
        if(d==3){
            continue;
        }
        cout<<d<<endl;
    }
};

void break_statement()
{
    int e;
    cout<<"break"<<endl;
    for(e=0;e<10;++e) {
        if(e==3){
            break;
        }
        cout<<endl<<e<<endl;
    }
}

int main()
{
    continue_statement();
    break_statement();

return 0;
}
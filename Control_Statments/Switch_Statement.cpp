#include<iostream>
using namespace std;

void first ( int a,int  b ,int c )
{
    switch (a*c){
        case 30 :
            cout<<"first case "<<endl<<(a*b)<<endl;
            break;
        case 10 :
            cout<<"second case"<<endl<<(a*b)<<endl;
            break;
        default:
            cout<<"default";
            break;

    }
}

void second(int a, int b, int c)
{
    switch(a+b)
    {
        case 10:
         switch(a-b)
         {
             case 0:
                  cout<<"switch a-b "<<endl;
                  break;
            default:
            cout<<"default1"<<endl;
         };

         switch(a*b)
         {
              case 25:
                  cout<<"switch a+b"<<endl;
            default:
            cout<<"default2"<<endl;
          };
        break;
        

        case 4:
            cout<<"case 4"<<endl;
        break;



    }
}

int main()
{
    int a,b;
    cout<<"enter value of a "<<endl;
    cin>>a;
    cout<<"enter the value of b"<<endl;
    cin>>b;
    int c = 2;
    first(a,b,c);
    second(a,b,c);

    return 0;

}
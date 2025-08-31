#include<iostream>
using namespace std;
                                                    //creating a macro named PI whoes value is 3.41 .
#define PI 3.41                                     //where ever there is PI in code it will be replaced by 3.41 .
                                                    //PI is micro not variable so it will not take any space in memory .
int main()                                          //3.41 is value assigned to PI during compile time .
{                                                   //its value cannot be modified in code .
    cout<<"enter radious of circle = ";
    int radius;
    cin>>radius;
    cout<<"the area of circel is = "<<PI*radius*radius<<endl;

    return 0 ;
}                                   
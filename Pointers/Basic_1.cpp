#include<iostream>
using namespace std;

int main()
{
    int array[10]={1,14,78,4,5,6,7,8,9,10};

    cout<<"step 1th cout array = "<<array<<endl;
    cout<<"step 2nd cout array[0] = "<<array[0]<<endl;
    cout<<"step 3rd cout &array[0] = "<<&array[0]<<endl;
    cout<<"step 4rd cout *array = "<<*array<<endl;
    cout<<"stap 5th cout *array+1 = "<<*array+1<<endl;
    cout<<"step 6th cout *(array+1) = "<<*(array+1)<<endl;
    cout<<"step 7th cout &array[0]+1 = "<<&array[0]+1<<endl;
    cout<<"step 8th cout &array = "<<&array<<endl;

    char ch[]={'a','d','e','f','u','f','w','o','p','\n'};

    cout<<"step 1st cout ch = "<<ch<<endl;
    cout<<"step 2nd cout ch[0] = "<<ch[0]<<endl;
    cout<<"step 3rd cout *ch = "<<*ch<<endl;
    cout<<"step 4th cout &ch = "<<&ch<<endl;
    cout<<"step 5th cout &ch[0] = "<<&ch[0]<<endl;

    return 0;
}
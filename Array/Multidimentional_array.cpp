#include<iostream>
using namespace std;
int main()
{
    //2-D array
    int array[3][4]={
        {33,1,82,21},
        {70,5,0,10},
        {79,2,54,1},
    };

    //traversing in 2-D array
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<"array["<<i<<"]["<<j<<"]"<<"="<<array[i][j]<<endl;
        }
    }

    //3-D array
    //in this 3 is no. of array , 2 is rows and 3 is no. of columns 
    int array_1[3][2][3]=
    {
        {
            {22,63,0},
            {34,5,2}
        },
        {
            {43,56,0},
            {56,23,04}
        },
        {
            {07,75,34},
            {77,66,444}
        }
    
    };

    cout<<"3 dimensional array"<<endl;
    //k is no. of arrays
    for(int k=0;k<3;k++){
        cout<<endl<<endl;
        for(int i = 0; i<2;i++){
            cout<<endl;
            for(int j=0;j<3;j++){
                cout<<array_1[k][i][j]<<" ";
            }
        }
    }
    return 0;
}
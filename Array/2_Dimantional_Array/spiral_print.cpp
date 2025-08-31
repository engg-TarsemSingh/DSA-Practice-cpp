#include <iostream>
using namespace std;

void display(int r, int c, int arr[][4])
{
    cout << "displaying the matrix " << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
}

void spiralprint(int row, int column, int arr[][4])
{
    cout << "spiral print " << endl;
    int rup = 0, cleft = 0, rdo = row - 1, cright = column - 1, rr = 0, cc = 0;
    int element = row * column;
    for (int count = 0; count < element;)
    {
        for (; cc<=cright ; cc++)
        {
            cout << arr[rr][cc] << "  ";
            count = count + 1;
            cout<<" first "<<endl;
        }
        cc=cc-1;
        rup = rup + 1;
        rr =rr+1 ;

        for (; rr<=rdo ; rr++)
        {
            cout << arr[rr][cc] << "  ";
            count = count + 1;
            cout<<" second "<<endl;
        }
        cright -= 1;
        cc =cc-1;
        rr=rr-1;


        for (; cc>=cleft ; cc--)
        {
            cout << arr[rr][cc]<<"  ";
            count = count + 1;
            cout<<" third "<<endl;
        }
        rdo -= 1;
        rr=rr-1;
        cc=cc+1;

        for (; rr>=rup ; rr--)
        {
            cout << arr[rr][cc]<<"  ";
            count = count + 1;
            cout<<" forth "<<endl;
        }
        rr=rr+1;
        cc=cc+1;
        cleft += 1;
    }
}

int main()
{
    int array[5][4] = {1, 5, 3, 6, 7, 34, 23, 9, 07, 23, 44, 5,7,9,6,0,0,0,8,7};
    cout<<endl;
    display(5,4, array);
    spiralprint(5,4, array);

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

void display(int arry[], int size)
{
    cout << "desplaying all the elements of array " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arry[i] << "  ";
    }
    cout << endl;
}

void findposition(int array[], int size, int Element)
{
    vector<int> find;
    for (int i = 1; i<=size; i++)
    {
        if (array[i] == Element)
        {
            find.push_back(i);
        };
    };
    cout<<"last position of element "<<Element<<" is "<<find.back();
    cout<<endl;
}

int main()
{
    cout << "enter the size of array " << endl;
    int size;
    cin >> size;
    int array[size];
    cout << "enter the elements of array " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    cout << endl;

    cout << "enter the element whose last position is to be found " << endl;
    int Element;
    cin >> Element;
    findposition(array,size,Element);
    display(array,size);
    return 0;
}
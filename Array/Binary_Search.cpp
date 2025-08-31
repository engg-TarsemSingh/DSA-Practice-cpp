#include <iostream>
using namespace std;

void initialization(int arr[], int size)
{
    cout << "enter the elements of array" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
}

int binarysearch(int arr[], int size)
{
    cout << "enter the number to be found " << endl;
    int find;
    cin >> find;
    int start = 0, end = size - 1, mid = (start / 2) + (end / 2);
    for (; start <= end;)
    {
        if (find == arr[mid])
        {
            cout << "the element " << find << " is at " << mid << endl;
            return 0;
        }
        if (arr[mid] > find)
        {
            end = mid - 1;
        }
        if (arr[mid] < find)
        {
            start = mid + 1;
        }
        mid = (start / 2) + (end / 2);
    }
    if (find != arr[mid])
    {
        cout << "element " << find << " is not present in array " << endl;
    }
    return 0;
}

void display(int arr[], int size)
{
    cout << "displaying the array" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int main()
{
    cout << "enter the size of array" << endl;
    int size;
    cin >> size;
    int arr[size];
    initialization(arr, size);
    display(arr, size);
    binarysearch(arr, size);
}
#include <iostream>
#include <vector>
using namespace std;

void install(vector<int> &n, int size)
{
    for (int i = 0; i < size; i++)
    {
        int a;
        cout << "enter the element " << i + 1 << " of array = ";
        cin >> a;
        n.push_back(a);
    }
}

void display(vector<int> n)
{
    cout<<"displaying the vecor "<<endl;
    for (int i = 0; i < n.size(); i++)
    {
        cout << n[i] << "  ";
    }
    cout << endl;
}

vector<int> game(vector<int> &nums)
{
    vector<int> arr(nums.size(),0);
    int minimum=0 , minimum_index=0 ;

    for (int i=0 ; i<arr.size(); )
    {
        int count = i + 1;
        minimum = INT_MAX;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] < minimum)
            {
                minimum = nums[j];
                minimum_index = j;
            }
        }
        i++;
        arr[count]=minimum;
        nums.erase(nums.begin() + minimum_index);

        minimum = INT_MAX;
        for (int j = 0; j< nums.size();j++)
        {
            if (nums[j] < minimum)
            {
                minimum = nums[j];
                minimum_index = j;
            }
        }
        i++;
        count--;
        arr[count] = minimum;
        nums.erase(nums.begin() + minimum_index);

    }
    return arr;
}

int main()
{
    vector<int> given;
    int size;
    cout << "enter the size of vector = ";
    cin >> size;
    install(given, size);
    display(given);
    vector<int> answer = game(given);
    display(answer);
    cout << "size of first vector = " << given.size();

    return 0;
}
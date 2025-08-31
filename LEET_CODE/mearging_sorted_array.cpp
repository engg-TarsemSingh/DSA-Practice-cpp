#include <iostream>
#include <vector>
using namespace std;

void initialize(vector<int> &num1, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "enter the " << i + 1 << " element = ";
        int a;
        cin >> a;
        num1.push_back(a);
    }
}

void default_size ( vector<int>& given , int size )
{
    for(int i=0 ; i<size ; i++ )
    {
        given.push_back(0);
    }
}

void display(vector<int> arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int k=nums1.size()-1 , main=m-1 , second=n-1 ;
    for( ; k>=0 ; k--)
    {
        if(second==-1)
        {
            break;
        }
        else if(main==-1)
        {
            for(; second>=0 ; second--,k--)
            {
                nums1[k]=nums2[second];
            }
            break;
        }
        else if(nums1[main]>nums2[second])
        {
            nums1[k]=nums1[main];
            main--;
        }
        else
        {
            nums1[k]=nums2[second];
            second--;
        }
    }
}

int main()
{
    vector<int> first, second;
    int first_size, second_size;
    cout << "enter the size of first element = ";
    cin >> first_size;
    initialize(first, first_size);
    cout << "enter the size of second element = ";
    cin >> second_size;
    initialize(second, second_size);
    default_size(first,second_size);

    merge(first , first_size , second, second_size );

    cout << "displaying the first array " << endl;
    display(first, first.size());

    return 0;
}
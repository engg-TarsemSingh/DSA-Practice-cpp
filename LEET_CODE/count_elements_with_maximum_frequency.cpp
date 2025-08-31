#include<iostream>
#include<vector>
using namespace std;

bool is_absent ( vector<int> given , int val)
{
    for(int i=0 ; i<given.size() ; i++)
    {
        if(given[i]==val)
        {
            return false;
        }
    }
    return true;
}

int maxFrequencyElements(vector<int>& nums) {
    vector<int> already ;
    vector<int> freq ;
    int ans=0;

    for(int i=0 ; i<nums.size() ; i++)
    {
        cout<<endl;
        cout<<"element of nums = "<<nums[i]<<endl;
        cout<<"output of is_absent = "<<is_absent(already,nums[i])<<endl;

        if( is_absent(already,nums[i]) )
        {
            int frequency=0;
            for( int j=i ; j<nums.size() ; j++ )
            {
                if(nums[i]==nums[j])
                {
                    frequency++;
                }
                already.push_back(nums[i]);
            }
            cout<<"frequency = "<<frequency<<endl<<endl;
            freq.push_back(frequency);
        }
    }
    //counting maximum frequency
    int max=0;
    for( int i=0 ; i<freq.size() ; i++ )
    {
        if(freq[i]>max)
        {
            max=freq[i];
        }
    }
    //counting number of maximum accurances
    for( int i=0 ; i<freq.size() ; i++ )
    {
        if(freq[i]==max)
        {
            ans=max+ans;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums;
    int size;
    cout<<"enter the size  of vector = ";
    cin>>size;
    for( int i=0 ; i<size ; i++)
    {
        cout<<"enter the "<<i+1<<" element = ";
        int a;
        cin>>a;
        nums.push_back(a);
    }

    int ans=maxFrequencyElements(nums);
    cout<<"answer = "<<ans<<endl;

    return 0;
}
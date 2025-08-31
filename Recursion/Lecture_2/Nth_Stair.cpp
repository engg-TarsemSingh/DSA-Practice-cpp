#include<iostream>
using namespace std;

int number_of_ways(int n)
{
    if(n<0)
    {
        return 0;                                                          //if the peron is not at any stair ways to return are zero
    }
    if(n==0)
    {
        return 1;                                                          //if the person is at 1st stair ways to reach 1st stair is 1
    }
    int ways = number_of_ways(n-1)+number_of_ways(n-2); 

    return ways;                                                           //if the person want to reach last stair either he will reach from n-1 or n-2 stair
}

int main()
{
    int toreach ;                                                           //stair to reach
    cout<<"enter the number of stair required to reach = ";                 //person can climb one or two stair at a time
    cin>>toreach;
    int answer = number_of_ways(toreach);
    cout<<"no. of ways to reach "<<toreach<<" th stair is = "<<answer;

    return 0;
}
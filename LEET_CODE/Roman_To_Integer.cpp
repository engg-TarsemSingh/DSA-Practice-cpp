#include<iostream>
#include<string>
using namespace std;

int romanToInt(string s) 
{
    int ans=0;
    char next='k';
    for(int i=0 ; i<s.size() ; i++)
    {
        if(i<s.size()-1)
        {
            next=s[(i+1)];
        }

        if(s[i]=='I' && (next=='V' || next=='X'))
        {
            ans=ans-1;
        }
        else if(s[i]=='X' && (next=='L' || next=='C'))
        {
            ans=ans-10;
        }
        else if(s[i]=='C' && (next=='D' || next=='M'))
        {
            ans=ans-100;
        }
        else 
        {
            switch(s[i])
            {
                case 'I':
                ans=ans+1;
                break ;

                case 'V':
                ans=ans+5;
                break ;

                case 'X':
                ans=ans+10;
                break ;

                case 'L':
                ans=ans+50;
                break ;

                case 'C':
                ans=ans+100;
                break ;

                case 'D':
                ans=ans+500;
                break ;

                case 'M':
                ans=ans+1000;
                break ;
            }
        }
    }
    return ans;
}

int main()
{
    string given ;
    cout<<"enter the value of string = ";
    cin>>given;
    int ans=romanToInt(given);
    cout<<"answer = "<<ans<<endl;

    return 0;
}
#include<iostream>
using namespace std;

void right_on_left(int R )
{
    for(int i=0 ; i<R ; i++)
    {
        for(int j=0 ; j<=i ; j++)
        {
            cout<<"*"<<"  ";
        };
        cout<<endl;
    };

    for(int i=0 ; i<R ; i++)
    {
        for(int j=0 ; j<=i ; j++)
        {
            int w=i+1;
            cout<<w<<"  ";
        }
        cout<<endl;
    }

    int k=1;
    for(int i=0 ; i<R ; i++)
    {
        for(int j=0 ; j<=i ; j++)
        {
            cout<<k<<"  ";
            k=k+1;
        }
        cout<<endl;
    }

    for(int i=0 ; i<R ; i++)
    {
        int o=i+1;
        for(int j=0 ; j<=i ; j++)
        {
            cout<<o<<"  ";
            o=o+1;
        }
        cout<<endl;
    }

    for(int i=0 ; i<R ; i++)
    {   
        int p=i+1;
        for(int j=0 ; j<=i ; j++)
        {
            cout<<p<<"  ";
            --p;
        }
        cout<<endl;
    }
}

void right_on_right(int R)
{
    for(int i=0 ; i<R ; i++)
    {
        for(int j=0 ; j<R ; j++)
        {
            if(j>=R-1-i)
            {
                cout<<"*"<<"  ";
            }else{
                cout<<" "<<"  ";
            }
        }
        cout<<endl;
    }
    
}

void rightangle_on_top_left(int R)
{
    for(int i=0 ; i<R ; i++)
    {
        for(int j=0 ; j<=R-1-i ;j++)
        {
            cout<<"*"<<"  ";
        }
        cout<<endl;
    }
}

void rightangle_on_top_right(int R)
{
    for(int i=0 ; i<R ; i++)
    {
        for(int j=0 ; j<R ; j++)
        {
            if(j>=i){
                cout<<"*"<<"  ";
            }else
            {
                cout<<" "<<"  ";
            }
        }
        cout<<endl;
    }
}

void triangle(int R)
{
    //PRIENT RIGHT ANGLE ON RIGHT TRIANGLE
    for(int i=0 ; i<R ; i++)
    {   
        int f=1;
        for(int j=0 ; j<R ; j++)
        {   
            if(j>=R-1-i)
            {   
                cout<<f<<"  ";
                f=f+1;
            }
            else{
                cout<<" "<<"  ";
            }
        }

        //PRINT SECONF RIGHT ANGLE ON LEFT TRIANGL
        if (i>=1)
        {
            for(int k=i ; k>=1 ; k-- )
            {
                cout<<k<<"  ";
            }
        }
        cout<<endl;
    }
}

void final(int R)
{
    for(int i=0 ; i<R ; i++)
    {  
      int x=1;
      int y=1;
      for(int j=0 ; j<R ; j++)
     {
       if(j>R-1-i)
         {
          cout<<"*"<<"  ";
         }
          else{
          cout<<y<<"  ";
           y=y+1;
         };
        x=x+1;
     }
       
     if( x>R && x<R+R )
     {
        for(int j=R ; j>=1 ; j--)
        {
           if(j<=R-i) 
           {
            cout<<j<<"  ";
           }
           else{
            cout<<"*"<<"  ";
           }
        }
     }
     cout<<endl;
    }
}

int main()
{
    cout<<"enter the rows required"<<endl;
    int R;
    cin>>R;
    //cout<<"right angle on left side triangle"<<endl;
    //right_on_left(R);
    //cout<<endl;

    //cout<<"right angle on right side triandle"<<endl;
    //right_on_right(R);
    //cout<<endl;

    //cout<<"right angle on top left side of triangle"<<endl;
    //rightangle_on_top_left(R);
    //cout<<endl;

    //rightangle_on_top_right(R);
    //cout<<endl;

    //cout<<"triangle payyren"<<endl;
    //triangle(R);

    cout<<"final pattern"<<endl;
    final(R);

    return 0 ;
}
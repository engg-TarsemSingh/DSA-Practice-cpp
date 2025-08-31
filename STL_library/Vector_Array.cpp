#include<iostream>
#include<vector>
using namespace std;

void display ( vector <int> V )
{
    cout<<"displaying the vector "<<endl;
    int Size=V.size();                                            //array_name . size is used to find size
    for(int i=0 ; i<Size ; i++ )
    {
        cout<<V[i]<<"  ";
    }
    cout<<endl;
}

void insert ( vector <int> &V)
{
    cout<<"enter the element to be inserted "<<endl;
    int E , P ;
    cin>>E;
    cout<<"current number of elements in array "<<V.size()<<endl;
    cout<<"enter the position in which it is to be inseted "<<endl;
    cin>>P;
    V.insert(V.begin()+P-1 , E );                                  //V.begin shows the position of first element
}

void deletion ( vector <int> &deletion )
{
    cout<<"number of element present "<< deletion.size() <<endl;
    cout<<"enter the position whose element is to be deleted "<<endl;
    int D;
    cin>>D;
    deletion.erase(deletion.begin()-D);
}

int main()
{
    vector<int> V ;                                              //this is declaring an dynamic array

    cout<<"enter the number upto which element is to be inserted"<<endl;
    int S;
    cin>>S;
    for(int i=0 ; i<S ; i++)
    {
        int element;
        cin>>element;
        V.push_back(element);
    }
    display(V);
    insert(V);
    display(V);
    deletion(V);
    display(V);

    return 0 ;
}

    //v.capacity()           v is name of vactor               this is used to chack capacity of v vactor
    //v.push_back(4)         4 is the element to be added      this is used to add element on end of vactor
    //v.pop_back()           to delete last element of vector
    //v.front()              to get first element of vector
    //v.back()               to get last element of vector
    //v.clear()              it make the size of vector 0       but the capacity will remain same
    
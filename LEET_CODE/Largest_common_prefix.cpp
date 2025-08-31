#include<iostream>
#include<string>
#include<vector>
using namespace std;

void initialize(vector<string>& given){
    for(int i=0 ; i<given.size() ; i++){
        cout<<"enter string at position "<<i+1<<" : ";
        string temp;
        cin>>temp;
        given[i] = temp;
    }
}

void display(vector<string>& given){
    cout<<"[";
    for(string c : given){
        cout<<" ["<<c<<"] ";
    }
    cout<<"]"<<endl;
}

string common_prefix(vector<string>& strs){
    string ans = "";
    while (true) {
        string common = strs[0];
        cout<<endl;
        cout<<"*******************************************"<<endl;
        cout<<"given array : "; display(strs);
        cout<<"common : "<<common<<endl;
        for (string& s : strs) {
            cout<<"-------------------------------------------"<<endl;
            cout<<"current tring : "<<s<<endl;
            if (s == "" || s[0] != common[0]) {
                cout<<"entring the return condition"<<endl;
                return ans;
            } else {
                s.erase(s.begin());
                cout<<"erasing the first element of string : "<<s<<endl;
            }
            cout<<"-------------------------------------------"<<endl;
        }
        ans += common[0];
        cout<<"current ans ======== "<<ans<<endl;
        cout<<"*******************************************"<<endl;
        cout<<endl;
    }
    return ans;
}

int main(){
    cout<<"enter the size of list : ";
    int size;
    cin>>size;

    vector<string> given(size);
    initialize(given);
    display(given);

    string prefix = common_prefix(given);
    cout<<endl<<"common prefix from the stringd : "<<prefix<<endl;
    return 0;
}
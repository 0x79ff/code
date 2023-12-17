#include <bits/stdc++.h>
using namespace std;

string t = "You are right, but ";
int main()
{
    string s;
    getline(cin,s);
    if(s.size()<19){
        cout<<"Human";
        return 0;
    }
    bool ai=1;
    for(int i=0;i<19;i++){
        if(s[i]!=t[i]){
            ai=0;
        }
    }
    if(ai){
        cout<<"AI";
    }
    else{
        cout<<"Human";
    }


    return 0;
}
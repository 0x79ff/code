#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"


ll n;

void solve()
{
    bool a,b,c; a=b=c=0;
    vector<array<ll,2>> u,v;
    
    cin>>n;
    for(int i=1;i<=n;i++){
        ll row,col;cin>>row>>col;
        if(row==1 && col==-1) a=1;
        if(row==2 && col==0)  b=1;
        if(row==1 && col==1)  c=1;
        
        if(col>=0){
            u.push_back({col,row});
        }
        if(col<=0){
            v.push_back({-col,row});
        }
    }
    
    sort(u.begin(),u.end());
    sort(v.begin(),v.end());
    bool uempty = u.empty(),vempty = v.empty();
    bool uok=0,vok=0;
    for(int i=0;i+1<u.size();i++){
        if(u[i+1][0]-u[i][0]<=1 && u[i+1][1]!=u[i][1]) uok=1;       
    }

    for(int i=0;i+1<v.size();i++){
        if(v[i+1][0]-v[i][0]<=1 && v[i+1][1]!=v[i][1]) vok=1; 
    }

    if(u.empty()&&v.empty()){
        cout<<3<<endl;
        return;
    }
    if(u.empty()||v.empty()){
        if(u.empty()){
            if(vok) cout<<2<<endl;
            else{
                if(a) cout<<2<<endl;
                else cout<<3<<endl;
            }
        }
        if(v.empty()){
            if(uok) cout<<2<<endl;
            else{
                if(c) cout<<2<<endl;
                else cout<<3<<endl;
            }
        }
        return;
    }

    if(uok && vok){
        cout<<0<<endl;
        return;
    }
    if(uok || vok){
        cout<<1<<endl;
        return;
    }
    if(a && c){
        cout<<1<<endl;
    }
    else{
        cout<<2<<endl;
    }
    
}

int main()
{
    IOS;
    int T;cin>>T;
    while(T--){
        solve();
    }
    
    return 0;
}
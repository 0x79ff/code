#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"




void solve()
{
    ll x,y;
    cin>>x>>y;
    if(y%2==0){
        cout<<x*(y/2)<<endl;
    }
    else{
        cout<<x*(y/2)<<endl;
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
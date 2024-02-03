#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"




void solve()
{
    ll n;
    cin>>n;
    if(n%6==0){
        cout<<n/6<<endl;
    }
    else{
        cout<<2*(n/6)<<endl;
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
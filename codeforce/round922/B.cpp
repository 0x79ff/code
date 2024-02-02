#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"




void solve()
{
    ll n;
    cin>>n;
    vector<array<ll,2>> v;
    for(int i=0;i<n;i++){
        ll t;cin>>t;
        v.push_back({t,0});
    }
    for(int i=0;i<n;i++){
        ll t;cin>>t;
        v[i][1]=t;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        cout<<v[i][0]<<" ";
    }
    cout<<endl;
        for(int i=0;i<n;i++){
        cout<<v[i][1]<<" ";
    }
    cout<<endl;
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
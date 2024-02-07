#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

ll n;

void solve()
{
    cin>>n;
    vector<ll> v;
    for(int i=1;i<=n;i++){
        ll t;cin>>t;
        v.push_back(t);
    }
    sort(v.begin(),v.end());
    ll ans =0;
    for(int i=0;i<n;i++){
        v[i] = min(v[i],2*v[0]);
    }
    for(int i=0;i<n;i++){
        ans += v[i]*(n-1-i);
    }   
    
    ans*=4;
    cout<<ans<<endl;

}

int main()
{
    IOS;
    int T=1;cin>>T;
    while(T--){
        solve();
    }
    
    return 0;
}
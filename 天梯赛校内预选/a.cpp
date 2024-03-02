#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 1e5+10;
const ll mod = 1e9+7;

void solve()
{
    ll n,k;
    cin>>n>>k;
    vector<ll> mx(k,0);
    for(int i=1;i<=n;i++){
        ll t;cin>>t;
        mx[i%k]=max(mx[i%k],t);
    }
    ll ans=0;
    for(int i=0;i<k;i++){
        ans+=mx[i];
    }
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

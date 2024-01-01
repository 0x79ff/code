#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll n,m,s,t;

ll quick_pow(ll x,ll y)
{
    ll re=1;
    x%=mod;
    while(y){
        if(y&1) re=re*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return re;
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>s>>t;
    vector<array<ll,2>> a;
    for(int i=1;i<=m;i++){
        ll x,l,r;
        cin>>x>>l>>r;
        a.push_back({l,-1});
        a.push_back({r+1,1});
    }
    sort(a.begin(),a.end());
    ll ans = 1,num = n,pos = s;
    for(auto x:a){
        ans = ans*quick_pow(num,x[0]-pos)%mod;
        pos = x[0];
        num+=x[1];
    }
    ans = ans*quick_pow(num,t+1-pos)%mod;
    cout<<ans;

    return 0;
}
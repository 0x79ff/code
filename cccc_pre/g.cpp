#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 1e6+10;
const ll mod = 10007;

ll a,b,k,n,m;
ll p[N];



ll quick_pow(ll x,ll y){
    ll re=1;
    x%=mod;
    while(y){
        if(y&1){
            re=re*x%mod;
        }
        x=x*x%mod;
        y>>=1;
    }
    return re;
}

ll inv(ll x){
    return quick_pow(x,mod-2);
}

ll C(ll x,ll y){
    return p[y]*inv(p[x])%mod*inv(p[y-x])%mod;
}

void solve()
{
    cin>>a>>b>>k>>n>>m;
    p[0]=1;
    for(int i=1;i<=N-10;i++) p[i] = p[i-1]*i%mod;

    ll ans = 1;
    ans*=quick_pow(a,n);ans%=mod;
    ans*=quick_pow(b,m);ans%=mod;
    ans*=C(n,k);ans%=mod;
    cout<<ans<<endl;
}

int main()
{
    IOS;
    int T=1;//cin>>T;
    while(T--){
        solve();
    }
    
    return 0;
}

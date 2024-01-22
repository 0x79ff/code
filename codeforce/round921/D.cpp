#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll N = 2e5+300;

ll n,m,k,sum;
ll A[N];


ll quickpow(ll x,ll y)
{
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

ll inv(ll x)
{
    return quickpow(x,mod-2)%mod;
}

ll C(ll x,ll y)
{
    if(x<0 || x>y) return 0;
    return A[y]*inv(A[x])%mod*inv(A[y-x])%mod;
}


void solve()
{
    cin>>n>>m>>k;
    sum=0;
    for(int i=1;i<=m;i++){
        ll a,b,f;
        cin>>a>>b>>f;
        sum+=f;sum%=mod;
    }    
    ll p = inv(C(2,n)),q = (C(2,n)-1)*(inv(C(2,n)))%mod;
    ll t1=0,t2=0;
    for(int i=0;i<=k;i++){
        t1+=C(i,k)*quickpow(q,k-i)%mod*quickpow(p,i)%mod*i%mod;
        t1%=mod;

        t2+=C(i,k)*quickpow(q,k-i)%mod*quickpow(p,i)%mod*C(2,i)%mod;
        t2%=mod;
    }
    ll ans = 0;
    ans += sum*t1%mod;ans%=mod;
    ans += m*t2%mod;ans%=mod;
    cout<<ans<<"\n";

}

int main()
{
    //pre
    A[0]=1;
    for(int i=1;i<=N-100;i++){
        A[i]=A[i-1]*i%mod;
    }

    
    int T;cin>>T;
    while(T--){
        solve();
    }
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

//补充一下三类斯特林数！

const ll mod = 1e9+7;
const ll N = 2e5+100;

ll A[N];
ll n,m;


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
    cin>>n>>m;
    ll ans = 0;
    for(int i=0;i<=m;i++){
        ll t;
        if(i%2==0) t=1;
        else t=-1;
        ans += t*C(i,m)%mod*quickpow(m-i,n)%mod;
        ans += mod; ans%=mod;
        // cout<<A[m]<<" "<<A[i]<<" "<<A[m-i]<<endl;
        // cout<<C(i,m)<<" "<<quickpow(m-i,n)<<endl;
       // cout<<ans<<endl;
    }
    cout<<ans*inv(A[m])%mod<<endl;
}

int main()
{
    IOS;

    A[0]=1;
    for(int i=1;i<=N-100;i++){
        A[i] = A[i-1]*i%mod;
    }
    
    int T=1;//cin>>T;
    while(T--){
        solve();
    }
    
    return 0;
}
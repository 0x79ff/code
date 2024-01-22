#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll mod = 1e9+7;
const ll N = 2e5+100;

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

ll n,m,k;

// max = 2k convert to <= 2k
//then f(2k) - f(2k-2)

ll f(ll n,ll m,ll k)
{
    if(k>=min(n,m)) return C(n,m+n);
    else return C(k,n+m); 
}

void solve()
{
    cin>>n>>m>>k;
    cout<<(f(n,m,k) - f(n,m,k-1) + mod)%mod<<endl;
}

int main()
{
    IOS;
    //pre
    A[0]=1;for(int i=1;i<=N-100;i++) A[i] = A[i-1]*i%mod;
    int T;cin>>T;
    while(T--){
        solve();
    }
    
    return 0;
}
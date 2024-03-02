#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

ll n,m,k;
const ll mod =  998244353;
const ll N = 1e5+10;
ll a[N];

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

ll inv(ll x){
    return quick_pow(x,mod-2);
}

ll C(ll x,ll y)
{
    //c x y
    if(y<0 || y>x){
        return 0;
    }  
    else{
        return a[x]*inv(a[x-y])%mod*inv(a[y])%mod;
    }
}


ll fun(ll n,ll m,ll k)
{
    if(m<k || m>n){
        return 0;
    }

    if(k==0){
        if(m==0) return 1;
        else{
            return 0;
        }
    }
    
    ll re=0;

    for(ll i=0;i<=n-m+1 && n-m <= n-(k+1)*i;i++)
    {
        int j=i%2?-1:1;
        re = re + j*C(n-(k+1)*i,n-m)%mod*C(n-m+1,i)%mod;
        re+=mod;re%=mod;
    }
    return re;
}


int main()
{
    IOS;
    a[0]=1;
    for(int i=1;i<=N-5;i++){
        a[i]=a[i-1]*i%mod;
    }

    cin>>n>>m>>k;
    ll ans = 0;

    ans+=fun(n,m,k);ans%=mod;
    ans+=mod-fun(n,m,k-1);ans%=mod;
    ans+=mod;ans%=mod;
    cout<<ans;

    return 0;
}
/*
9 7 5
9
*/
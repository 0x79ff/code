#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

const ll mod = 999999893;

ll n;

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


void solve()
{
    cin>>n;
    if(n==1){
        cout<<0<<"\n";
        return;
    }   
    ll k = n/2; 
    if(n%2==1){
        cout<< (quickpow(2,k)-1 + mod)%mod*inv((quickpow(2,2*k) + quickpow(2,k+1) - 1 + mod)%mod)%mod<<endl;
    }
    else{
        cout<< (quickpow(2,k)-1 + mod)%mod*inv((-quickpow(2,2*k-1) + quickpow(2,k+1) - 1 + mod)%mod)%mod<<endl;
    }
}


int main()
{
    
    int T;cin>>T;
    while(T--){
        solve();
    }
    
    return 0;
}
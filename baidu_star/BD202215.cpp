#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//类似牛客的某题

const ll mod = 998244353;
const ll N = 1e5+10;
array<array<int,2>,2010> a;
ll n,m,k;
array<ll,N> A;

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


ll C(ll x,ll y)
{
    if(y<0 || y>x){
        return 0;
    }
    return A[x]*quick_pow(A[x-y],mod-2)%mod*quick_pow(A[y],mod-2)%mod;
}


int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++){
        cin>>a[i][0]>>a[i][1];
    }
    A[0]=1;
    for(int i=1;i<=max(n,m);i++){
        A[i] = A[i-1]*i%mod;
    }    

    ll ans=0;
    //B不经过任意传送门到C的方案数
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            
        }
    }
    
    
    
        
   
    return 0;
}
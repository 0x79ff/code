#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


const ll mod = 998244353;
const ll N=1e6+10;
ll p[N],n,dp[N];
vector<array<ll,2>> e[N];

//dp[1] = p2*(dp[2]+1) + p3*(dp[3]+1) + p1*(dp[1]+1);
//dp[1] = (1/(1-p1)) * (p1 + p2*(dp[2]+1) + p3*(dp[3]+1)) =  1/sum - n1 * n1 n2 n3

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

void dfs(int x,int fa)
{
    ll sum = p[x];
    for(auto s:e[x]){
        sum+=s[1];
        dfs(s[0],x);
    }
    for(auto s:e[x]){
        dp[x] += s[1]*(dp[s[0]]+1);
        dp[x]%=mod;
    }
    dp[x]+=p[x];
    dp[x] = dp[x]*quick_pow(sum - p[x],mod-2)%mod;
}


int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    for(int i=2;i<=n;i++){
        ll fa,val;
        cin>>fa>>val;
        e[fa].push_back({i,val});
    }

    dfs(1,0);
    cout<<dp[1];
    
    
   
    return 0;
}
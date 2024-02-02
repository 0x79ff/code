#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll mod = 1e8+7;
const ll N = 2e5+100;

ll n,m,a;
vector<ll>e[N];

ll idx,l[N],r[N],dp[N];

void dfs(ll x,ll fa){
    ++idx;
    l[x] = idx;
    dp[x] = dp[fa]+1;
    for(auto s:e[x]){
        dfs(s,x);
    }
    r[x] = idx;
}

ll quickpow(ll x,ll y)
{
    ll re = 1;
    x%=mod;
    while(y){
        if(y&1) re=re*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return re;
}

ll inv(ll x)
{
    return quickpow(x,mod-2);
}

ll powa[N],powinva[N];

//区间修改 单点查询的树状数组
//t为原来的差分数组
ll t[N];
ll lowbit(ll x){
    return x&(-x);
}

void modify(ll x,ll y){
    while(x<=n){
        t[x] = t[x] + y;
        t[x]+=mod;t[x]%=mod;
        x+=lowbit(x);
    }
}

ll ask(ll x){
    ll re=0;
    while(x){
        re+=t[x];
        re+=mod;re%=mod;
        x-=lowbit(x);
    }
    return re;
}
 
void solve()
{
    cin>>n>>m>>a;
    for(int i=2;i<=n;i++){
        ll fa;cin>>fa;
        e[fa].push_back(i);
    }

    dp[0]=-1;
    dfs(1,0);
    //dfs序已经好了 每个点的dp算出来了
    
    // for(int i=1;i<=n;i++){
    //     cout<<l[i]<<" "<<r[i]<<"     "<<dp[i]<<endl;
    // }
    // for(int i=1;i<=n;i++){
    //     cout<<t[i]<<" ";
    // }
    // cout<<endl;

    //预处理下pow
    powa[0]=1;
    powinva[0]=1;
    a = (a+mod)%mod;//!!!!!a可能为负数
    ll inva = inv(a);
    for(int i=1;i<=N-100;i++){
        powa[i] = powa[i-1]*a%mod;
        powinva[i] = powinva[i-1]*inva%mod;
    }
    
    while(m--){
        ll t;cin>>t;
        if(t==1){
            ll v,x;
            cin>>v>>x;
            // l[v] r[v]  + inv(a,dp[v])*quickpow(a,x) 
            //！！！！！！x也可能为负数
            if(x>0){
                modify(l[v],powa[x]*powinva[dp[v]]%mod);
                modify(r[v]+1,(mod-powa[x]*powinva[dp[v]]%mod)%mod);    
            }
            else{
                modify(l[v],powinva[-x]*powinva[dp[v]]%mod);
                modify(r[v]+1,(mod-powinva[-x]*powinva[dp[v]]%mod)%mod);    
            }
            
        }
        else{
            ll x;
            cin>>x;
            cout<<(ask(l[x])*powa[dp[x]]+mod)%mod<<endl;
        }
    }
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
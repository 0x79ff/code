#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N=2e5+10;
const ll mod=1e9+7;

ll n,k;
ll a[N];

struct node
{
    ll son[2];
    ll val;
}t[N*31];
ll cnt;


//01字典树版本 
//通过枚举max 通过在trie中方案数  从小到大插入trie中即可

//与百度之星国赛c题一样 ~~~指数拆分~~~

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

void modify(ll x,ll y)
{
    int u = 1;
    for(int i=30;i>=0;i--){
        int s=(x>>i)&1;
        if(!t[u].son[s]) t[u].son[s]=++cnt;
        u = t[u].son[s];
        t[u].val+=y;t[u].val%=mod;
    }
}

ll ask(ll x)
{
    int u=1;
    ll re=0;
    for(int i=30;i>=0;i--)
    {
        int s=(x>>i)&1;
        int tt=(k>>i)&1;
        if(tt){
            if(t[u].son[s]){
                re=(re+t[t[u].son[s]].val)%mod;
            }
            u=t[u].son[s^1];
        }
        else{
            u=t[u].son[s];
        }
    }
    re+=t[u].val;
    re%=mod;
    return re;
}
ll ask(int x)
{
    int u=1;
    ll sum=0;
    for(int i=30;i>=0;i--)
    {
        int s=(x>>i)&1;
        int tt=(k>>i)&1;
        if(tt)
        {
            if(t[u].son[s]) sum=(sum+t[t[u].son[s]].val)%mod;
            u=t[u].son[s^1];
        }
        else u=t[u].son[s];
    }
    sum=(sum+t[u].val)%mod;
    return sum;
}
void solve()
{
    cin>>n>>k;
    //pre
    for(int i=0;i<=n*31;i++){
        t[i].son[0]=t[i].son[1]=t[i].val=0;
        cnt=1;
    }


    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);

    ll ans = 1;
    for(int i=2;i<=n;i++){
        modify(a[i-1],inv(quick_pow(2,i-1)));
        ans+=(1+ask(a[i])*quick_pow(2,i-1)%mod);
        ans%=mod;
    }
    cout<<ans<<endl;
}

int main()
{
    IOS;
    int T=1;cin>>T;
    while(T--){
        solve();
    }
    
    return 0;
}

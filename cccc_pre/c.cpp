#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 5e5+10;
const ll mod = 1e9+7;

ll n,m;
vector<ll> g[N];
bool vis[N];
ll dfn[N],low[N],siz[N];
ll id,ans[N];


void tarjen(int x,int fa)
{
    vis[x]=1;
    dfn[x]=low[x]=++id;
    siz[x]=1;
    
    ll child=0,sum=0;

    for(auto s:g[x]){
        if(s==fa) continue;
        if(!vis[s]){
            tarjen(s,x);
            child++;
            siz[x]+=siz[s];
            low[x]=min(low[x],low[s]);
            if(low[s]>=dfn[x]){
                ans[x]+=siz[s]*sum;
                sum+=siz[s];   
            }
        }
        else{
            low[x]=min(low[x],dfn[s]);
        }
    }
    
    ans[x]+=sum*(n-sum-1);
}


void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            id=0;
            tarjen(i,i);        
        }
    }
    
    for(int i=1;i<=n;i++){
        cout<<2*(ans[i]+n-1)<<endl;
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

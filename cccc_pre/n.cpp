#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 2e3+10;
const ll mod = 1e9+7;
vector<ll> g[N];
ll root;
ll ffa[N];
ll x[N],y[N],z[N];


void dfs(ll x,ll fa,ll xx)
{
    ffa[x]=xx;
    for(auto s:g[x]){
        if(s==fa){
            continue;
        }
        dfs(s,x,xx);
    }
}

void solve()
{
    ll n,m;
    cin>>n>>m;
    for(int i=2;i<=n;i++){
        ll a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=1;i<=m;i++){
        cin>>x[i]>>y[i]>>z[i];
    }

    for(int i=1;i<=n;i++){
        map<int,int> ma;
        root = i;
        memset(ffa,0,sizeof(ffa));
        for(auto s:g[i]){
            dfs(s,i,s);
        }
        
        for(int j=1;j<=m;j++){
            //cout<<ffa[x[j]]<<" "<<ffa[y[j]]<<endl;
            if((ffa[x[j]]!=ffa[y[j]])||(ffa[x[j]]==0)){
                ma[z[j]]++;
            }
        }

        ll ans = 0,mx = 0;
        for(map<int,int>::iterator it=ma.begin();it!=ma.end();it++)
        {
            if(it->second>mx){
                mx=it->second;
                ans=it->first;
            }
            else if(it->second == mx && it->first<ans){
                ans=it->first;
            }
        }
        cout<<ans<<endl;   
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

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 2e5+10;
const ll mod = 1e9+7;

//欧拉序问题
vector<ll> g[N];
int n;

//seq中为树的欧拉序
int pos,seq[N*2];
void dfs(int x,int fa)
{
    seq[++pos] = x;
    for(auto s:g[x]){
        if(s!=fa) {
            dfs(s,x);
            seq[++pos] = x;
        }
    }
}

void solve()
{
    cin>>n;
    for(int i=1;i<n;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        sort(g[i].begin(),g[i].end());
    }
    dfs(1,0);
    for(int i=1;i<=pos;i++){
        cout<<seq[i]<<' ';
    }
    cout<<endl;
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

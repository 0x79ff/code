#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"


const ll N = 2e5+10;
const ll mod = 1e9+7;


vector<int> g[N];
int n,k;

int dep[N],len[N];
//用与维护每个节点的最深的son以及该节点的深度

void dfs1(int x)
{
    len[x] = 1;
    for(auto &s:g[x]){///&
        dep[s] = dep[x]+1;
        dfs1(s);
        len[x] = max(len[x],len[s]+1);
        if(len[s]>len[g[x][0]]){
            swap(s,g[x][0]);
        }
    }

    if(!g[x].empty()){
        swap(g[x][0],g[x].back());
    }
}


//seq中为树的欧拉序
int pos,seq[N*2];
void dfs2(int x)
{
    seq[++pos] = x;
    for(auto s:g[x]){
        dfs2(s);
        seq[++pos] = x;
    }
    
}


bool vis[N];

void solve()
{
    cin>>n>>k;
    for(int i=2;i<=n;i++){
        ll t;cin>>t;
        g[t].push_back(i);
    }

    dfs1(1);
    dfs2(1);
    
    int ans = pos - 1 - (len[1]-1);
    int last = 1;
    vis[1]=true;

    vector<int> f;
    for(int i=2;i<=pos;i++){
        int x = seq[i];
        if(vis[x]) continue;
        vis[x] = true;
        f.push_back(i - last - dep[x]);
        last = i;
    }

    sort(f.begin(),f.end(),greater<int>());
    
    while(!f.empty() && f.back()<=0){
        f.pop_back();
    }

    for(int i=0;i<min(k,(int)(f.size()));i++){
        ans -= f[i];
    }
    cout<<ans<<endl;

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
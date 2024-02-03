#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll mod = 998244353;
const ll N = 1e5+100;
ll n;
ll a[N];
string s[N];
ll vis[N];//1 表示在本次dfs访问过 2表示环处理过


vector<ll> v;
ll b;

void dfs(ll x)
{
    v.push_back(x);
    vis[x]=1;
    if(vis[a[x]]==2){
        b=0;
        return;
    }
    if(vis[a[x]]==1){
        b=a[x];
        return;
    }
    if(vis[a[x]]==0){
        dfs(a[x]);
    }
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>s[i];
    }    
    
    ll ans = 1;
    
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            v.clear();
            dfs(i);
            for(auto s:v) vis[s] = 2;

            if(b==0) continue;
            //处理环
            ll cnt = 0;
            vector<ll> lo;
            ll c=a[b];
            while(c!=b) {
                lo.push_back(c);
                c=a[c];
            }
            
            for(int j=0;j<5;j++){
                ll t = s[b][j] - 'A';
                for(int k=0;k<lo.size();k++){
                    t  = s[lo[k]][t] - 'A';
                }
                if(t==j) cnt++;
              //  cout<<t<<endl;
            }

            ans*=cnt;
            ans%=mod;
           // cout<<i<<" "<<ans<<endl;
        }
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
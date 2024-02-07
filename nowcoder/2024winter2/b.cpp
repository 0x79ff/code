#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"


ll n,m,k;

int a[500][500];
vector<array<ll,2>> c;
const ll dx[4] = {0,0,1,-1};
const ll dy[4] = {1,-1,0,0};

bool range(ll x,ll y){
    return x>=1 && x<=n && y>=1 && y<=m;
}

void solve()
{
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++){
        ll x,y;
        cin>>x>>y;
        c.push_back({x,y});
        a[x][y]=1;
    }
    ll ans = 0,num = 0;
    for(auto s:c){
        for(int j=0;j<4;j++){
            if(a[s[0]+dx[j]][s[1]+dy[j]]==1){
                num++;
            }
            
        }
    }
    num/=2;
    ans=4*k-num;
    cout<<ans;
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
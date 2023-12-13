#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N=1e2+10;
const ll inf=1e9+10;

ll fa[N];

ll find(ll x){
    if(x==fa[x]){
        return x;
    }
    return fa[x]=find(fa[x]);
}

void merge(ll x,ll y){
    fa[find(x)] = find(y);
}

//还是kruskal

void solve()
{
    ll n;
    vector<array<ll,3>> e;
    vector<array<ll,2>> ans;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ll t;cin>>t;
            if(i<j){
                e.push_back({t,i,j});
            }
        }
    }

    //pre
    for(int i=1;i<=n;i++){
        fa[i] = i;
    }

    sort(e.begin(),e.end());
    
    for(auto s:e){
        if(ans.size()==n-1){
            break;
        }
        if(find(s[1])!=find(s[2])){
            ans.push_back({s[1],s[2]});
            merge(s[1],s[2]);
        }
    }

    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(auto s:ans){
        cout<<s[0]<<" "<<s[1]<<endl;
    }
    
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll T;cin>>T;
    while(T--){
        solve();
    }
   
    return 0;
}
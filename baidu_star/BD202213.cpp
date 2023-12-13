#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=3e3+10;
const ll inf=1e16+10;

ll d[N],vis[N],c[N],n,k;
ll x[N],y[N],z[N];


vector<ll> ans;
vector<array<ll,3>> e;
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

//kruskal

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    
    cin>>n>>k;
    for(int i=1;i<=n-k;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i]>>z[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){        
            e.push_back({(x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) 
            + (z[i]-z[j])*(z[i]-z[j]),i,j});
        }
    }

    //pre
    for(int i=1;i<=n;i++){
        fa[i] = i;
    }

    sort(e.begin(),e.end());
    for(auto s:e){
      //  cout<<s[0]<<" "<<s[1]<<" "<<s[2]<<endl;
        if(ans.size()==n-k) break;
        if(find(s[1])!=find(s[2])){
            ans.push_back(s[0]);
            merge(s[1],s[2]);
        }
    }
    //cout<<ans.size()<<endl;
    ll sum=0,anss=c[n-k];
    for(int i=0;i<ans.size();i++){
        sum+=ans[i];
        anss = min(anss,sum + c[n-k-1-i]);
    }
    cout<<anss;
    
    return 0;
}
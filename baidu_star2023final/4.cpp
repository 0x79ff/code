#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
const int N = 1e3+100;
ll fa[N],to[N];

ll find(ll x)
{
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}

void merge(ll x,ll y)
{
    ll xx = find(x),yy = find(y);
    if(xx>yy) fa[xx]=yy;
    else fa[yy]=xx;
}

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    cin>>n;
    
    for(int i=1;i<=n;i++){
        cin>>to[i];
        fa[i]=i;
    }

    for(int i=1;i<=n;i++){
        merge(i,to[i]);
    }
    
    ll ans=0;
    for(int i=1;i<=n;i++){
        // cout<<find(i)<<endl;
        if(find(i)==0){
            ans^=i;
        }
    }
    cout<<ans;
    return 0;
}
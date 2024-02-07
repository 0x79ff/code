#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 1e5+100;
ll n,q,tc;
ll t[N],sum[N];

void solve()
{
    cin>>n>>q>>tc;
    for(int i=1;i<=n;i++){
        cin>>t[i];
    }
    
    sort(t+1,t+n+1);
    sum[1]=t[1];
    for(int i=1;i<=n;i++){
        sum[i] = sum[i-1]+t[i];
    }
    
    while(q--){
        ll m;cin>>m;
        cout<<tc + sum[max(0ll,n - m/tc)]<<endl;        
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
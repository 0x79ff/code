#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"


ll n,m,a[20],u[20],v[20],b[20];
ll pow3[20];

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i];
    }
    

    ll ans = n;    
    for(ll i=0;i<pow3[m];i++){
        for(int j=1;j<=n;j++) b[j] = a[j];
        for(int j=1;j<=m;j++){
            ll t = (i/pow3[j-1])%3;
            if(t==0) b[u[j]]+=3;
            if(t==1) b[v[j]]+=3;
            if(t==2) b[u[j]]+=1,b[v[j]]+=1; 
        }
        ll cnt = 1;
        for(int j=2;j<=n;j++){
            if(b[j]>b[1]){
                cnt++;
            }
        }
        ans = min(cnt,ans);
    }
    cout<<ans<<endl;
}

int main()
{
    IOS;

    pow3[0]=1;
    for(int i=1;i<=15;i++){
        pow3[i] = pow3[i-1]*3;
    }
    int T;cin>>T;
    while(T--){
        solve();
    }
    
    return 0;
}
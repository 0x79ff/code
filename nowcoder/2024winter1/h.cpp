#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

//补题  
//按位去算 ...

const ll N = 2e5+100;

ll n,m;
ll w[N],v[N];

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i];
    }    
    
    auto get = [&](ll x){
        ll re = 0;
        for(int i=1;i<=n;i++){
            if((x|w[i])== x){
                re+=v[i];
            }
        }
        return re;
    };

    
    ll ans = get(m);
    for(int i=m;i;i-=i&(-i)){
        ans = max(ans,get(i-1));
    }
    cout<<ans<<endl;

    
}

int main()
{
    IOS;
    int T;cin>>T;
    while(T--){
        solve();
    }
    
    return 0;
}
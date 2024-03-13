#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 1e5+10;
const ll mod = 1e9+7;

ll a[N];
ll n;


void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    ll ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]==0) continue;
        if(a[i-1]==0) ans+=a[i];
        else if(a[i]>=a[i-1]){
            ans+=(a[i]-a[i-1]+1);
        }
        else ans++;
    }
    cout<<ans<<endl;
    
}

int main()
{
    IOS;
    int T=1;cin>>T;
    while(T--){
        solve();
    }
    
    return 0;
}

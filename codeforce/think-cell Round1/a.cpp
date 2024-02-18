#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 1e5+10;
const ll mod = 1e9+7;


ll n;
ll a[200];

void solve()
{
    cin>>n;
    for(int i=1;i<=n*2;i++){
        cin>>a[i];
    }
    ll ans = 0;
    sort(a+1,a+1+2*n);
    for(int i=1;i<=n;i++){
        ans+=a[i*2-1];
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

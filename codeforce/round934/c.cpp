#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 2e5+10;
const ll mod = 1e9+7;

ll n;

void solve()
{
    cin>>n;
    vector<ll> a(n+10,0);
    for(int i=1;i<=n;i++){
        ll t;cin>>t;
        a[t]++;
    }
    bool oone=0;
    ll ans;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            ans=i;
            break;
        }
        else if(a[i]==1){
            if(oone==0) oone=1;
            else{
                ans=i;
                break;
            }
        }
        ans=i+1;
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

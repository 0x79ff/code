#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 1e5+10;
const ll mod = 1e9+7;


void solve()
{
    ll n;cin>>n;
    string s;cin>>s;
    s = ' '+s;
    
    ll ans = 0;
    vector<ll> dp(n+10,0);
    for(int i=n;i>0;i--){
        if(s[i] == '1'){
            dp[i] = dp[i+3] + n - i + 1;
        }
        else{
            dp[i] = dp[i+1];
        }
        ans+=dp[i];
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

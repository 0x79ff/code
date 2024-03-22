#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 2e5+10;
const ll inf = 1e18+7;


bool cmp(array<ll,2>x,array<ll,2>y)
{
    return x[1]<y[1];
}

void solve()
{
    ll n,l;
    cin>>n>>l;
    
    vector<array<ll,2>> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1];
    }
    sort(a.begin()+1,a.end(),cmp);
    

    int ans=0;
    vector<ll> dp(n+10,inf);
    for(int i=1;i<=n;i++){
        if(a[i][0]<=l){
            ans = max(ans,1);
        }
    }

    dp[1]=a[1][0]-a[1][1];
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(dp[j]+a[i][0]+a[i][1]<=l){
                ans = max(ans,j+1);
            }
        }
        for(int j=n;j>=2;j--){
            dp[j] = min(dp[j],dp[j-1]+a[i][0]);
        }
        dp[1] =min(dp[1],a[i][0]-a[i][1]);
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

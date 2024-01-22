#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5+100;
ll n,k,x;
ll a[N];

//别想太多 直接枚举就行了
void solve()
{
    cin>>n>>k>>x;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);

    for(int i=1;i<=n;i++){
        a[i]+=a[i-1];
    }
    ll ans = -1e11;
    for(int i=0;i<=k;i++){
        if(i+x>=n){
            ans = max(ans,-(a[n]-a[i]));
        }
        else{
            ans = max(ans,a[n]-a[i+x] -(a[i+x]-a[i]));
        }
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

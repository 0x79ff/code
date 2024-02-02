#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"


ll n;
const int N = 1e5+100;
ll a[N],sum[N],dp[N];

bool check(ll x)
{
    for(int i=0;i<=n;i++){
        dp[i]=0;
    }
    
    deque<ll>q;
    q.push_back(0);
    for(int i=1;i<=n;i++){
        while(q.size()!=0 && sum[i-1]-sum[q.front()]>x) q.pop_front();
        if(q.size()!=0){
            dp[i] = dp[q.front()] + a[i];
            while(q.size()!=0 && dp[q.back()]>=dp[i]) q.pop_back();
            q.push_back(i);
        }
    }
    while(q.size()!=0 && (sum[n]-sum[q.front()]>x || dp[q.front()]>x)) q.pop_front();
    // cout<<x<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;
    if(q.size()!=0) return 1;
    else return 0;
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }

    ll l=1,r=sum[n];
    while(l<r){
        ll mid = (l+r)/2;
        if(check(mid)){
            r = mid;
        }
        else{
            l=mid+1;
        }
    }
    cout<<l<<endl;
}

int main()
{
    //IOS;
    int T;cin>>T;
    while(T--){
        solve();
    }
    
    return 0;
}
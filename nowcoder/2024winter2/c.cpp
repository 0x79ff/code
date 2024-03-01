#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N=2e5+10;
const ll mod=1e9+7;

ll n,k;
ll a[N],p[N];

void solve()
{
    cin>>n>>k;
    k++;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+n+1);

    // 按位枚举 小于k 可以枚举最高与k不同的一位

    ll now=0,ans=0;
    for(int i=30;i>=0;i--){
        if(k &(1<<i)){
            for(int j=1;j<=n;j++){
                ll oth = (a[j]>>i<<i)^now;
                ll l,r;
                l = lower_bound(a+1,a+j+1,oth) - a;
                r = lower_bound(a+1,a+j+1,oth + (1<<i)) - a;
                if(r==j+1) ans=(ans+p[r-l-1])%mod;
                else ans = (ans+(p[r-l]-1)*p[j-r]%mod)%mod;
            }
            now+=(1<<i);
        }
    }
    cout<<ans<<endl;
}

int main()
{
    IOS;
    p[0]=1;
    for(int i=1;i<=N-10;i++) p[i]=p[i-1]*2%mod;

    int T=1;cin>>T;
    while(T--){
        solve();
    }
    
    return 0;
}

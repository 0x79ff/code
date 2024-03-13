#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 2e6+10;
const ll mod = 1e9+7;

ll prime[N],cnt;
bool isprime[N];

void solve()
{
    ll n;cin>>n;
    if(n==1){
        cout<<1<<endl;
        return;
    }
    //二分
    ll l=1,r=cnt;
    while(l<r){
        ll mid = (l+r+1)>>1;
        //cout<<mid<<" "<<prime[mid]<<endl;
        if(prime[mid]<=n){
            l = mid;
        }
        else{
            r=mid-1;
        }
        
    }
    cout<<prime[l]<<endl;
}

int main()
{
    IOS;
    //pre
    memset(isprime,1,sizeof(isprime));
    isprime[1]=0;
    for(int i=2;i<=N-10;i++)
    {
        if(isprime[i])
        {
            prime[++cnt]=i;
        }
        for(int j=1;j<=cnt && i*prime[j]<=N-10;j++)
        {
            isprime[i*prime[j]]=0;
            if(i%prime[j]==0) break;
        }
    }

    int T=1;cin>>T;
    while(T--){
        solve();
    }
    
    return 0;
}

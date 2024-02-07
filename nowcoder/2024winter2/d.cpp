#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"


const ll N = 5e3+100;
const ll inf = 1e16;
ll n,m,k;
ll a[N],b[N];


void solve()
{
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i];
    }

    vector<ll>dp(n,inf);
    dp[0] = 0;

    for(int i=1;i<=m;i++){
        vector<bool>vis(n,0);
        for(int k=0;k<n;k++){
            if(vis[k]) continue;
            vis[k]=1;
            while(vis[(k+a[i])%n]==0){
                vis[(k+a[i])%n]=1;
                if(dp[k%n]!=inf){
                    dp[(k+a[i])%n] = min(dp[(k+a[i])%n],dp[k%n]+b[i]);
                }
                k = (k+a[i])%n;
            }   
            if(dp[k%n]!=inf){
                dp[(k+a[i])%n] = min(dp[(k+a[i])%n],dp[k%n]+b[i]);
            }


        }

        vector<bool>vis2(n,0);
        for(int k=0;k<n;k++){
            if(vis2[k]) continue;
            vis2[k]=1;
            while(vis2[(k+a[i])%n]==0){
                vis2[(k+a[i])%n]=1;
                if(dp[k%n]!=inf){
                    dp[(k+a[i])%n] = min(dp[(k+a[i])%n],dp[k%n]+b[i]);
                }
                k = (k+a[i])%n;
            }   
            if(dp[k%n]!=inf){
                dp[(k+a[i])%n] = min(dp[(k+a[i])%n],dp[k%n]+b[i]);
            }

            
        }
        // for(int j=0;j<n;j++){
        //     cout<<dp[j]<<' ';
        // }
        // cout<<endl;
    }

    if(dp[n-k]==inf){
        cout<<-1<<endl;
    }
    else{
        cout<<dp[n-k]<<endl;
    }
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
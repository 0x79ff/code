#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 1e5+10;
const ll mod = 1e9+7;

ll n;
string s;
ll a[200];

void solve()
{
    cin>>n;
    cin>>s;
    for(int i=1;i<=n;i++){
        a[i] = s[i-1] - '0';
    }
    ll ans = 0;

    for(int j=1;j<=n;j++){
        for(int k=j;k<=n;k++){
            vector<ll>b(n+10,0),c(n+10,0);
            ll num = 0;
            for(int m=j;m<=k;m++){
                b[m-j+1] = a[m];   
            }
            for(int i=1;i<=k-j+1;i++){
                if(b[i]==1){
                    if(c[i]==1 || (i-1>=1 && c[i-1]==1)) continue;
                    else{
                        c[i+1]=1;
                        num++;
                    }
                }
            }
            
            ans+=num;
        }
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

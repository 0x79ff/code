#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 1e5+10;
const ll mod = 1e9+7;

ll n;
ll a[3][N];
ll ans;
bitset<N>x,y,z,w;
//bitset怎么用 相当于反着的bool数组
//前面都是0.....

void solve()
{
    cin>>n;

    for(int i=0;i<3;i++){    
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }

    for(int i=0;i<3;i++){
        ll num = 0;
        for(int j=1;j<=n;j++){
            if(a[i][j]==1){
                num++;
            }
        }
        if(num>=3) ans+=num*(num-1)*(num-2)/6;
    }
    
    for(ll i=1;i<=n;i++){
        y[i]=a[2][i];
        x[i]=a[0][n+1-i];
    }

    for(ll i=1;i<=n;i++){
        if(a[1][i]==1){
            if(i<=(n+1)/2){
                z=y&(x<<(n+1-2*i));
            }
            else{
                z=y&(x>>(2*i-n-1));
            }
            ans+=z.count();
        }
    }
    cout<<ans<<endl;
}

int main()
{
    IOS;
    int T=1;//cin>>T;
    while(T--){
        solve();
    }
    
    return 0;
}

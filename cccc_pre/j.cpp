#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 1e5+10;
const ll mod = 1e9+7;

ll n,m;
ll a[N];
string b[N];

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    ll pos = 1;
    while(m--){
        ll x,y;cin>>x>>y;
        if((a[pos]==1&&x==0)||(a[pos]==0&&x==1)){
            pos+=y;pos%=n;
            if(pos==0)pos=n;
        }
        else{
            pos-=y;pos+=n;pos%=n;
            if(pos==0)pos=n;
        }
    }
    cout<<b[pos]<<endl;
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

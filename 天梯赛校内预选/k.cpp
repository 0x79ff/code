#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 1e5+10;
const ll mod = 1e9+7;


ll lowbit(ll x){
    return x&(-x);
}

void solve()
{
    ll n,x;
    cin>>n>>x;
    if(x>n){
        cout<<-1<<endl;
        return;
    }
    //逐个处理n的最低位 check
    ll t=n;
    while(t>=x){
        if(t==x){
            cout<<n<<endl;
            return;
        }
        n+=lowbit(n);
        t=n&t;
    }
    cout<<-1<<endl;
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
    

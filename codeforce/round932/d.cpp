#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 3e5+10;
const ll mod = 998244353;

//艹 vector.size() 是 int类型

void solve()
{
    ll n,c;
    cin>>n>>c;
    vector<ll> s(n+10,0);
    ll a,b;a=b=0;
    
    ll ans = (c+1)*c/2+(c+1);
    
    for(int i=1;i<=n;i++){
        cin>>s[i];
        ll t=s[i];
        ans-=(s[i]+2)/2;
        ans-=(c-s[i]+1);
        ans+=1;

        if(s[i]%2==1){
            a++;
        }
        else{
            b++;
        }
    }

    ans+=a*(a-1)/2;
    ans+=b*(b-1)/2;
    
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

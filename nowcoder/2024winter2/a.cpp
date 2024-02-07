#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"


void solve()
{
    ll a,b,c;cin>>a>>b>>c;
    ll ans=0;
    if(a==150) ans++;
    if(a==200) ans+=2;
    
    if(b>=34 && b<=40) ans++;
    if(b==45) ans+=2;
        
    if(c>=34 && c<=40) ans++;
    if(c==45) ans+=2;

    cout<<ans<<endl;
}

int main()
{
    IOS;
    int T;cin>>T;
    while(T--){
        solve();
    }
    
    return 0;
}
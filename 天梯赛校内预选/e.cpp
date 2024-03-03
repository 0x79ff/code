#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 1e5+10;
const ll mod = 1e9+7;

void solve()
{
    ll n;
    string s;
    cin>>n>>s;
    s=" "+s;
    ll ans = n;
    for(int i=1;i<n*2;i++){
        if(s[i]==')' && s[i+1]=='('){
            ans--;
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

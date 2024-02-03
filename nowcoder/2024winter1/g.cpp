#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const int N = 1e5+100;

ll n,m;

vector<array<ll,2>> v;

void solve()
{
    v.clear();

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ll a,b;cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    
    ll ans = m;
    ll sum = 0;
    for(int i=0;i<v.size();i++){
        sum += v[i][1];
        if(v[i][0]-sum<=m){
            ans = max(ans,sum+m);   
        }
    }
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
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 3e5+10;
const ll mod = 1e9+7;


void solve()
{
    ll n;
    vector<ll> a;
    cin>>n;
    for(int i=1;i<=n;i++){
        ll t;cin>>t;
        a.push_back(t+i);
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    for(int i=1;i<a.size();i++){
        a[i] = min(a[i],a[i-1]-1);
    }

    for(auto s:a)
    {
        cout<<s<<" ";
    }
    cout<<endl;
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

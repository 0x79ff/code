#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 2e5+100;

ll n;
vector<ll> v[N];

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++){
       v[i].clear();
    }

    for(int i=1;i<=n;i++){
        ll t;cin>>t;
        v[t].push_back(i);
    }
    set<int> s;
    for(int i=1;i<=n;i++){
        if(v[i].size()!=0) s.insert(i);
    }
    ll ans=0;
    while(!s.empty()){
        ll lo = 1e9;
        vector<ll>y;
        for(auto x:s){
            lo = min(lo,v[x][v[x].size()-1]);
        }
        for(auto x:s){
            while(!v[x].empty() && v[x][v[x].size()-1]>=lo){
                v[x].pop_back();
            }
            if(v[x].empty()) y.push_back(x);
        }
        for(auto x:y){
            s.erase(x);
        }
        //cout<<"lo:"<<lo<<endl;
        ans++;
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
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 1e5+10;
const ll mod = 1e9+7;

ll n,k;


void solve()
{
    cin>>n>>k;
    vector<ll> a(n+10,0),l,r;
    for(int i=1;i<=n*2;i++){
        ll t;cin>>t;
        if(i<=n){
            a[t]++;
        }
    }    
    for(int i=1;i<=n;i++){
        if(a[i]==2 && l.size()+2<=2*k){
            l.push_back(i);
            l.push_back(i);
        }
        if(a[i]==0 && r.size()+2<=2*k){
            r.push_back(i);
            r.push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]==1 && l.size()+1<=2*k && r.size()+1<=2*k){
            l.push_back(i);
            r.push_back(i);
        }
    }
    for(auto s:l){
        cout<<s<<" ";
    }
    cout<<endl;

    for(auto s:r){
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

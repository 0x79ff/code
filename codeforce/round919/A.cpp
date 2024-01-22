#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll a[200],b[200];

void solve()
{
    cin>>n;
    ll c = 0,d = 1e11;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        if(a[i]==1){
            c=max(c,b[i]);
        }
        if(a[i]==2){
            d=min(d,b[i]);
        }
    }
    if(c>d){
        cout<<0<<endl;
    }
    else{
        ll ans = d-c+1;
        for(int i=1;i<=n;i++){
            if(a[i]==3 && b[i]>=c && b[i]<=d){
                ans--;
            }
        }
        cout<<ans<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    
        
    

    return 0;
}
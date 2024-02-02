#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"


ll pow2[62];

ll cnt(ll x)
{
    ll re=0;
    while(x){
        re++;
        x>>=1;
    }
    return re;
}

void solve()
{
    ll a,b,r;
    cin>>a>>b>>r;
    if(a==b){
        cout<<0<<endl;
        return;
    }

    if(a<b){
        swap(a,b);
    }
    vector<ll> v;
    for(ll i=60;i>=0;i--){
        if((a&(1ll<<i))!=(b&(1ll<<i))){
            //cout<<i<<endl;
            v.push_back(i);
        }
    }

    ll ans = pow2[v[0]];
    ll cnt = r;

    for(ll i=1;i<v.size();i++){
        if(cnt>=pow2[v[i]]){
            if(a&(1ll<<v[i])){
                cnt-=pow2[v[i]];
                ans-=pow2[v[i]];    
            }
            else{
                ans-=pow2[v[i]];
            }


            
        }
        else{
            if(a&(1ll<<v[i])){
                ans+=pow2[v[i]];
            }
            else{
                ans-=pow2[v[i]];
            }
        }
    }
    cout<<ans<<endl;
}


int main()
{
    pow2[0]=1;
    for(int i=1;i<=60;i++){
        pow2[i]=pow2[i-1]*2;
    }
    IOS;
    int T;cin>>T;
    while(T--){
        solve();
    }
    
    return 0;
}

/*

*/
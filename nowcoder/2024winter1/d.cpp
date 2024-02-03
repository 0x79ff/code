#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"


const ll N = 1e5+100;
const ll R = 1e9;

ll n,q;
ll a[N];
set<ll> s;



//n==2的特殊情况
void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    
    if(n==2){
        ll x=a[1],y=a[2];
        if(x>y) swap(x,y);
        while(q--){
            ll z;cin>>z;
            ll w = (y-x)*(y-x)+4*z;
            if((ll)(sqrt(w))*(ll)(sqrt(w)) == w && ((ll)(sqrt(w)) + (y-x)) %2==0){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
            

        }   



        return;
    }
    sort(a+1,a+n+1);
    s.insert(0);
    
    ll t = a[(n+1)/2];
    for(int i=1;i<=n;i++){
        a[i]-=t;
    }
    //左移
    bool ok=1;
    for(int i=0;ok;i++){
        ll val = 1;
        for(int j=1;j<=n;j++){
            val*=(a[j]-i);
            if(abs(val)>R && j<=(n+1)/2){
                ok = 0;
                break;
            }
            if(abs(val)>R) break;
        }
        if(ok && abs(val)<=R) s.insert(val);
    }

    ok=1;
    for(int i=0;ok;i++){
        ll val = 1;
        for(int j=n;j>=1;j--){
            val*=(a[j]+i);
            //cout<<"a[j]+i::"<<a[j]+i<<endl;
            if(abs(val)>R && j>=(n+1)/2){
                ok = 0;
                break;
            }
            if(abs(val)>R) break;
        }
        //cout<<val<<endl;
        if(ok && abs(val)<=R) s.insert(val);
    }

    

    while(q--){
        ll x;cin>>x;
        if(s.find(x)!=s.end()){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}

int main()
{
    IOS;
    int T=1;//cin>>T;
    while(T--){
        solve();
    }
    
    return 0;
}
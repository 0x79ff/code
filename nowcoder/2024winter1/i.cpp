#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

void solve()
{
    ll n;cin>>n;
    ll num = 0;
    for(int i=1;i<=n;i++){
        ll x,y,r;
        cin>>x>>y>>r;
        if(abs(x)<50 && abs(y)<=50){
            num++;
        }
    }
    if(num>=30000){
        cout<<"buaa-noob"<<endl;
    }
    else{
        cout<<"bit-noob"<<endl;
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
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x,n;

void solve()
{
    cin>>x>>n;
    ll y = x/n;
    for(int i=1;i<sqrt(x);i++){
        if(x%i==0){
            if(x/i<=y){
                cout<<x/i<<"\n";
                return;
            }
        }
    }
    for(int i=sqrt(x);i>=1;i--){
        if(x%i==0){
            if(i<=y){
                cout<<i<<"\n";
                return;
            }
        }
    }
}



int main()
{
    int T;cin>>T;
    while(T--){
        solve();
    }
    
    return 0;
}
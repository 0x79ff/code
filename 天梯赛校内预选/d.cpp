#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 1e5+10;
const ll mod = 1e9+7;

void solve()
{
    ll n,m;
    cin>>n>>m;
    if(n>m){
        cout<<"no"<<endl;
        return;
    }
    if(n%2==0 && m%2==1){
        cout<<"no"<<endl;
        return;
    }
    cout<<"yes"<<endl;
    if(n%2==1){
        for(int i=1;i<=n-1;i++){
            cout<<1<<" ";
        }
        cout<<m-n+1<<endl;
    }
    else{
        for(int i=1;i<=n-2;i++){
            cout<<1<<" ";
        }
        cout<<(m-n+2)/2<<" "<<(m-n+2)/2<<endl;
    }
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

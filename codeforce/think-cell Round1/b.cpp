#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 1e5+10;
const ll mod = 1e9+7;


ll n;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        if(i%2==1){
            cout<<(i+1)/2<<" ";
        }
        else{
            cout<<n+1-i/2<<" ";
        }
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

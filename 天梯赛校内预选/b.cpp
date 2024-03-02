#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 1e5+10;
const ll mod = 1e9+7;

void solve()
{
    ll n,x,y;
    cin>>n>>x>>y;
    if(x!=0&&y!=0){
        cout<<-1<<endl;
        return;
    }
    if(x==0 && y==0){
        cout<<-1<<endl;
        return;
    }
    if(x<y)swap(x,y);
    //y = 0
    if((n-1)%x!=0){
        cout<<-1<<endl;
        return;
    }
    for(int i=2;i<=n;i+=x){
        for(int j=1;j<=x;j++){
            cout<<i<<" ";
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

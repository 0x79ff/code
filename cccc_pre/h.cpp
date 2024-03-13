#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 1e5+10;
const ll mod = 1e9+7;

//ll a,b;
ll days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

void solve()
{
    ll a,b;cin>>a>>b;
    ll x,y,z,w;
    ll ans = 0;
    x = a/10000;y=a%10000;
    z = b/10000;w=b%10000;
    
    for(int i=x;i<=z;i++){
        //cout<<i<<endl;
        ll num[4];
        num[0]=i%10;
        num[1]=i/10%10;
        num[2]=i/100%10;
        num[3]=i/1000%10;
        
        ll m,d;

        m = num[0]*10+num[1];
        d = num[2]*10+num[3];
             //   cout<<m<<" "<<d<<endl;
        if(m<=12 && m>=1){
            if(d>=1 && d<=days[m]+(i==9220)){
                bool ok=1;
                if(i==x){
                    if(m*100+d<y){
                        ok=0;
                    }
                }
                if(i==z){
                    if(m*100+d>w){
                        ok=0;
                    }
                }
                if(ok){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
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

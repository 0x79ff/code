#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 1e5+10;
const ll mod = 1e9+7;

ll a,b,c,d;
ll x,y;

void exgcd(ll c,ll d)
{
    if(c==0 || d==0){
        return;
    }
    
    if(c<d){
        if(a==c && d>=b && (d-b)%c==0){
            y+=(d-b)/c;
            cout<<x<<" "<<y<<endl;
            exit(0);
        }
        else{
            y+=d/c;
            exgcd(c,d%c);
        }
    }
    else{
        if(b==d && c>=a && (c-a)%d==0){
            x+=(c-a)/d;
            cout<<x<<" "<<y<<endl;
            exit(0);
        }
        else{
            x+=c/d;
            exgcd(c%d,d);
        }
    }
}

void solve()
{
    cin>>a>>b>>c>>d;
    exgcd(c,d);
    cout<<-1<<endl;
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

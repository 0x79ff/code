#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 30;
const ll mod = 1e9+7;

ll d,n,x[N],y[N],k[N];

void solve()
{
    cin>>d>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i]>>k[i];
    }

    ll mx=0,cnt=0;

    for(int i=0;i<=128;i++){
        for(int j=0;j<=128;j++){
            ll num=0;
            for(int xx=1;xx<=n;xx++){
                if(abs(x[xx]-i)<=d && abs(y[xx]-j)<=d){
                    num+=k[xx];
                }
            }
            if(num>mx){
                mx=num;cnt=1;
            }
            else if(num==mx){
                cnt++;
            }
        }
    }
    cout<<cnt<<" "<<mx<<endl;
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

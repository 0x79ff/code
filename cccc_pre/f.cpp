#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 100+10;
const ll mod = 1e9+7;

ll a[N][N];
ll n,m;
bool ok[N][N];


const int dx[]={0,0,1,-1};
const int dy[]={-1,1,0,0};

bool inr(ll x,ll y){
    return x>=1&&x<=n&&y>=1&&y<=m;
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<4;k++){
                ll xx = i+dx[k],yy = j+dy[k];
                if(inr(xx,yy)&&a[xx][yy]==a[i][j]) ok[i][j]=1;
            }
        }
    }

    ll ans = n*m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(ok[i][j]) ans--;
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

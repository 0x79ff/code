#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 50;
const ll mod = 1e9+7;

ll a[N][N];

void solve()
{
    ll n;cin>>n;
    ll r,c;
    a[1][(n+1)/2]=1;
    r = 1;
    c = (n+1)/2;
    
    for(int i=2;i<=n*n;i++){
        if(r==1 && c!=n){
            a[n][c+1]=i;
            r=n;
            c+=1;
        }
        else if(r!=1 && c==n){
            a[r-1][1]=i;
            r-=1;
            c=1;
        }
        else if(r==1 && c==n){
            a[r+1][c]=i;
            r++;
        }
        else{
            if(a[r-1][c+1]==0){
                a[r-1][c+1]=i;
                r--;
                c++;
            }
            else{
                a[r+1][c]=i;
                r++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<a[i][j]<< " ";
        }
        cout<<endl;
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

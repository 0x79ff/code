#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 1e5+10;
const ll mod = 1e9+7;

void solve()
{
    ll n;
    cin>>n;
    vector<ll> a(n+10,0),b(n+10,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]]++;
    }
    
    ll mex;
    for(int i=0;i<=n;i++){
        if(b[i]==0){
            mex=i;
            break;
        }
    }
    
    vector<array<ll,2>> ans;
    for(int i=1;i<=n;){
        ll tmex=0;
        for(int j=0;j<=mex;j++) b[j]=0;
        int j;
        for(j=i;j<=n;j++){
            if(a[j]<mex){
                b[a[j]]++;
            }
            while(b[tmex]!=0){
                tmex++;
            }
            if(tmex==mex){
                ans.push_back({i,j});
                i=j+1;
                break;
            }
        }
        if(j>n){
            break;
        }
    }

    if(ans.size()==0){
        cout<<2<<endl;
        cout<<1<<" "<<1<<endl;
        cout<<2<<" "<<n<<endl;
    }
    else if(ans.size()==1){
        cout<<-1<<endl;
    }
    else{
        cout<<2<<endl;
        cout<<ans[0][0]<<" "<<ans[0][1]<<endl;
        cout<<ans[0][1]+1<<" "<<n<<endl;
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

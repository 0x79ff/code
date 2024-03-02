#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 1e5+10;
const ll mod = 1e9+7;

int ans[N],cnt,n;
map<int,array<int,2>> m;


void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        int t;cin>>t;
        if(m[n-t][0]!=0){
            m[n-t][0]--;
            ans[i]=m[n-t][1];
        }
            
        else{
            m[n-t]={n-t-1,++cnt};
            ans[i]=cnt;
        }
    }
    bool ok=1;
    for(map<int,array<int,2>>::iterator it=m.begin();it!=m.end();it++)
    {
        if(it->second[0]!=0)
        {
            ok=0;
            break;
        }
    }
    if(ok==0)
        cout<<"Impossible"<<endl;
    else
    {
        cout<<"Possible"<<endl;
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<" ";
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
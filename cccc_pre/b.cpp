#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 1e6+10;
const ll mod = 1e9+7;

ll n,m;
ll a[N];
ll ans;
priority_queue<ll,vector<ll>,less<ll>> x;//从大到小
priority_queue<ll,vector<ll>,greater<ll>> y;//从小到大

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+n+1);

    for(int i=1;i<=n;i++){
        if(i<=(n+1)/2){
            x.push(a[i]);
        }
        else{
            y.push(a[i]);
        }
    }
   // cout<<x.top()<<" "<<y.top()<<endl;
    ans = x.top();x.pop();

    cin>>m;
    for(int i=1;i<=m;i++){
        string op;cin>>op;
        if(op[0]=='m'){
            cout<<ans<<endl;
        }    
        else{
            ll t;cin>>t;
            if(t<=ans) x.push(t);
            else y.push(t);
            
            if(x.size()>y.size()){
                y.push(ans);
                ans=x.top();x.pop();
            }
            else if(x.size()<y.size()-1){
                x.push(ans);
                ans=y.top();y.pop();                   
            }
        }
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

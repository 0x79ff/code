#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

ll pow10[20];
ll n;
ll ans,num;
vector<ll> a,b,c,d,_;
string x;ll y;

void dfs(ll x,ll tmp,ll aa,ll bb,ll cc)
{
    if(x==6){
        //cout<<x<<" "<<tmp<<" ";
        if(tmp<=y && (tmp>=pow10[n-1] || n==1) && tmp%8==0){
            ans++;
           // cout<<"ok";
        }
       // cout<<endl;
        return;
    }
    
    if(x==1){
        if(a.empty()){
            dfs(x+1,tmp,-1,-1,-1);
        }
        else{
            ll t=0;
            for(auto s:a){
               t+=pow10[s];
            }
            for(int i=0;i<10;i++){
               dfs(x+1,tmp+i*t,i,-1,-1);
            }
        }
    }
    
    if(x==2){
        if(b.empty()){
            dfs(x+1,tmp,aa,-1,-1);
        }
        else{
            ll t=0;
            for(auto s:b){
               t+=pow10[s];
            }
            for(int i=0;i<10;i++){
               if(i!=aa) dfs(x+1,tmp+i*t,aa,i,-1);
            }
        }
    }

    if(x==3){
        if(c.empty()){
            dfs(x+1,tmp,aa,bb,-1);
        }
        else{
            ll t=0;
            for(auto s:c){
               t+=pow10[s];
            }
            for(int i=0;i<10;i++){
               if(i!=aa && i!=bb) dfs(x+1,tmp+i*t,aa,bb,i);
            }
        }
    }

    if(x==4){
        if(d.empty()){
            dfs(x+1,tmp,aa,bb,cc);
        }
        else{
            ll t=0;
            for(auto s:d){
               t+=pow10[s];
            }
            for(int i=0;i<10;i++){
               if(i!=aa && i!=bb && i!=cc) dfs(x+1,tmp+i*t,aa,bb,cc);
            }
        }
    }

    if(x==5){
        if(_.empty()){
            dfs(x+1,tmp,aa,bb,cc);
        }
        else{
            ll t=0;
            for(auto s:_){
               t+=pow10[s];
            }
            for(int i=0;i<10;i++){
               dfs(x+1,tmp+i*t,aa,bb,cc);
            }
        }
    }
}

void solve()
{
    cin>>n;
    a.clear();b.clear();c.clear();d.clear();_.clear();
    num=ans=0;
    
 
    cin>>x>>y;
    for(int i=n-1;i>=0;i--){
        if(x[i]=='_') _.push_back(n-1-i);
        else if(x[i]=='d') d.push_back(n-1-i);
        else if(x[i]=='c') c.push_back(n-1-i);
        else if(x[i]=='b') b.push_back(n-1-i);
        else if(x[i]=='a') a.push_back(n-1-i);
        else num+=pow10[n-1-i]*(x[i]-'0');
    }


    dfs(1,num,-1,-1,-1);
    
    cout<<ans<<endl;
}

int main()
{
    IOS;

    //pre
    pow10[0]=1;
    for(int i=1;i<=10;i++) pow10[i] = pow10[i-1]*10;
    int T=1;cin>>T;

    while(T--){
        solve();
    }
    
    return 0;
}
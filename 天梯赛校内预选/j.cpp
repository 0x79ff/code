#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 1e5+10;
const ll mod = 1e9+7;

map<string,pair<int,string>> m;

void solve()
{
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        ll len = s.length();
        s=" "+s;
        map<string,int> t;
        for(int j=1;j<=len;j++){
            for(int k=j;k<=len;k++){
                string ss;
                for(int x=j;x<=k;x++){
                    ss+=s[x];
                }
                if(t[ss]!=0) continue;
                t[ss]=1;
                if(m[ss].first==0){
                    (m[ss].first)++;
                    m[ss].second=s;
                }
                else{
                    (m[ss].first)++;
                }
            }
        }    
    }
    ll q;cin>>q;
    while(q--){
        string s;cin>>s;
        if(m[s].first==0){
            cout<<0<<" "<<"-"<<endl;
        }
        else{
            cout<<m[s].first<<m[s].second<<endl;
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

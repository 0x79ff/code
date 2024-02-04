#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

ll ans[2010];

//快速排序的模拟过程 
//看好交互题的要求 需要1-n  0-n-1肯定不行。。。

char query(ll x){
    char a;
    cout<<"? "<<x<<endl;
    cout.flush();
    cin>>a;
    return a;  
};

void fun(ll cnt,vector<ll> v){
    if(v.size()==0) return;
    if(v.size()==1){
        ans[v[0]] = cnt;
        return;
    }

    vector<ll>p,q;
    while(query(v[0])!='=');
    for(auto s:v){
        if(s==v[0]) continue;
        char c = query(s);
        if(c =='<') p.push_back(s);
        else if(c =='>') q.push_back(s);
        query(v[0]);
    }
    ans[v[0]] = cnt+p.size();
    fun(cnt,p);
    fun(cnt+p.size()+1,q);
    return;
};

void solve()
{
    ll n;
    cin>>n;

    vector<ll> pos;
    for(int i=1;i<=n;i++){
        pos.push_back(i);
    }

    random_shuffle(pos.begin(),pos.end());
    
    fun(0,pos);

    cout<<"! ";
    for(int i=1;i<=n;i++){
        cout<<ans[i]+1<<" ";
    }
    cout<<endl;
    cout.flush();
    return;
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
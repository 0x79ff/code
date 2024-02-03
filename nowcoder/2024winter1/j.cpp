#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

//补题 
//就是个线性的题 想不清楚

void solve()
{
    ll n,x,y;
    cin>>n>>x>>y;
    vector<ll> a;
    for(int i=1;i<=n;i++){
        ll t;cin>>t;
        a.push_back(t);
    }

    auto check = [&](ll mid){
        set<ll> s;
        s.insert(x);s.insert(y);
        for(auto b:a){
            while(!s.empty() && abs(*s.begin()-b)>mid) s.erase(s.begin());
            while(!s.empty() && abs(*s.rbegin()-b)>mid) s.erase(prev(s.end()));
            //set成员函数的用法
            if(s.empty()) return false;
            s.insert(b);
        }
        return true;
    };

    ll lo=abs(x-y),hi=1e9;
    while(lo<hi){
        ll mid = (lo+hi)/2;
        if(check(mid)) hi = mid;
        else lo = mid+1;
    }
    cout<<lo<<endl;
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
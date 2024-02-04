#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"


void solve()
{
    ll n;
    cin>>n;
    if(n==3 || n==5){
        cout<<"no"<<endl;
        return;
    }
    cout<<"Yes"<<endl;
    if(n%2==0){
        cout<<"1 2 ";
        ll a=1,b=2;
        for(int i=2;i<=n/2;i++){
            cout<<-b<<" "<<a-b<<" ";
            ll c = -b,d = a-b;
            a = c;b = d;
        }
    }
    else{
        cout<<"1 -4 1 5 2 -4 3 ";
        ll a = -4,b = 3;
        for(int i=4;i<=n/2;i++){
            cout<<-b<<" "<<a-b<<" ";
            ll c = -b,d = a-b;
            a = c;b = d;
        }
    }
}

int main()
{
    IOS;
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    
    return 0;
}
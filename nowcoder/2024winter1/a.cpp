#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"


ll n;
char a[100];

void solve()
{
    cin>>n;
    cin>>a;
    bool ans1=0,ans2=0;
    bool D,F,S,d,f,s;
    D=F=S=d=f=s=0;
    for(int i=0;i<n;i++){
        if(a[i]=='D') D=1;
        if(a[i]=='F' && D) F=1;
        if(a[i]=='S' && D&&F)S=1;
        if(a[i]=='d') d=1;
        if(a[i]=='f' && d) f=1;
        if(a[i]=='s' && d&&f)s=1;
    }
    cout<<(D&&F&&S)<<" "<<(d&&f&&s)<<endl;
}

int main()
{
    IOS;
    int T;cin>>T;
    while(T--){
        solve();
    }
    
    return 0;
}
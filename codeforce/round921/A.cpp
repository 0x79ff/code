#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=k;j++){
            cout<<char('a'-1+j);       
        }
    cout<<endl;

}


int main()
{
    int T;cin>>T;
    while(T--){
        solve();
    }
    
    return 0;
}
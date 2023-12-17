#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n = 685676213;
    ll ans = 0;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            ans+=i;
            if(i*i!=n) ans+=n/i;
        }
    }
    cout<<ans;
    return 0;
}
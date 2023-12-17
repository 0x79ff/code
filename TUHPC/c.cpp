#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    ll l,r,n;
    double p;
    cin>>n>>p>>l>>r;
    cout<<fixed<<setprecision(10)<<p*(r-l+1);
    return 0;
}
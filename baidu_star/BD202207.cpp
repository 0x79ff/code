#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

//递推 Fermat小定理指数处理 大整数取模运算可以从左到右按照位进行

ll quick_pow(ll x,ll y)
{
    ll re=1;
    x%=mod;
    while(y){
        if(y&1) re=re*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return re;
}


int main()
{
    string a;cin>>a;
    ll tmp = 0;

    for(int i=0;i<a.size();i++){
        tmp*=10;
        tmp+=a[i]-'0';
        tmp%=(mod-1);
    }
    tmp+=1;tmp%=(mod-1);
    if((a[a.size()-1]-'0')%2==0){
        cout<<quick_pow(3,mod-2)*(quick_pow(2,tmp)+1)%mod;
    }
    else{
        cout<<quick_pow(3,mod-2)*(quick_pow(2,tmp)-1)%mod;
    }
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 2e5+10;
const ll inf = 1e18+7;


bool cmp(array<ll,2>x,array<ll,2>y)
{
    return x[1]<y[1];
}

void solve()
{
    ll n,l;
    cin>>n>>l;
    
    vector<array<ll,2>> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1];
    }
    sort(a.begin()+1,a.end(),cmp);

    int ans = 0;
    
    for(int i=1;i<=n;i++){
        priority_queue<ll> pq;
        ll sum = 0;
        for(int j=i;j<=n;j++){
            pq.push(a[j][0]);
            sum += a[j][0];
            while(!pq.empty() && a[j][1] - a[i][1]+sum>l){
                sum-=pq.top();pq.pop();
            }
            ans = max(ans,(int)pq.size());
        }
    }
    cout<<ans<<endl;
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

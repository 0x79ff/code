#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct NODE{
    ll b_val;
    ll c_val;
    int id;
};
bool cmp(NODE x,NODE y)
{
    if(x.b_val == y.b_val)return x.c_val>y.c_val;
    else return x.b_val > y.b_val;
}
void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n + 10), b(n + 10), c(n + 10);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    ll sum0 = 0, sum1 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0){
            if(b[i] == 0)continue;
            else{
                sum0+=min(b[i]-1,c[i]);
            }
        }
        else{
            sum1+=min(b[i],a[i]+c[i]);
        }
    }
    for(int i=1;i<=n;i++){
        ll res = 0;
        ll tmp_sum1 = sum1;
        ll tmp_sum0 = sum0;
        if(a[i]!=0){
            tmp_sum1 -= min(b[i],a[i]+c[i]);
            if(b[i]!=0){
                res = tmp_sum1 + (a[i]+c[i]) + tmp_sum0;
            }
            else{
                if(tmp_sum1 == 0){
                    res = a[i] + c[i];
                }
                else{
                    res = tmp_sum1 + (a[i]+c[i]) + tmp_sum0;
                }
            }
        }
        else{
            if(b[i]!=0){
                tmp_sum0 -= min(b[i]-1,c[i]);
                if(tmp_sum1 == 0){
                    res = 0;
                }
                else{
                    res = tmp_sum1 + tmp_sum0 + c[i];
                }
            }
            else{
                if(tmp_sum1 == 0){
                    res = 0;
                }
                else{
                    res = tmp_sum1 + c[i] + tmp_sum0;
                }
            }
        }
        cout<<res<<" ";
    }
    cout<<"\n";

    ll b_sum = 0;
    ll ans = 0;
    vector<NODE>p;
    for(int i=1;i<=n;i++){
        if(a[i]!=0){
            b_sum += min(b[i],a[i]+c[i]);
            ans+=a[i]+c[i];
        }
        else{
            p.push_back({b[i],c[i],i});
        }
    }
    sort(p.begin(),p.end(),cmp);
    for(int i=0;i<p.size();i++){
        int id = p[i].id;
        if(b_sum == 0)break;
        b_sum--;
        ans += c[id];
        b_sum += min(b[id],1+c[id]);
    }
    cout<<ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}

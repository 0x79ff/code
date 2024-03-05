#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

//补题  
//相关 -> 洛谷P4513 线段树+最大子段和

const ll N = 5e5+100;
const ll inf = -1e18;

ll a[N];
ll n,q;

struct node{
    ll l,r;
    ll sum,mx,allmx,lmx,rmx,rmxsum,lmnsum;
}t[N<<2];

node merge(node x,node y)
{
    node re;
    re.sum=x.sum+y.sum;
    re.allmx=max({x.sum-y.sum,x.allmx-y.sum,x.sum+y.allmx});
    re.mx=max({x.mx,y.mx,x.rmxsum-y.lmnsum,x.rmx-y.lmnsum,x.rmxsum+y.lmx});
    re.lmx=max({x.lmx,x.sum+y.lmx,x.sum-y.lmnsum,x.allmx-y.lmnsum});
    re.rmx=max({y.rmx,x.rmxsum-y.sum,x.rmxsum+y.allmx,x.rmx-y.sum});
    re.rmxsum=max(y.rmxsum,y.sum+x.rmxsum);
    re.lmnsum=min(x.lmnsum,x.sum+y.lmnsum);    
    return re;
}

void build(ll p,ll l,ll r)
{
    if(l==r){
        t[p].l=l;
        t[p].r=r;
        t[p].sum = t[p].mx = t[p].allmx =t[p].lmx=t[p].rmx=t[p].rmxsum=t[p].lmnsum=a[l];
        t[p].mx = t[p].allmx = t[p].lmx = t[p].rmx = inf;
        return;
    }
    ll mid = (l+r)>>1;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    t[p]=merge(t[p*2],t[p*2+1]);
    t[p].l=l;t[p].r=r;
}

void modify(ll p,ll x,ll y)
{
    if(t[p].l==t[p].r && t[p].l==x){
        t[p].sum = t[p].mx = t[p].allmx =t[p].lmx=t[p].rmx=t[p].rmxsum=t[p].lmnsum=y;
        t[p].mx = t[p].allmx = t[p].lmx = t[p].rmx = inf;
        return;
    }
    ll mid = (t[p].l+t[p].r)>>1;
    if(x<=mid){
        modify(p*2,x,y);
    }
    else{
        modify(p*2+1,x,y);
    }
    ll tpl = t[p].l,tpr=t[p].r;
    t[p] = merge(t[p*2],t[p*2+1]);
    t[p].l=tpl,t[p].r=tpr;
}

node ask(ll p,ll l,ll r)
{
    if(l<=t[p].l && t[p].r<=r){
        return t[p];
    }
    
    ll mid = (t[p].l+t[p].r)>>1;

    if(l<=mid && r>mid){
        return merge(ask(p*2,l,r),ask(p*2+1,l,r));
    }
    else if(l<=mid){
        return ask(p*2,l,r);
    }
    else if(r>mid){
        return ask(p*2+1,l,r);
    }
    node err;
    return err;
}

void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    
    build(1,1,n);

    while(q--){
        ll op,x,y;
        cin>>op>>x>>y;
        if(op==1){
            modify(1,x,y);
        }
        else{
            node ans = ask(1,x,y);
            cout<<ans.mx<<endl;
        }
    }
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
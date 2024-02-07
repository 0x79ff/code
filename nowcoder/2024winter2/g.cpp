#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 5e5+100;
const ll inf = -1e18;

ll n,q;
ll a[N],b[N];

struct node{
    ll l,r;
    ll val,le,ri,tag;
} t[N << 2];
 
void pushup(int p)
{
    if(t[p].l == t[p].r) return;
    t[p].le = t[p*2].le;
    t[p].ri = t[p*2+1].ri;
    t[p].val = max(t[p*2].val,t[p*2+1].val);
    t[p].val = max(t[p].val,t[p*2].ri*2 - t[p*2+1].le);
}
 
void build(int p,int l,int r)
{
    if(l==r){
        t[p].val=-1e18;
        t[p].le=b[l];
        t[p].ri=b[r];
        t[p].l=l;
        t[p].r=r;
        t[p].tag=0;
        return ;
    }
    t[p].l=l;
    t[p].r=r;
    t[p].tag=0;
    int mid = l + ((r-l)>>1);
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    pushup(p);
}
 
void pushdown(int p)
{
    if(t[p].l == t[p].r || t[p].tag==0){
        return;
    }
    t[p*2].le+=t[p].tag;
    t[p*2].ri+=t[p].tag;
    t[p*2].tag+=t[p].tag;
    t[p*2+1].le+=t[p].tag;
    t[p*2+1].ri+=t[p].tag;
    t[p*2+1].tag+=t[p].tag;
    t[p].tag = 0;
}
 
void change(int p,int l,int r,ll x)
{
    pushdown(p);
    if(l<=t[p].l && r>=t[p].r){
        t[p].le+=x;
        t[p].ri+=x;
        t[p].tag=x;
        return;
    }
    int m = t[p].l + ((t[p].r-t[p].l)>>1);
    if(l<=m){
        change(p*2,l,r,x);
    }
    if(r>=m+1){
        change(p*2+1,l,r,x);
    }
    pushup(p);   
}
 
ll ask(int p,int l,int r)
{
    cout<<t[p].l<<" "<<t[p].r<<" "<<t[p].val<<endl;
    pushdown(p);
    if(l<=t[p].l && r>=t[p].r){
        return t[p].val;   
    }

    int m = t[p].l + ((t[p].r-t[p].l)>>1);
    if(l<=m && r>=m+1){   
        ll ans=max(ask(p*2,l,r),ask(p*2+1,l,r));
        ans = max(ans,t[p*2].ri*2 - t[p*2+1].le);
        // cout<<t[p*2].l<<" "<<t[p*2].r<<endl;
        // cout<<t[p*2].ri<<" "<<t[p*2+1].le<<endl;
        // cout<<ans<<endl;
        return ans;
    }
    else if(l<=m){
        return ask(p*2,l,r);
    }
    else if(r>=m+1){
       return ask(p*2+1,l,r);
    }
}

ll query(int p,int l,int r)
{
    pushdown(p);
    if(l<=t[p].l && r>=t[p].r){
        return t[p].le;   
    }

    int m = t[p].l + ((t[p].r-t[p].l)>>1);
    ll ans;
    if(l<=m){
        ans = query(p*2,l,r);
    }
    if(r>=m+1){
        ans = query(p*2+1,l,r);
    }
    return ans;
}


void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i] = b[i-1]+a[i];
    }

    build(1,1,n);

    while(q--){
        ll op;cin>>op;
        if(op==1){
            ll x,y;cin>>x>>y;
            change(1,x,n,y-a[x]);
            a[x]=y;
        }
        else{
            ll x,y;cin>>x>>y;
            cout<<ask(1,x,y)<<" "<<query(1,x-1,x-1)<<endl;
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
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 5e5+100;
const ll inf = -1e18;

//最值线段树 注意转化的时候要方便维护

ll n,q;
ll a[N],b[N];//b是a的前缀和

struct node{
    ll l,r;
    ll val,mx,tag;
} t[N << 2];
 
void pushup(int p)
{
    if(t[p].l == t[p].r) return;
    t[p].val = t[p*2].val + t[p*2+1].val;
    t[p].mx = max(t[p*2].mx,t[p*2+1].mx);
}
 
void build(int p,int l,int r)
{
    if(l==r){
        t[p].val=b[l] - 2*a[l];
        t[p].l=l;
        t[p].r=r;
        t[p].mx=t[p].val;
        t[p].tag=0;
        return ;
    }
    t[p].l=l;
    t[p].r=r;
    t[p].tag=0;
    int mid = (l+r)>>1;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    pushup(p);
}
 
void pushdown(int p)
{
    if(t[p].l == t[p].r || t[p].tag==0){
        return;
    }
    t[p*2].mx+=t[p].tag;
    t[p*2].val+=(t[p*2].r-t[p*2].l+1)*t[p].tag;
    t[p*2].tag+=t[p].tag;

    t[p*2+1].mx+=t[p].tag;
    t[p*2+1].val+=(t[p*2+1].r-t[p*2+1].l+1)*t[p].tag;
    t[p*2+1].tag+=t[p].tag;

    t[p].tag = 0;
}
 
void change(int p,int l,int r,ll x)
{
    pushdown(p);
    if(l<=t[p].l && t[p].r<=r){
        t[p].mx+=x;
        t[p].val+=(t[p].r - t[p].l + 1)*x;
        t[p].tag+=x;
        return;
    }
    int m = (t[p].l + t[p].r)>>1;
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
    pushdown(p);
    if(l<=t[p].l && t[p].r<=r){
        return t[p].mx;   
    }

    int m = (t[p].l + t[p].r)>>1;
    if(l<=m && r>=m+1){   
        return max(ask(p*2,l,r),ask(p*2+1,l,r));
    }
    else if(l<=m){
        return ask(p*2,l,r);
    }
    else if(r>=m+1){
       return ask(p*2+1,l,r);
    }
}


void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=b[i-1]+a[i];
    }
    
    build(1,1,n);

    while(q--){
        ll op;cin>>op;
        if(op==1){
            ll x,y;cin>>x>>y;
            ll z = y-a[x];
            if(x!=n) change(1,x+1,n,z);
            change(1,x,x,-z);
            a[x]=y;
        }
        else{
            ll x,y;cin>>x>>y;
            // cout<<ask(1,x,y)<<" "<<ask(1,x-1,x-1)<<" "<<2*a[x-1]<<endl;
            cout<<ask(1,x+1,y)-ask(1,x-1,x-1)-2*a[x-1]<<endl;
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
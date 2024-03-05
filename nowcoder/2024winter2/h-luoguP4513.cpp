#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

//补题  
//洛谷P4513 线段树+最大子段和

const ll N = 5e5+100;
const ll inf = -1e18;

ll n,m;
ll a[N];

struct node{
    ll l,r;
    ll mx,sum,mxl,mxr;
}t [N<<2];

void pushup(ll p)
{
    if(t[p*2].mxr>=0 && t[p*2+1].mxl>=0) t[p].mx = t[p*2].mxr + t[p*2+1].mxl;
    else t[p].mx = max(t[p*2].mxr,t[p*2+1].mxl);

    t[p].mx = max(t[p].mx,t[p*2].mx);
    t[p].mx = max(t[p].mx,t[p*2+1].mx);

    t[p].mxl = max(t[p*2].mxl,t[p*2].sum+t[p*2+1].mxl);
    t[p].mxr = max(t[p*2+1].mxr,t[p*2+1].sum+t[p*2].mxr);
    
    t[p].sum = t[p*2].sum+t[p*2+1].sum;
    
}

//单点修改 无需pushdown

void build(ll p,ll l,ll r)
{
    if(l==r){
        t[p].l = l;
        t[p].r = r;
        t[p].mx = t[p].mxl = t[p].mxr = t[p].sum = a[l];
        return;
    }
    t[p].l = l;
    t[p].r = r;
    ll mid = (l+r)>>1;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    pushup(p);
}

array<ll,4> ask(ll p,ll l,ll r)
{
    if(l<=t[p].l && t[p].r<=r){
        return {t[p].mx,t[p].mxl,t[p].mxr,t[p].sum};
    }

    ll mid = (t[p].l+t[p].r)>>1;
    
    if(l<=mid && r>=mid+1){
        array<ll,4> n1,n2,re;
        n1 = ask(p*2,l,r);
       // cout<<n1[0]<<" "<<n1[1]<<" "<<n1[2]<<" "<<n1[3]<<endl;

        n2 = ask(p*2+1,l,r);
       // cout<<n2[0]<<" "<<n2[1]<<" "<<n2[2]<<" "<<n2[3]<<endl;

        if(n1[2]>=0 && n2[1]>=0) re[0] = n1[2] + n2[1];
        else re[0] = max(n1[0],n2[0]);

        re[0] = max(re[0],n1[0]);
        re[0] = max(re[0],n2[0]);

        re[1]=max(n1[1],n1[3]+n2[1]);
        re[2]=max(n2[2],n2[3]+n1[2]);

        re[3] = n1[3]+n2[3];

        return re;        
    }
    else if(r<=mid){
        return ask(p*2,l,r);
    }
    else if(l>mid){
        return ask(p*2+1,l,r);
    }
}

void modify(ll p,ll x,ll y)
{
    if(t[p].l == t[p].r && t[p].l == x){
        t[p].mx = t[p].mxl = t[p].mxr = t[p].sum = y;
        return;
    }
    
    ll mid = (t[p].l + t[p].r)>>1;
    if(x<=mid){
        modify(p*2,x,y);
    }
    if(x>=mid+1){
        modify(p*2+1,x,y);
    }
    pushup(p);
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    build(1,1,n);
    while(m--){
        ll op,x,y;cin>>op>>x>>y;
        if(op==1){
            if(x>y) swap(x,y);
            array<ll,4> ans = ask(1,x,y);
            cout<<ans[0]<<endl;
        }
        else{
            modify(1,x,y);
        }
    }
}

int main()
{
    IOS;
    int T=1;//cin>>T;
    while(T--){
        solve();
    }
    
    return 0;
}
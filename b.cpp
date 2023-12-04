#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

const int N = 2e5+10;
ll l[N],r[N];
ll now[N];

struct node{
    ll x,y;
};
unordered_map<node,int> vis;

vector<node> a;

bool cmp(node t1,node t2){
    return t1.y < t2.y;
}


int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int n,m;
    for(int i=1;i<=m;i++){
        ll l,r;cin>>l>>r;
        a.push_back({i,l});
        a.push_back({i,r});
    }
    
    sort(a.begin(),a.end(),cmp);

    queue<ll> c;

    for(int i=0;i<a.size();i++){
        if(now[a[i].x]==0){
            c.push_back();
        }
    }


    return 0;
}


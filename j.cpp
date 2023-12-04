#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

const int N = 2e5+100;

ll n,m,a,b,c[N];

vector<ll> e[N];
ll dis[N],vis[N];
vector<int> day[N];


struct node{
    ll pos,val;
};


void solve()
{
    cin>>n>>m>>a>>b;
    for(int i=1;i<=n+10;i++){
        e[i].clear();
        dis[i] = vis[i]= 0;
        day[i].clear();
    }

    
    for(int i=1;i<=m;i++){
        ll u,v;cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        cin>>c[i];
    }


    if(a==b){
        queue<int> q;
        q.push(1);
        vis[1]=1;
        dis[1]=0;
        while(!q.empty()){
            int pos = q.front();q.pop();
            for(auto s:e[pos]){
                if(c[s]<c[1] - b && vis[s] == 0){
                    vis[s] = 1;
                    dis[s] = dis[pos] + 1;
                    q.push(s);
                }
            }
        }
        cout<<(vis[n] ? dis[n] : -1)<<endl;
    }

    else if(a<b){
        //会有最晚攻击时间 直接bfs去找player第i天能到达的所有的点 之中维护好player的能力值
        queue<node> q;
        q.push({1,c[1]-b});
        vis[1]=1;
        dis[1]=0;
        
        while(!q.empty()){
            node t = q.front();q.pop();
            for(auto s:e[t.pos]){
                if(c[s] < t.val  && vis[s] == 0){
                    vis[s] = 1;
                    dis[s] = dis[t.pos] + 1;
                    q.push({s,t.val + a - b});//
                }
            }
        }
        cout<<(vis[n] ? dis[n] : -1)<<endl;
    }

    else if(a>b){
        vector<int> ti(n+10,0);//最早可刷时间

        for(int i=2;i<=n;i++){
            ti[i] = max(1ll,(c[i]+1 - (c[1] - b) + a-b-1)/(a-b) + 1);    
        }

        ll cnt = 0;//能打的怪的数目
        queue<int> q;
        q.push(1);vis[1]=1;dis[1]=0;
        
        //每天只能打一个怪
        
        for(int i=1;i<=n;i++){
            for(auto s:day[i]){
                q.push(s);
                if(dis[s]==0){
                    dis[s]=i;
                    cnt++;
                } 
            }
            while(!q.empty()){
                int pos = q.front();q.pop();
                for(auto s:e[pos]){
                    if(vis[s]==0){
                        vis[s]=1;
                        if(ti[s]<=i){
                            dis[s]=i;
                            cnt++;
                            day[i+1].push_back(s);
                        }
                        else{
                            day[ti[s]].push_back(s);
                        }
                    }
                }
            }
            
            //每天肯定要打一个怪
            if(cnt>0) cnt--;
            else break;

        }
        cout<<(dis[n] ? dis[n] : -1)<<endl;
    }
    

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    

    return 0;
}


/*

2
5 4 5 8
1 2
1 3
1 4
4 5
15 1 1 1 1
5 4 10 5
1 2
1 3
1 4
4 5
10 4 4 4 19

2 
4





*/
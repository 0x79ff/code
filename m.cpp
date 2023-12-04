#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN=2e5+5;
const ll INF=1e17;

ll n,m,A,B;
vector<ll>to[MAXN];
ll l[MAXN],d[MAXN];
bool vis[MAXN],isreach[MAXN];
ll dis[MAXN];

struct qnode{
	ll v,c;
	bool operator<(const qnode y)const{
		return c>y.c;
	}
};

void init(){
	for(int i=1;i<=n;i++){
		vis[i]=0;
		dis[i]=INF;
	}
}

void bfs(){
	init();
	priority_queue<qnode>q;
	ll now=0;
	isreach[1]=1;
	vis[1]=1;
	for(auto u:to[1]){if(!vis[u])q.push({u,d[u]});vis[u]=1;}
	while(!q.empty()){
		int u=q.top().v;
		q.pop();
		if(d[u]<=now){
			now++;
			isreach[u]=1;
			for(auto y:to[u]){
				if(vis[y])continue;
				else {
					vis[y]=1;
					q.push({y,d[y]});
				}
			}
		}
	}
}

void dijkstra(){
	init();
	priority_queue<qnode>q;
	dis[1]=0;
	q.push({1,0});
	while(!q.empty()){
		int v=q.top().v;
		q.pop();
		if(vis[v])continue;
		vis[v]=1;
		for(auto y:to[v]){
			if(vis[y]||!isreach[y])continue;
			if(dis[y]>max(d[y]+1,dis[v]+1)){
				dis[y]=max(d[y]+1,dis[v]+1);
				q.push({y,dis[y]});
			}
		}
	}
}

void bfs1(){
	init();
	deque<qnode>q;
	q.push_back({1,0});
	dis[1]=0;
	while(!q.empty()){
		int v=q.front().v;
		q.pop_front();
		if(vis[v])continue;
		vis[v]=1;
		for(auto y:to[v]){
			if(vis[y]||l[y]>=l[1])continue;
			if(dis[y]>dis[v]+1){
				dis[y]=dis[v]+1;
				q.push_back({y,dis[y]});
			}
		}
	}
}

void bfs2(){
	init();
	deque<qnode>q;
	q.push_back({1,0});
	dis[1]=0;
	while(!q.empty()){
		int v=q.front().v;
		q.pop_front();
		if(vis[v])continue;
		vis[v]=1;
		for(auto y:to[v]){
			if(vis[y]||dis[v]>d[y])continue;
			if(dis[y]>dis[v]+1){
				dis[y]=dis[v]+1;
				q.push_back({y,dis[y]});
			}
		}
	}
}

int main(){
	int t;scanf("%d",&t);
	while(t--){
		
		scanf("%lld%lld%lld%lld",&n,&m,&A,&B);
		for(int i=1;i<=m;i++){
			int a,b;scanf("%d%d",&a,&b);
			to[a].push_back(b);
			to[b].push_back(a);
		}
		for(int i=1;i<=n;i++)scanf("%lld",&l[i]);
		for(int i=2;i<=n;i++)l[i]+=B;
		if(A>B){
			for(int i=2;i<=n;i++){if(l[i]>=l[1])d[i]=(l[i]-l[1])/(A-B)+1;else d[i]=0;}
			bfs();
			dijkstra();
			if(dis[n]<INF&&isreach[n])printf("%lld\n",dis[n]);
			else printf("-1\n");
		}else if(A==B){
			bfs1();
			if(dis[n]<INF&&l[n]<l[1])printf("%lld\n",dis[n]);
			else printf("-1\n");
		}else{
			for(int i=2;i<=n;i++){if(l[1]-l[i]<=0)d[i]=-1;else d[i]=(l[1]-l[i]+B-A-1)/(B-A)-1;}
			bfs2();
			if(dis[n]<INF)printf("%lld\n",dis[n]);
			else printf("-1\n");
		}
		for(int i=1;i<=n;i++){
			to[i].clear();
			isreach[i]=0;
		}
	}
	return 0;
}

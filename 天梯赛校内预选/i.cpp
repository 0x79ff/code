#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 550;
const ll inf = 1e9+7;

char a[N][N];
bool vis[N][N];
int dp[N][N];
const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};
const int ddx[16] = {-2,-2,-2,-1,-1,-1,-1,0,0,1,1,1,1,2,2,2};
const int ddy[16] = {-1,0,1,-2,-1,1,2,-2,2,-2,-1,1,2,-1,0,1};
int n,m;

bool inr(int x,int y)
{
    return x>=1 && x<=n && y>=1 && y<=m;
}

vector<array<ll,3>> v;

void dfs(int z,int x,int y)
{
    for(int i=0;i<4;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if(inr(xx,yy)&&a[xx][yy]=='.'){
            dp[xx][yy] = min(dp[xx][yy],z);
            if(vis[xx][yy]==0){
                vis[xx][yy]=1;
                v.push_back({z,xx,yy});
                dfs(z,xx,yy);    
            }
            
        }
    }  
}

void se(int z,int x,int y)
{
    for(int i=0;i<16;i++){
        int xx=x+ddx[i],yy=y+ddy[i];
        if(inr(xx,yy)){
            dp[xx][yy] = min(dp[xx][yy],z+1);
            if(vis[xx][yy]==0){
                vis[xx][yy]=1;
                v.push_back({z+1,xx,yy});     
            }
           
        }
    }
}

void solve()
{

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        for(int j=1;j<=m;j++){
            a[i][j] = s[j-1];
            dp[i][j] = inf;
        }
    }

    //bfs
    priority_queue<array<ll,3>,vector<array<ll,3>>,greater<array<ll,3>>> q;
    q.push({0,1,1});
    vis[1][1]=1;
    dp[1][1]=0;
    
    while(!q.empty()){
        array<ll,3> s = q.top();
        q.pop();
        s[0]=dp[s[1]][s[2]];
        //cout<<"pop:"<<s[0]<<" "<<s[1]<<" "<<s[2]<<endl;
        
        //找这个点所有联通的点
        v.clear();
        dfs(s[0],s[1],s[2]);
        for(auto s:v){
            //cout<<s[0]<<" "<<s[1]<<" "<<s[2]<<endl;
            q.push(s);
        }
        
        //找使用一次技能可以到的
        v.clear();
        se(s[0],s[1],s[2]);
        for(auto s:v){
          //  cout<<s[0]<<" "<<s[1]<<" "<<s[2]<<endl;
            q.push(s);
        }
        
    }
    cout<<dp[n][m]<<endl;
}

int main()
{
   // IOS;
    int T=1;//cin>>T;
    while(T--){
        solve();
    }
    
    return 0;
}

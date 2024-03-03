#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 550;
const ll inf = 1e9+7;

char a[N][N];
bool vis[N][N];
const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};
int n,m;

bool inr(int x,int y)
{
    return x>=1 && x<=n && y>=1 && y<=m;
}


void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        for(int j=1;j<=m;j++){
            a[i][j] = s[j-1];
        }
    }

    //01 bfs
    deque<array<int,3>> q;

    q.push_front({0,1,1});
    
    while(!q.empty()){
        array<int,3> s;
        s=q.front();
        q.pop_front();
        if(vis[s[1]][s[2]]) continue;

        vis[s[1]][s[2]]=1;
        //cout<<s[1]<<" "<<s[2]<<" "<<s[0]<<endl;

        if(s[1]==n & s[2]==m){
            cout<<s[0]<<endl;
            return;
        }

        for(int i=0;i<4;i++){
            int xx=s[1]+dx[i],yy=s[2]+dy[i];
            if(inr(xx,yy)&&!vis[xx][yy]){
                if(a[xx][yy]=='.'){
                    q.push_front({s[0],xx,yy});
                }
            }    
        }

        for(int i=-2;i<=2;i++){
            for(int j=-2;j<=2;j++){
                if(i==0 && j==0) continue;
                if(abs(i)==2 && abs(j)==2) continue;
                int xx = s[1]+i,yy = s[2]+j;
                if(inr(xx,yy) && !vis[xx][yy]){
                    q.push_back({s[0]+1,xx,yy});
                }
            }
        }
        
    }
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

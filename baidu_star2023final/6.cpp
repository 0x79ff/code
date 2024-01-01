#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e2+10;
const ll inf = 1e18;
ll n,m,q;
ll d[N][N][2][40];
ll f[N][2][40];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=0;k<=30;k++){
                d[i][j][0][k]=inf;
                d[i][j][1][k]=-1;           
            }
        }
    }
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        d[u][v][0][0] = min(d[u][v][0][0],w);
        d[u][v][1][0] = max(d[u][v][1][0],w);
        d[v][u][0][0] = min(d[v][u][0][0],w);
        d[v][u][1][0] = max(d[v][u][1][0],w);
    }
    
    for(int i=1;i<=30;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                for(int l=1;l<=n;l++){
                    //min jk jl lk
                    if(d[j][l][0][i-1]!=inf && d[l][k][0][i-1]!=inf){
                        d[j][k][0][i] = min(d[j][k][0][i],d[j][l][0][i-1]+d[l][k][0][i-1]);
                    }
                    //max
                    if(d[j][l][1][i-1]!=-1 && d[l][k][1][i-1]!=-1){
                        d[j][k][1][i] = max(d[j][k][1][i],d[j][l][1][i-1]+d[l][k][1][i-1]);
                    }
                }
            }
        }
    }

    
    for(int i=1;i<=q;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        memset(f,0,sizeof(f));

        for(int j=1;j<=n;j++){
            for(int k=0;k<=30;k++){
                f[j][0][k]=inf;
                f[j][1][k]=-1;           
            }
        }
      

        int len;
        for(int j=0;j<=30;j++){
            if(z & (1<<j)){
                len = j;
            }
        }   
        
        for(int j=len;j>=0;j--){
            if((z & (1<<j))==0){
                for(int k=1;k<=n;k++){
                    f[k][0][j] = f[k][0][j+1];
                    f[k][1][j] = f[k][1][j+1];
                }
            }
            else{
                if(j==len){    
                    for(int k=1;k<=n;k++){
                        if(d[x][k][0][j]!=inf){
                            f[k][0][j] = d[x][k][0][j];
                        }
                        if(d[x][k][1][j]!=-1){
                            f[k][1][j] = d[x][k][1][j];
                        }
                    }   
                }
                else{
                    for(int k=1;k<=n;k++){
                        for(int l=1;l<=n;l++){
                            if(f[l][0][j+1]!=inf && d[l][k][0][j]!=inf){
                                f[k][0][j] = min(f[k][0][j],f[l][0][j+1]+d[l][k][0][j]);
                            }
                            if(f[l][1][j+1]!=-1 && d[l][k][1][j]!=-1){
                                f[k][1][j] = max(f[k][1][j],f[l][1][j+1]+d[l][k][1][j]);
                            }
                        }
                    }
                }
            }
           // cout<<f[1][0][j]<<" "<<f[2][0][j]<<" "<<f[3][0][j]<<endl;
        }
        
        if(f[y][0][0]!=inf) cout<<f[y][0][0];
        else cout<<-1;
        cout<<" ";
        if(f[y][1][0]!=-1) cout<<f[y][1][0];
        else cout<<-1;
        cout<<endl;
    }
    return 0;
}
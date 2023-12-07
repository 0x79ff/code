#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

const int N = 1e4+10;
const int D = 30;

ll w[N],q[N][D],k[N][D],v[N][D],kt[D][N];
ll b[D][D],c[N][D];

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    
    int n,d;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=d;j++){
            cin>>q[i][j];
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=d;j++){
            cin>>k[i][j];
            kt[j][i]=k[i][j];
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=d;j++){
            cin>>v[i][j];
        }
    }   

    for(int i=1;i<=n;i++){
        cin>>w[i];
    }


    for(int i=1;i<=d;i++){
        for(int j=1;j<=d;j++){
            for(int x=1;x<=n;x++){
                b[i][j]+=kt[i][x]*v[x][j];
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=d;j++){
            for(int x=1;x<=d;x++){
                c[i][j]+=q[i][x]*b[x][j];
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=d;j++){
            c[i][j]*=w[i];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=d;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    

    return 0;
}


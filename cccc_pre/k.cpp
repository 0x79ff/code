#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
ll n,m;

const ll N = 3000;
const ll mod = 998244353;

ll dp[2][N];

void solve()
{
    cin>>n>>m;
    if(n*m%2==1){
        cout<<0;
        return;
    }
    if(m==1 || n==1){
        cout<<1;
        return;
    } 

    for(int i=0;i<(1<<(m+1));i++){
        dp[0][i]=0;
    }
    dp[0][(1<<(m+1)) - 1]=1;

    for(int i=1;i<=n*m;i++){
        int p = i%2,q=1-p;
        for(int j=0;j<(1<<(m+1));j++){
            dp[p][j]=0;
        }

        if(i%m!=1){
            for(int j=0;j<(1<<(m+1));j++){
                if(( (j&(1<<(m))) == 0) && ( (j & (1<<(m-1))) == 0) && ((j & (1<<0)) == 0)){
                    int k=j;
                    k|=(1<<(m));k|=(1<<(m-1));k|=(1<<0);
                    k = ((k<<1) & ((1<<(m+1))-1));
                    k+=1;
                    dp[p][k]+=dp[q][j];
                    dp[p][k]%=mod;
                }
            }   
        }
        for(int j=0;j<(1<<(m+1));j++){
            if( ((j & (1<<(m-1))) == 0) && ((j & (1<<(m))) != 0)  ){
                int k=j;
                k|=(1<<(m-1));
                k = ((k<<1) & ((1<<(m+1))-1));
                k+=1;
                dp[p][k]+=dp[q][j];
                dp[p][k]%=mod;
            }
        } 

        if(i%m!=1){
            for(int j=0;j<(1<<(m+1));j++){
                if(((j & (1<<0)) == 0) && ((j & (1<<(m))) != 0) ){
                    int k=j;
                    k|=(1<<0);
                    k = ((k<<1) & ((1<<(m+1))-1));
                    k +=1;
                    dp[p][k]+=dp[q][j];
                    dp[p][k]%=mod;
                }
            }         
    
        }
        
        for(int j=0;j<(1<<(m+1));j++){
            if(((j & (1<<(m)))!=0)){
                int k=j;
                k = ((k<<1) & ((1<<(m+1))-1));
                dp[p][k]+=dp[q][j];
                dp[p][k]%=mod;
            }
        }        

        for(int j=0;j<(1<<(m+1));j++){
            if(i%m==0 && ((j & (1<<(m)))==0)){
                dp[p][j]=0;
            }
            if( ((j & (1<<(m)))==0) && ( ((j & (1<<(m-1)))!=0) ||  ((j & (1<<0))!=0)) ){
                dp[p][j]=0;
            }
        }
    }
    cout<<dp[n*m%2][(1<<(m+1))-1];
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
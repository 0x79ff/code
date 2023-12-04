#include<bits/stdc++.h>
using namespace std;
typedef __int128 ll;
#define endl '\n'


//__int128的read和write  好像不能和sync共同使用
inline __int128 read(){
    __int128 num=0; char g=getchar(); while(g<48||57<g) g=getchar();
    while(47<g&&g<58) num=(num<<1)+(num<<3)+g-48,g=getchar(); return num;
}
inline void write(__int128 u){
    if(u>9) write(u/10); putchar(u%10+'0');
}


const ll NO=3e18;

ll dp[25][25][2];
ll mi[20]={1};

ll fun1(ll a,ll b ){
    return (a/mi[b])%10;
}

ll fun2(ll a,ll b){
    return a*mi[b];
}

ll fun3(ll a,ll b){
    int cnt=0;
    while(a||b){
        if(a%10!=b%10)cnt++;
        a/=10;
        b/=10;
    }
    return cnt-1;
}


void solve(){
    for(int i=0;i<=21;i++){
        for(int j=0;j<=21;j++){
            dp[i][j][1]=dp[i][j][0]=NO;
        }
    }
    ll x;
    ll k;

    x=read();k=read();
    if(k==0){
        ll y=1;
        while(x%10==9){
            y*=10;
            x/=10;
        }
        write(y);
        putchar('\n');
        return;

    }


    int len=0;
    while(x%10==0){
        len++;
        x/=10;
    }

    for(int i=0;i<=20;i++){
        dp[i][0][0]=x;
    }
    for(int i=0;i<=18;i++){
        for(int j=0;j<=18;j++){
            
            if(i!=0)dp[i][j][0]=min(dp[i][j][0],dp[i-1][j][0]);
            if(i!=0)dp[i][j][0]=min(dp[i][j][0],dp[i-1][j][1]);
            //if(1)cout<<"i="<<i<<" j="<<j<<" dp="<<dp[i][j][0]-x<<" "<<dp[i][j][1]-x<<endl;
            if(dp[i][j][1]!=NO){
                int tem=fun1(dp[i][j][1],i);
                if(tem!=0){
                    tem=10-tem;
                    ll b=dp[i][j][1]+fun2(tem,i);
                    int ch=fun3(dp[i][j][1],b);
                    //cout<<"a="<<dp[i][j]<<" b="<<b<<" ch="<<ch<<endl;
                    dp[i+1][j+ch][1]=min(dp[i+1][j+ch][1],b);
                    
                    //cout<<"dp"<<i+1<<" "<<j+ch<<" ="<<min(dp[i+1][j+ch][1],b)<<endl;
                }
                dp[i+1][j][0]=min(dp[i+1][j][0],dp[i][j][1]);
                
            }
            if(dp[i][j][0]!=NO){
                int tem=fun1(dp[i][j][0],i);
                if(tem!=0){
                    tem=10-tem;
                    ll b=dp[i][j][0]+fun2(tem,i);
                    int ch=fun3(dp[i][j][0],b);
                    //cout<<"a="<<dp[i][j]<<" b="<<b<<" ch="<<ch<<endl;
                    dp[i+1][j+ch][1]=min(dp[i+1][j+ch][1],b);
                    
                    //cout<<"dp"<<i+1<<" "<<j+ch<<" ="<<min(dp[i+1][j+ch][1],b)<<endl;
                }
                dp[i+1][j][0]=min(dp[i+1][j][0],dp[i][j][0]);
                
            }
            
        }
    }
    ll miny=NO;
    for(int i=0;i<19;i++){
        
        miny=min(miny,dp[i][k][0]);
    }
    //cout<<miny<<endl;
    for(int i=0;i<19;i++){
        miny=min(miny,dp[i][k][1]);
        //if(dp[i][k][1]<=0)cout<<i<<endl;
    }
        
   write(miny-x);
    
    while(len--){
        cout<<0;
    }
    putchar('\n');
    //cout<<min(dp[18][k]-x,dp[17][k]-x)<<endl;
}


int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int tt=1;
    cin>>tt;
    for(int i=1;i<=19;i++){
        mi[i]=mi[i-1]*10;
    }
    while(tt--){
        solve();
    }
    

    return 0;
}

/*
4
12345678 0
12345678 5
12345678 18
990099 5
*/
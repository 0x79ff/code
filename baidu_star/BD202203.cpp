#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int inf=1e9+10;
int d[N];
int n;
int dp[N][2];

//dp[i][0] 把第i个元素放到上升序列时，下降序列结尾的最大值

//实际上需要记录的信息 每个元素放到（0-1）哪个中，上升和下降的最值

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    dp[0][0]=inf;
    dp[0][1]=0;
    for(int i=1;i<n;i++){
        dp[i][0]=0;
        dp[i][1]=inf;

        if(d[i]>=d[i-1]){
            dp[i][0]=max(dp[i][0],dp[i-1][0]);
        }
        if(d[i]>=dp[i-1][1]){
            dp[i][0]=max(dp[i][0],d[i-1]);
        }
        if(d[i]<=dp[i-1][0]){
            dp[i][1]=min(dp[i][1],d[i-1]);
        }
        if(d[i]<=d[i-1]){
            dp[i][1]=min(dp[i][1],dp[i-1][1]);
        }
        // if(dp[i][0]==0&&dp[i][1]==inf){
        //     break;
        // }
    }
    cout<<(dp[n-1][0]!=0||dp[n-1][1]!=inf?"yes":"no")<<"\n";

    return 0;
}
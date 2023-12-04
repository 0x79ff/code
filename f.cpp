#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

ll n;
const int N = 2010;
int b[N],c[N];

void solve()
{
    cin>>n;
    b[1]=1;
    for(int i=2;i<=n;i++){
        //二分
        int l=1,r=i-1;
        int ipos=0;//i最后放在ipos右边
        while(l<=r){
            int mid = (l+r)/2;
            int midpos = b[mid];
            
            ll t1,t2;
            cout<<"? "<<midpos<<" "<<i<<endl;
            cout.flush();
            cin>>t1;
            cout<<"? "<<midpos+1<<" "<<i<<endl;
            cout.flush();
            cin>>t2;
            if((t1-t2-c[midpos])%2==0){
                l = mid+1;
                ipos=mid;
            }
            else{
                r = mid-1;
            }
            
        }
        
        vector<int> tb(n+10,0);
        for(int j=1;j<=i;j++){
            if(j<=ipos){
                tb[j] = b[j];
            }
            if(j==ipos+1){
                tb[j] = i;
            }
            if(j>ipos+1){
                tb[j] = b[j-1];
                c[b[j-1]] ++;
            }
        }
        for(int j=1;j<=i;j++){
            b[j] = tb[j];
        }
    }
    
    vector<int> ans(n+10,0);
    for(int i=1;i<=n;i++){
        ans[b[i]] = i;
    }
    cout<<"! ";
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout.flush();
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int tt=1;
    //cin>>tt;
    while(tt--){
        solve();
    }
    

    return 0;
}


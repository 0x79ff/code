#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,k,m;
string s;

void solve()
{
    cin>>n>>k>>m;
    cin>>s;
    vector<bool>vis(30,0);
    int cnt = 0,num = 0;
    vector<char>ans;

    for(int i=0;i<s.size();i++){
        if(vis[s[i]-'a']==0 && s[i]-'a'<k){
            vis[s[i]-'a']=1;
            cnt++;
            if(cnt==k){
                for(int i=0;i<k;i++){
                    vis[i]=0;
                }
                cnt=0;
                num++;
                
                ans.push_back(s[i]);

                if(num==n){
                    cout<<"yes\n";
                    return;
                }
            }
        }
    }   
    
    cout<<"no\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }
    for(int i=0;i<k;i++){
        if(vis[i]==0){
            cout<<(char)('a'+i);
            break;
        }
    }
    for(int i=1;i<=n-num-1;i++){
        cout<<"a";
    }
    cout<<"\n";


}



int main()
{
    int T;cin>>T;
    while(T--){
        solve();
    }
    
    return 0;
}
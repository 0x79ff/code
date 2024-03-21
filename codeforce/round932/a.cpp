#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 1e5+10;
const ll mod = 1e9+7;

int n;
string s;


void solve()
{
    cin>>n;
    cin>>s;
    int flag = 0;
    int len = s.size();
    for(int i=0;i<len;i++){
        if(s[i]!=s[len-1-i]){
            if(s[i]>s[len-1-i]){
                flag=1;
                break;
            }
            else if(s[i]<s[len-1-i]){
                flag=2;
                break;
            }
        }
    }

    if(flag==0){
        cout<<s<<endl;
    }
    else if(flag==2){
        cout<<s<<endl;
    }
    else{
        reverse(s.begin(),s.end());
        cout<<s;
        reverse(s.begin(),s.end());
        cout<<s<<endl;
        
    }
    
}

int main()
{
    IOS;
    int T=1;cin>>T;
    while(T--){
        solve();
    }
    
    return 0;
}

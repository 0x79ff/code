#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'


int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int n;
    cin>>n;
    unordered_map<int,array<int,2>> b;//place begintime endtime
    unordered_map<int,bool> vis;//is visited  !!why
    set<array<int,3>> c;//time person place 
    for(int day=0;day<n;day++){
        int r,m;
        cin>>r>>m;
        while(r--){
            int p;
            cin>>p;
            if(!vis[p]){
                vis[p]=1;
                b[p][0]=day;
                b[p][1]=day+6;
            }
            else{   
                if(b[p][1]+1>=day){
                    b[p][1]=day+6;
                }
                else{
                    b[p][0]=day;
                    b[p][1]=day+6;
                }   
            }
        }
        while(m--){
            array<int,3> t;
            cin>>t[0]>>t[1]>>t[2];
            c.insert(t);
        }

        set<int> ans;
        set<array<int,3>> newc;
        for(auto s:c){
            if(s[0]+6<day){
                ;
            }
            else{
                newc.insert(s);
                if(b[s[2]][0] <= s[0] && b[s[2]][1]>=day && b[s[2]][1]!=0){
                    ans.insert(s[1]);
                }
            //     if(b[s[2]][0] <= s[0] && b[s[2]][1]>=day && vis[s[2]]){
            //         ans.insert(s[1]);
            //     }
            }
        }
        c=newc;

        cout<<day<<" ";
        for(auto s:ans){
            cout<<s<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}


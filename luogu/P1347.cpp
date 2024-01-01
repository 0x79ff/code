#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;
ll b[1000],c[1000];


int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        string t;
        cin>>t;
        b[i]=t[0];
        c[i]=t[2];
    }

    
    for(int i=1;i<=m;i++){
        stack<int> s;
        vector<char>ans;
        vector<int>id(50,0),vis(50,0);
        vector<int> v[50];
        bool ok=1;
        
        for(int j=1;j<=i;j++){
            id[c[j]-'A']++;
            v[b[j]-'A'].push_back(c[j]-'A');
        }
        
        for(int j=0;j<n;j++){
            if(id[j]==0){
                s.push(j);
                vis[j]=1;
            }
        }
        
        int j;
        for(j=1;j<=n;j++){
            if(s.empty()){
                cout<<"Inconsistency found after "<<i<<" relations.";
                return 0;
            }
            else{
                if(s.size()>1) ok=0;
                int x = s.top();s.pop();
                ans.push_back((char)(x+'A'));
                for(auto xx:v[x]){
                    if(!vis[xx]){    
                        id[xx]--;
                        if(id[xx]==0){
                            vis[xx]=1;
                            s.push(xx);
                        }   
                    }
                }
            }
        }
        
        if(j==n+1 && ok){
            cout<<"Sorted sequence determined after "<<i<<" relations: ";
            for(auto x:ans){
                cout<<x;
            }
            cout<<".";
            return 0;
        }
        
    }

    
    cout<<"Sorted sequence cannot be determined.";
    return 0;
}
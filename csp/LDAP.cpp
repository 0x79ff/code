#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2500+100; //人最多2500个
ll n,m;
ll a[N];

struct node{
    ll x,y;
};
unordered_map<ll,vector<node>> b;
//存储每个属性有哪些人 值是多少

void solve()
{
    stack<vector<ll>> st;
    string s;cin>>s;
    reverse(s.begin(),s.end());
    
    int len = s.length();
    for(int i=0;i<len;){
        if(s[i]=='&' || s[i] == '|'){
            vector<ll> t1,t2,t3;
            t1 = st.top(); st.pop();
            t2 = st.top(); st.pop();
            //merge
            int len1 = t1.size(), len2 = t2.size();
            
            if(s[i]=='|'){                
                int x1=0,x2=0;
                for(;x1<len1 && x2<len2;){
                    if(t1[x1]<t2[x2]){
                        t3.push_back(t1[x1]);
                        x1++;
                    }
                    else if(t1[x1]>t2[x2]){
                        t3.push_back(t2[x2]);
                        x2++;
                    }
                    else{
                        t3.push_back(t1[x1]);
                        x1++;x2++;
                    }
                }
                while(x1<len1){
                    t3.push_back(t1[x1]);
                    x1++;
                }
                while(x2<len2){
                    t3.push_back(t2[x2]);
                    x2++;
                }
            }

            else{
                int x1=0,x2=0;
                for(;x1<len1 && x2<len2;){
                    if(t1[x1]<t2[x2]){
                        x1++;
                    }
                    else if(t1[x1]>t2[x2]){
                        x2++;
                    }
                    else{
                        t3.push_back(t1[x1]);
                        x1++;x2++;
                    }
                }
            }

            st.push(t3);
            i++;
        }  
        
        else if(s[i]=='(' || s[i]==')'){
            i++;
        }

        else{
            ll num1 = 0,num2 = 0;
            ll pow10 = 1;
            char op;
            int j;
            for(j=i;j<len;j++){
                if(s[j]>='0' && s[j]<='9'){
                    num2+=pow10*(s[j]-'0');
                    pow10*=10;
                }
                else{
                    op = s[j];
                    break;
                }
            }
            pow10 = 1;
            
            for(j=j+1;j<len;j++){
                if(s[j]>='0' && s[j]<='9'){
                    num1+=pow10*(s[j]-'0');
                    pow10*=10;
                }
                else{
                    break;
                }
            }
            i=j;

            vector<ll> t1;
            
            if(op==':'){
                for(auto xx:b[num1]){
                    if(xx.y == num2){
                        t1.push_back(xx.x);
                    }
                }
            }
            else{
                for(auto xx:b[num1]){
                    if(xx.y!=num2){
                        t1.push_back(xx.x);
                    }
                }
            }

            st.push(t1);
        }
    }
    vector<ll> ans = st.top();
    for(int i=0;i<ans.size();i++){
        ans[i] = a[ans[i]];
    }
    sort(ans.begin(),ans.end());
    for(auto xx:ans){
        cout<<xx<<" ";
    }
    cout<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ll num;cin>>num;
        for(int j=1;j<=num;j++){
            ll t1,t2;cin>>t1>>t2;
            b[t1].push_back({i,t2});
        }    
    } 

    cin>>m;
    while(m--){
        solve();
    }

    

    return 0;
}
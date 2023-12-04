#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'


const ll mod = 1e9+7;

ll n,m;
string s;
ll num[200],now;//对now求偏导 now最后代入

struct node{
    ll a[200]={0};
    ll len;//最高次项的次数
};


ll quick_pow(ll x,ll y)
{
    ll re = 1;
    x%=mod;//注意这里 否则可能爆ll
    while (y > 0) {
    if (y & 1) re = re * x % mod;
    x = x * x % mod;
    y >>= 1;
    }
    return re%mod;
}


void solve()
{
    stack<node> st;
    
    ll len = s.size();
    for(int i=0;i<len;){
        if(s[i]=='x'){
            int j;
            int k = 0;
            for(j=i+1;j<len;j++){
                if(s[j]>='0' && s[j]<='9'){
                    k*=10;k+=s[j]-'0';
                }
                else{
                    break;
                }
            }

            node t;
            if(k==now){
                t.a[1]=1;
                t.len=1;
            }
            else{
                t.a[0]=num[k];
                t.len=0;
            }
            
            st.push(t);     
            i=j;
        }

        else if(s[i]>='0' && s[i]<='9'){
            int j;
            int k = 0;
            for(j=i;j<len;j++){
                if(s[j]>='0' && s[j]<='9'){
                    k*=10;k+=s[j]-'0';
                }
                else{
                    break;
                }
            }
            node t;
            t.a[0]=k;
            t.len = 0;
            st.push(t);
            i=j;
        }
        
        else if(s[i]=='-'){
            //case1
            if(i+1<len && s[i+1]>='0' && s[i+1]<='9'){
                int j;
                int k = 0;
                for(j=i+1;j<len;j++){
                    if(s[j]>='0' && s[j]<='9'){
                        k*=10;k+=s[j]-'0';
                    }
                    else{
                        break;
                    }
                }
                
                node t;
                t.a[0]=-k;
                t.len = 0;
                st.push(t);
                i=j;
            }

            //case2
            else{
                node t1,t2,t3;
                t2 = st.top();st.pop();
                t1 = st.top();st.pop();
                //t1 - t2
                t3.len = max(t1.len,t2.len);
                for(int j=0;j<=t3.len;j++){
                    t3.a[j] = (t1.a[j] - t2.a[j] + mod)%mod;
                }
                
                st.push(t3);
                i++;
            }
        }
        
        else if(s[i]=='*'){
             node t1,t2,t3;
            t2 = st.top();st.pop();
            t1 = st.top();st.pop();
            //t1 * t2
            t3.len = t1.len + t2.len;
            for(int j=0;j<=t1.len;j++){
                for(int k=0;k<=t2.len;k++){
                    t3.a[k+j] += t1.a[j]*t2.a[k]%mod;
                    t3.a[k+j]%=mod;
                }
            }
            
            st.push(t3);
            
            
            i++;
        }
        else if(s[i]=='+'){
            node t1,t2,t3;
            t2 = st.top();st.pop();
            t1 = st.top();st.pop();
            //t1 + t2
            t3.len = max(t1.len,t2.len);
            for(int j=0;j<=t3.len;j++){
                t3.a[j] = (t1.a[j] + t2.a[j] + mod)%mod;
            }
            
            st.push(t3);
            i++;
        }
        else{
           i++;
        }
    }

    node re = st.top();
    ll ans = 0;
    for(int i=1;i<=re.len;i++){
        ans = (ans + i*re.a[i]%mod*quick_pow(num[now],i-1)%mod)%mod;
    }

    ans+=mod;ans%=mod;
    cout<<ans<<endl;
    

}

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    cin>>n>>m;
    getchar();
    getline(cin,s);

    while(m--){
        cin>>now;
        for(int i=1;i<=n;i++){
            cin>>num[i];
        }
        solve();
    }

    return 0;
}


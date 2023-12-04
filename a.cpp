#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'


const ll mod = 1e9+7;

ll n,m;
string s;
ll num[105],now;

struct node{
    ll a[105];  
};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    getline(cin,s);

    stack<vector<node>> st;

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
            vector<node>t;
            node t1;
            t1.a[0]=1;//*1
            t1.a[k]=1;
            t.push_back(t1);
            
            
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
            vector<node>t;
            node t1;
            t1.a[0]=k;
            t.push_back(t1);
        
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
                vector<node>t;
                node t1;
                t1.a[0]=-k;
                t.push_back(t1);

                i=j; 
            }

            //case2
            else{
                vector<node> t1= st.top();st.pop();
                vector<node> t2 = st.top();st.pop();
                for(auto xx:t2){
                    xx[0]=-xx[0];
                    t1.push_back(xx);
                }
                st.push(t1);
                i++;
            }
        }
        
        else if(s[i]=='*'){
            vector<node> t1= st.top();st.pop();
            vector<node> t2 = st.top();st.pop();
            for(auto xx:t2){
                
            }
            st.push(t1);
            
            i++;
        }
        else if(s[i]=='+'){
            vector<node> t1= st.top();st.pop();
            vector<node> t2 = st.top();st.pop();
            for(auto xx:t2){
                t1.push_back(xx);
            }
            st.push(t1);
            i++;
        }
        else{
           
            i++;
        }
    }

    vector<node> re = st.top();
    

    while(m--){
        cin>>now;
        for(int i=1;i<=n;i++){
            cin>>num[i];
        }

        
    }
    

    

    

    return 0;
}


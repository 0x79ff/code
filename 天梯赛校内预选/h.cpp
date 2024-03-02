#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const ll N = 1e5+10;
const ll mod = 1e9+7;

map<string,int> a;
int n;

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        int op;cin>>op;
        if(op==1){
            string b;int c;
            cin>>b>>c;
            a[b]=c;
            cout<<"OK"<<endl;
        } 
        if(op==2){
            string b;cin>>b;
            if(a.count(b)){
                cout<<a[b]<<endl;
            }
            else{
                cout<<"Not found"<<endl;
            }
        }
        if(op==3){
            string b;cin>>b;
            if(a.count(b)){
                a.erase(b);
                cout<<"Deleted successfully"<<endl;
            }
            else{
                cout<<"Not found"<<endl;
            }
        }
        if(op==4){
            cout<<a.size()<<endl;
        }
    }
}

int main()
{
    IOS;
    int T=1;//cin>>T;
    while(T--){
        solve();
    }
    
    return 0;
}


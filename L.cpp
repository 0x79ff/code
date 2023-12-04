#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

const int N =1e6+10;
vector<int> a[N];   
int n,m,cnt;

const int p[]={1,0,2,3};//4k+3 4k用
const int q[]={1,0,2,0};//<4用
const int s[]={1,3,0,2};//4k+2 4k+1用

void output()
{
    cout<<cnt<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
}



void solve(){

    cin>>n>>m;
    
    for(int i=1;i<=n;i++){
        a[i].push_back(2);//占位
        for(int j=1;j<=m;j++){
            a[i].push_back(1);
        }
    }
    cnt = n*m;

    if(n<4 && m<4){
        ;
    }
    else if(n<4 || m<4){
        if(n<4){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(j%4==q[i%4]){
                        a[i][j]=0;
                        cnt--;
                    }
                }
            }
        }
        
        if(m<4){
            for(int j=1;j<=m;j++){
                for(int i=1;i<=n;i++){
                    if(i%4==q[j%4]){
                        a[i][j]=0;
                        cnt--;
                    }
                }
            }
        }
    }

    
    else{
        if(n%4==0){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(j%4==p[i%4]){
                        a[i][j]=0;
                        cnt--;
                    }
                }
            }
        }
        else if(m%4==0){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(i%4==p[j%4]){
                        a[i][j]=0;
                        cnt--;
                    }
                }
            }
        }
        
        else{
            if(m%4==3){
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=m;j++){
                        if(j%4==p[i%4]){
                            a[i][j]=0;
                            cnt--;
                        }   
                    }
                }
            }
            else{   
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=m;j++){
                        if(j%4==s[i%4]){
                            a[i][j]=0;
                            cnt--;
                        }   
                    }
                }
            }
        }
       
    }

    output();
    for(int i=1;i<=n;i++){
        a[i].clear();
    }
    

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt=1;
    cin>>tt;
    while(tt--){
        solve();
    }
    

    return 0;
}

/*


1
5 5


3
2 2
3 4
3 8

1
3 7

1
6 6

9
5 5
5 6
5 7
6 5
6 6
6 7
7 5
7 6
7 7



*/
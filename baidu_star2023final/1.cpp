#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 4e3+100;
ll n,m;
char a[N][N];
ll posx,posy;
ll l[N],r[N];
ll u[N],d[N];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;

    if(n==1 || m==1){
        cout<<"No\n";
        return 0;
    }
    
    for(int i=1;i<=n;i++){
        string t;cin>>t;
        for(int j=1;j<=m;j++){
            a[i][j] = t[j-1];
            if(a[i][j]!='.' && a[i][j]!='#'){
                posx = i;posy = j;
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=posy;j>=1;j--){
            if(a[i][j]!='#'){
                l[i]=j;
            }
            else{
                break;
            }
        }
        for(int j=posy;j<=m;j++){
            if(a[i][j]!='#'){
                r[i]=j;
            }
            else{
                break;
            }
        }
    }    

    for(int j=1;j<=m;j++){
        for(int i=posx;i>=1;i--){
            if(a[i][j]!='#'){
                u[j]=i;
            }
            else{
                break;
            }
        }
        for(int i=posx;i<=n;i++){
            if(a[i][j]!='#'){
                d[j]=i;
            }
            else{
                break;
            }
        }
    }

    // cout<<posx<<" "<<posy<<endl;
    // cout<<endl;

    // for(int i=1;i<=n;i++){
    //     cout<<l[i]<<" "<<r[i]<<endl;
    // }
    // cout<<endl;
    
    // for(int j=1;j<=m;j++){
    //     cout<<u[j]<<" "<<d[j]<<endl;
    // }
    // cout<<endl;

    //在上下边界上
    for(int i=1;i<posx;i++){
        if(l[i]==0 || r[i]==0) continue;
        int ll=max(l[i],l[posx]),rr = min(r[i],r[posx]);
        int fl=0,fr=0;
        for(int j=ll;j<=posy;j++){
            if(u[j]<=i && u[j]!=0){
                fl=j;
                break;
            }
        }
        for(int j=rr;j>=posy;j--){
            if(u[j]<=i && u[j]!=0){
                fr=j;
                break;
            }
        }
        if(fl!=0 &&fr!=0 && fl!=fr){
            cout<<"Yes\n";
            return 0;
        }
    }
    
    for(int i=posx+1;i<=n;i++){
        if(l[i]==0 || r[i]==0) continue;
        int ll=max(l[i],l[posx]),rr = min(r[i],r[posx]);
        int fl=0,fr=0;
        for(int j=ll;j<=posy;j++){
            if(d[j]>=i && d[j]!=0){
                fl=j;
                break;
            }
        }
        for(int j=rr;j>=posy;j--){
            if(d[j]>=i && d[j]!=0){
                fr=j;
                break;
            }
        }
        //cout<<fl<<" "<<fr<<endl;
        if(fl!=0 &&fr!=0 && fl!=fr){
            cout<<"Yes\n";
            return 0;
        }
    }

    //在左右边界上
    for(int j=1;j<posy;j++){
        if(u[j]==0 || d[j]==0) continue;
        int uu = max(u[j],u[posy]),dd = min(d[j],d[posy]);
        int fu = 0,fd=0;
        for(int i=uu;i<=posx;i++){
            if(l[i]<=j&&l[i]!=0){
                fu=i;
                break;
            }
        }
        for(int i=dd;i>=posx;i--){
            if(l[i]<=j&&l[i]!=0){
                fd=i;
                break;
            }
        }
        if(fu!=0 &&fd!=0 && fu!=fd){
            cout<<"Yes\n";
            return 0;
        }
    }

    for(int j=posy+1;j<=m;j++){
        if(u[j]==0 || d[j]==0) continue;
        int uu = max(u[j],u[posy]),dd = min(d[j],d[posy]);
        int fu = 0,fd=0;
        for(int i=uu;i<=posx;i++){
            if(r[i]>=j&&r[i]!=0){
                fu=i;
                break;
            }
        }
        for(int i=dd;i>=posx;i--){
            if(r[i]>=j&&r[i]!=0){
                fd=i;
                break;
            }
        }
        if(fu!=0 &&fd!=0 && fu!=fd){
            cout<<"Yes\n";
            return 0;
        }
    }


    cout<<"No\n";
    
    return 0;
}
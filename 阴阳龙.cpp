#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

ll n,m,p,q;

const int dx[] = {00,1,1,0,-1,-1,-1,0,1};
const int dy[] = {00,0,1,1,1,0,-1,-1,-1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>p>>q;
    vector<array<ll,2>> pos;
    unordered_map<ll,set<array<ll,2>>> row,col,ld,rd;

    auto insert = [&](int id){
        int x = pos[id][0],y = pos[id][1];
        row[x].insert({y,id});
        col[y].insert({x,id});
        ld[x+y].insert({x,id});
        rd[y-x].insert({x,id});
    };
    
    auto remove = [&](int id){
        int x = pos[id][0],y = pos[id][1];
        row[x].erase({y,id});
        col[y].erase({x,id});
        ld[x+y].erase({x,id});
        rd[y-x].erase({x,id});
    };
    
    for(int i=0;i<p;i++){
        ll x,y;
        cin>>x>>y;
        pos.push_back({x,y});
        insert(i);
    }

    

    while(q--){
        ll u,v,t;
        cin>>u>>v>>t;
        vector<array<ll,3>> tans;
        ll len = min(min(u-1,n-u),min(v-1,m-v));

        auto search = [&](const set<array<ll,2>> &s,ll d,int dirl,int dirr){
            auto pos = s.lower_bound(array<ll,2>{d,p});
            if(pos!=s.end()){
                tans.push_back({(*pos)[0]-d,dirr,(*pos)[1]});
                //cout<<(*pos)[1]<<endl;
            }
            

            if (pos != s.begin()){
                pos = prev(pos);
                if ((*pos)[0] == d && pos != s.begin())
                    pos = prev(pos);

                if ((*pos)[0] != d){
                    tans.push_back({d - (*pos)[0],dirl,(*pos)[1]});
                }
            }
            
        };

        search(row[u],v,7,3);
        search(rd[v-u],u,6,2);
        search(col[v],u,5,1);
        search(ld[u+v],u,4,8);

        auto cmp = [&](const array<ll,3>&t1,const array<ll,3>&t2){
            return t1[0]<t2[0];
        };
        

        //很重要 空的话会有非法访问！！！这里错了几次
        if(tans.empty()){
            continue;
        }
        
        sort(tans.begin(),tans.end(),cmp);
        if(tans[0][0]>len){
            continue;
        }
        len = tans[0][0];

        //旋转
        for(auto s:tans){
            //
            if(s[0]>len){
                break;
            }
            
            int id = s[2],dis = s[0],cur = s[1];
          // cout<<id+1<<" "<<dis<<" "<<cur<<endl;
            remove(id);
            //cout<<(cur+t+7)%8+1<<endl;
            pos[id][0] = u + dis*(dx[(cur+t+7)%8+1]);
            pos[id][1] = v + dis*(dy[(cur+t+7)%8+1]);
            insert(id);
        }
        //   cout<<endl;
        
    }



    ll ans = 0;
    for(int i=0;i<p;i++){
       // cout<<i+1<<" "<<pos[i][0]<<" "<<pos[i][1]<<endl; 
        ans^=((i+1)*pos[i][0]+pos[i][1]);
    }
    cout<<ans<<"\n";

    return 0;
}


//发展心理学
//平时作业举个例子
//平时作业自己整理成一个文档 发邮箱
//期末作业 17周 打印交
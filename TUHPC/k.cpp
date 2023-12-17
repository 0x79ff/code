#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int cnt = 0;
    vector<int>v;
    vector<int>p;
    for (int i = 1; i <= 5; i++)
    {
        string s;
        cin >> s;
        int tmp_cnt = 0;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == 'o'){
                tmp_cnt++;
                if(tmp_cnt == 1)p.push_back(j);
            }           
        }
        cnt+=tmp_cnt;
        if(tmp_cnt>0)v.push_back(tmp_cnt);
    }
    if(cnt==2){
        cout<<"Far\n";
    }
    else{
        if(cnt == 4){
            if(v.size() == 4 || v.size() == 1){
                cout<<"Away\n";
            }
            else if(v.size() == 2&&v[0] == 2){
                if(p[0] == p[1]){
                    //tian zi
                    cout<<"Away\n";
                }
                else{
                    cout<<"Far\n";
                }
            }
            else{
                cout<<"Far\n";
            }
        }
        else{
            cout<<"Away\n";
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<string , int> > v;
bool vis[1000005];
vector<string>ans[1000005];
int mx = 0 , cur = 0;

void dfs(int u , int d = 0)
{
    mx = max(mx , d);
    ans[d].push_back(v[u].first);
    vis[u] = true;
    for(int i=1;i<=v[u].second;i++){

        ++cur;
        dfs(cur , d+1);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    string ar;
    cin >> ar;
    ar+=",";

    for(int i=0;i<ar.size();i++){

        string s = "";
        int t = 0;

        while(ar[i]!=',')s+=ar[i] , i++;
        i++;
        while(ar[i]!=','){
            t*=10;
            t+=ar[i]-'0';
            i++;
        }
        v.push_back({s , t});
    }

    memset(vis , false , sizeof(vis));
    for(int i=0;i<v.size();i++){

        if(vis[i]==false){

            dfs(i);
            cur++;
        }
    }
    cout << mx+1 << endl;
    for(int i=0;i<1000005;i++){

        if(ans[i].size()>0){

            for(auto it : ans[i])cout << it << " ";
            cout << endl;
        }
    }

    return 0;
}

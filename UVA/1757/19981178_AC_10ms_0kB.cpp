// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>edges[26];
bool found = false;
bool vis[26];

void dfs(int now , int tar)
{
    if(now==tar)found = true;
    if(vis[now]==true)return ;
    vis[now] = true;
    for(auto v:edges[now])dfs(v , tar);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n , m;
    while(cin >> n >> m){
        for(int i=0;i<26;i++)edges[i].clear();
        for(int i=0;i<n;i++){
            char x , y;
            cin >> x >> y;
            edges[x-'a'].push_back(y-'a');
        }
        for(int i=0;i<m;i++){
            string ar , br;
            cin >> ar >> br;
            bool check = true;
            if(ar.size()!=br.size())check = false;
            if(check){
                for(int i=0;i<ar.size();i++){
                    found = false;
                    memset(vis , false , sizeof(vis));
                    dfs(ar[i]-'a' , br[i]-'a');
                    if(found==false)check = false;
                }
                if(check)cout << "yes" << endl;
                else cout << "no" << endl;
            }
            else{
                cout << "no" << endl;
            }
        }
    }
    return 0;
}

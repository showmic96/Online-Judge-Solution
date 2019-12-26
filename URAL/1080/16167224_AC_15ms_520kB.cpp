// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>edges[105];
bool check = true;
string ar;
bool vis[105];

void dfs(int u , int now)
{
    if(vis[u]==true)return ;
    vis[u] = true;

    ar[u] = '0'+now^1;

    for(int i=0;i<edges[u].size();i++){

        if(vis[edges[u][i]]==true){

            if(ar[edges[u][i]]==ar[u])check = false;
        }
        else dfs(edges[u][i] , now^1);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    memset(vis , false , sizeof(vis));
    int n;
    cin >> n;

    for(int i=0;i<n;i++){

        int in;
        while(cin >> in){

            if(in==0)break;
            edges[i].push_back(in-1);
            edges[in-1].push_back(i);
        }
    }

    for(int i=0;i<n;i++)ar+="0";
    check = true;
    dfs(0 , 1);

    if(check==false)cout << -1 << endl;
    else cout << ar << endl;

    return 0;
}

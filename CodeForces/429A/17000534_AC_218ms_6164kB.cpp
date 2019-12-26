// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>edges[100005] , ans;
int now[100005] , target[100005];

void dfs(int u , int par = -1 , int d = 0 , int c1 = 0 , int c2 = 0)
{
    if(d%2==0){

        if(c1==1)now[u]^=1;
    }
    else{

        if(c2==1)now[u]^=1;
    }

    if(now[u]!=target[u]){

        ans.push_back(u);
        if(d%2==0)c1^=1;
        else c2^=1;
    }

    for(auto v : edges[u]){

        if(v!=par)dfs(v , u , d+1 , c1 , c2);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;

    for(int i=0;i<n-1;i++){

        int in1 , in2;
        cin >> in1 >> in2;
        edges[in1].push_back(in2);
        edges[in2].push_back(in1);
    }

    for(int i=1;i<=n;i++)cin >> now[i];
    for(int i=1;i<=n;i++)cin >> target[i];

    dfs(1);

    cout << ans.size() << '\n';
    for(int i=0;i<ans.size();i++)cout << ans[i] << '\n';

    return 0;
}

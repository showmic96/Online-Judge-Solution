// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 300005;
const ll INF = 1e18;

ll tree[4*MAX] , n , m;

vector<int>edges[MAX+9];
vector<pair<int , int> > query[MAX+9];
ll ans[MAX+9];

void update(int node , int st , int en , int idx , int val)
{
    if(st==en){

        tree[node]+=(ll)val;
        return ;
    }

    int mid = (st+en)/2;
    if(idx<=mid)update(2*node , st , mid , idx , val);
    else update(2*node+1 , mid+1 , en , idx , val);

    tree[node] = tree[2*node] + tree[2*node+1];
}

ll q(int node , int st , int en , int l , int r)
{
    if(st>r||l>en)return 0;
    if(st>=l&&en<=r)return tree[node];

    int mid = (st+en)/2;
    return q(2*node , st , mid , l , r) + q(2*node+1 , mid+1 , en , l , r);
}

void dfs(int u , int par = -1 , int now = 1)
{

    for(auto it : query[u]){

        update(1 , 1 , n , min((int)n , now+it.first) , it.second);
    }

    ans[u] = q(1 , 1 , n , now , n);
    for(auto v : edges[u]){

        if(v!=par)dfs(v , u , now+1);
    }

    for(auto it : query[u]){

        update(1 , 1 , n , min((int)n , now+it.first) , -it.second);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;

    for(int i=0;i<n-1;i++){

        ll in1 , in2;
        cin >> in1 >> in2;

        edges[in1].emplace_back(in2);
        edges[in2].emplace_back(in1);
    }

    cin >> m;
    for(int i=0;i<m;i++){

        ll in1 , in2 , in3;
        cin >> in1 >> in2 >> in3;
        query[in1].push_back(make_pair(in2 ,in3));
    }

    dfs(1);

    for(int i=1;i<=n;i++)cout << ans[i] << " ";

    return 0;
}

// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 200005;
vector<ll>tree[4*MAX];
vector<pair<ll , ll> > edges[MAX];
ll value[MAX] , val[MAX] , st[MAX] , en[MAX] , dis[MAX];
ll counter = 0;

void dfs(int u , int par=-1)
{
    counter++;
    val[counter] = dis[u]-value[u];
    st[u] = counter;
    for(auto v:edges[u]){
        if(par!=v.first){
            dis[v.first] = dis[u]+v.second;
            dfs(v.first , u);
        }
    }
    en[u] = counter;
}
void build(int node , int st , int en)
{
    if(st==en){
        tree[node].push_back(val[st]);
        return ;
    }
    int mid=(st+en)/2;
    build(2*node , st , mid);
    build(2*node+1 , mid+1 , en);
    merge(tree[2*node].begin() , tree[2*node].end() , tree[2*node+1].begin() , tree[2*node+1].end() , back_inserter(tree[node]));
}
ll query(int node , int st , int en , int l , int r , ll v)
{
    if(st>r||en<l)return 0;
    if(st>=l&&en<=r){
        ll tot = lower_bound(tree[node].begin() , tree[node].end() , v+1) - tree[node].begin();
        return tot;
    }
    int mid = (st+en)/2;
    return query(2*node , st , mid , l , r , v)+query(2*node+1 , mid+1 , en , l , r , v);
}

int main(void)
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&value[i]);
    for(int i=2;i<=n;i++){
        int in1 , in2;
        scanf("%d %d",&in1 , &in2);
        edges[in1].push_back({i , in2});
        edges[i].push_back({in1 , in2});
    }
    dfs(1);
    build(1 , 1 , n);
    for(int i=1;i<=n;i++){
        int ans = query(1 , 1 , n , st[i] , en[i] , dis[i]);
        printf("%d ",ans-1);
    }
    return 0;
}

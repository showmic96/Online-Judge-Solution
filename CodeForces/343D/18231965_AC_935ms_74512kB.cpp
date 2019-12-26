// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 5e5+9;

ll tree[4*MAX] , lazy[4*MAX];
int st[MAX] , en[MAX] , t = 0 , parent[MAX];
vector<int>edges[MAX];

void dfs(int u , int par = 0)
{
    st[u] = ++t;
    parent[u] = par;
    for(auto v : edges[u]){

        if(v!=par)dfs(v , u);
    }
    en[u] = t;
}

void build(int node , int st , int en)
{
    if(st==en){
        tree[node] = 1;
        return ;
    }
    int mid = (st+en)/2;
    build(2*node , st , mid);
    build(2*node+1 , mid+1 , en);
    tree[node] = tree[2*node] + tree[2*node+1];
}

void update(int node , int st , int en , int l , int r , ll val)
{
    if(lazy[node]!=-1){

        tree[node] = (en-st+1)*lazy[node];
        if(st!=en){

            lazy[2*node] = lazy[node];
            lazy[2*node+1] = lazy[node];
        }
        lazy[node] = -1;
    }
    if(st>r||en<l)return ;
    if(st>=l&&en<=r){

        tree[node] = (en-st+1)*val;
        if(st!=en){
            lazy[2*node] = val;
            lazy[2*node+1] = val;
        }
        return ;
    }
    int mid = (st+en)/2;
    update(2*node , st , mid , l , r , val);
    update(2*node+1 , mid+1 , en , l , r , val);
    tree[node] = tree[2*node] + tree[2*node+1];
}

ll query(int node , int st , int en , int l , int r)
{
    if(st>r||en<l)return 0;
    if(lazy[node]!=-1){

        tree[node] = (en-st+1)*lazy[node];
        if(st!=en){

            lazy[2*node] = lazy[node];
            lazy[2*node+1] = lazy[node];
        }
        lazy[node] = -1;
    }
    if(st>=l&&en<=r)return tree[node];
    int mid = (st+en)/2;
    return query(2*node , st , mid , l , r) + query(2*node+1 , mid+1 , en , l , r);
}

int main(void)
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int in1 , in2;
        scanf("%d %d",&in1 , &in2);
        edges[in1].push_back(in2);
        edges[in2].push_back(in1);
    }
    build(1 , 1 , n);
    dfs(1);
    memset(lazy , -1 , sizeof(lazy));

    int q;
    scanf("%d",&q);
    while(q--){

        int in;
        scanf("%d",&in);
        if(in==1){

            scanf("%d",&in);
            ll now = query(1 , 1 , n , st[in] , en[in]);
            if(now>0)update(1 , 1 , n , st[parent[in]] , st[parent[in]] , 1);
            update(1 , 1 , n , st[in], en[in] , 0);
        }
        else if(in==2){

            scanf("%d",&in);
            update(1 , 1 , n , st[in] , st[in] , 1);
        }
        else{

            scanf("%d",&in);
            ll now = query(1 , 1 , n , st[in] , en[in]);
            if(now==0)printf("1\n");
            else printf("0\n");
        }
    }
    return 0;
}

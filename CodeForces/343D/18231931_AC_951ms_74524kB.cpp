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

void update(int node , int st , int en , int l , int r , ll val)
{
    if(lazy[node]!=0){

        tree[node] = 0;
        if(st!=en){

            lazy[2*node] = lazy[node];
            lazy[2*node+1] = lazy[node];
        }
        lazy[node] = 0;
    }
    if(st>r||en<l)return ;
    if(st>=l&&en<=r){

        tree[node] = 0;
        if(st!=en){
            lazy[2*node] = 1;
            lazy[2*node+1] = 1;
        }
        return ;
    }
    int mid = (st+en)/2;
    update(2*node , st , mid , l , r , val);
    update(2*node+1 , mid+1 , en , l , r , val);
    tree[node] = tree[2*node] + tree[2*node+1];
}
void up(int node , int st , int en , int idx)
{
    if(idx<st||idx>en)return ;
    if(lazy[node]!=0){

        tree[node] = 0;
        if(st!=en){

            lazy[2*node] = lazy[node];
            lazy[2*node+1] = lazy[node];
        }
        lazy[node] = 0;
    }
    if(st==idx&&en==idx){
        tree[node] = 1;
        return ;
    }
    int mid = (st+en)/2;
    up(2*node , st , mid , idx);
    up(2*node+1 , mid+1 , en , idx);
    tree[node] = tree[2*node] + tree[2*node+1];
}

ll query(int node , int st , int en , int l , int r)
{
    if(st>r||en<l||st>en)return 0;
    if(lazy[node]!=0){

        tree[node] = 0;
        if(st!=en){

            lazy[2*node] = lazy[node];
            lazy[2*node+1] = lazy[node];
        }
        lazy[node] = 0;
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
    for(int i=1;i<=n;i++)up(1 , 1 , n , i);
    dfs(1);

    int q;
    scanf("%d",&q);
    while(q--){

        int in;
        scanf("%d",&in);
        if(in==1){

            scanf("%d",&in);
            ll now = query(1 , 1 , n , st[in] , en[in]);
            update(1 , 1 , n , st[in], en[in] , 0);
            if(now>0)up(1 , 1 , n , st[parent[in]]);
        }
        else if(in==2){

            scanf("%d",&in);
            up(1 , 1 , n , st[in]);
        }
        else{

            scanf("%d",&in);
            ll now = query(1 , 1 , n , st[in] , en[in]);
            if(now>0)printf("0\n");
            else printf("1\n");
        }
    }
    return 0;
}

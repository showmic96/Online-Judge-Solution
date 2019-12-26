// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 2e5+9;
ll tree[4*MAX+9][2] , lazy[4*MAX+9][2];
vector<ll>v;
vector<int>edges[MAX+9];
int T = 0 , bt[MAX] , et[MAX] , lvl[MAX] , ar[MAX];

void dfs(int u , int par = -1 , int now = 0)
{
    bt[u] = ++T;
    ar[T] = v[u-1];
    lvl[u] = now;
    for(auto v : edges[u]){

        if(v!=par){
            dfs(v , u , 1^now);
        }
    }
    et[u] = T;
}


void update(int node , int st , int en , int l , int r , ll value , int q)
{
    if(lazy[node][q]!=0){

        tree[node][q] += (en - st + 1) * lazy[node][q];
        if(st!=en){

            lazy[2*node][q] += lazy[node][q];
            lazy[2*node+1][q] += lazy[node][q];
        }
        lazy[node][q] = 0;
    }
    if(st>r||en<l)return ;
    if(st>=l&&en<=r){

        tree[node][q] += (en-st+1)*value;
        if(st!=en){

            lazy[2*node][q] += value;
            lazy[2*node+1][q] += value;
        }
        return ;
    }

    int mid = (st+en)/2;
    update(2*node , st , mid , l , r , value , q);
    update(2*node+1 , mid+1 , en , l , r , value , q);

    tree[node][q] = tree[2*node][q] + tree[2*node+1][q];
}

ll query(int node , int st , int en , int l , int r , int q)
{
    if(st>r||en<l)return 0;
    if(lazy[node][q]!=0){

        tree[node][q] += (en - st + 1) * lazy[node][q];
        if(st!=en){

            lazy[2*node][q] += lazy[node][q];
            lazy[2*node+1][q] += lazy[node][q];
        }
        lazy[node][q] = 0;
    }
    if(st>=l&&en<=r)return tree[node][q];
    int mid = (st+en)/2;
    return query(2*node , st , mid , l , r , q)+query(2*node+1 , mid+1 , en , l , r , q);
}

int main(void)
{
    int n , m;
    scanf("%d %d",&n, &m);

    for(int i=0;i<n;i++){
        ll in;
        scanf("%lld",&in);
        v.push_back(in);
    }

    for(int i=0;i<n-1;i++){
        int in1 , in2;
        scanf("%d %d",&in1 , &in2);
        edges[in1].push_back(in2);
        edges[in2].push_back(in1);
    }
    dfs(1);
    for(int i=0;i<n;i++){

        update(1 , 1 , n , i+1 , i+1 , ar[i+1] , 0);
        update(1 , 1 , n , i+1 , i+1 , ar[i+1] , 1);
    }
    for(int i=0;i<m;i++){

        int type;
        scanf("%d",&type);
        if(type==1){
            ll in1 , in2;
            scanf("%lld %lld",&in1 , &in2);

            update(1 , 1 , n , bt[in1] , et[in1] , in2 , lvl[in1]);
            update(1 , 1 , n , bt[in1] , et[in1] , -in2 , 1^lvl[in1]);

        }
        else{

            ll in;
            scanf("%lld",&in);
            printf("%lld\n",query(1 , 1 , n , bt[in] , bt[in] , lvl[in]));
        }
    }

    return 0;
}

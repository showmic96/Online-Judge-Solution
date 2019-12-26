// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1429431 + 1009;

ll tree[4*MAX] , ans[MAX];

void build(int node , int st , int en )
{
    if(st==en){

        tree[node] = st%2;
        return ;
    }

    int mid = (st+en)/2;

    build(2*node , st , mid);
    build(2*node+1 , mid+1, en);

    tree[node] = tree[2*node] + tree[2*node+1];
}

void update(int node , int st , int en , int idx)
{
    if(st==en){

        tree[node] = 0;
        return ;
    }

    int mid = (st+en)/2;

    if(idx<=tree[2*node])update(2*node , st , mid , idx);
    else update(2*node+1 , mid+1 , en , idx - tree[2*node]);

    tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int node , int st , int en , int value)
{
    if(st==en){

        return en;
    }

    int mid = (st+en)/2;

    if(value<=tree[2*node])return query(2*node , st , mid , value);
    else return query(2*node+1 , mid+1 , en , value-tree[2*node]);
}

void pre()
{
    build(1 , 1 , MAX);

    ans[1] = 1;

    int lim = 1e5 + 1;

    for(int i=2;i<=MAX;i++){

        ll value = query(1 , 1 , MAX , i);
        ans[i] = value;

        for(int j=(MAX/value)*value;j>=value;j-=value){

            update(1 , 1 , MAX , j);
        }
    }
}

int main(void)
{
    pre();

    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        int n;
        scanf("%d",&n);
        printf("Case %d: %lld\n",++c , ans[n]);
    }

    return 0;

}

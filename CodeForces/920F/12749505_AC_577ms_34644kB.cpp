// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 3e5+9;

ll tree[4*MAX] , mx[4*MAX] , dv[1000005+9];
vector<ll>v;

void build(int node , int st , int en)
{
    if(st==en){

        tree[node] = v[st-1];
        mx[node] = v[st-1];
        return ;
    }

    int mid = (st+en)/2;

    build(2*node , st , mid);
    build(2*node+1 , mid+1 , en);

    tree[node] = tree[2*node]+tree[2*node+1];
    mx[node] = max(mx[2*node] ,mx[2*node+1]);
}

void update(int node , int st , int en , int l , int r)
{
    if(st==l&&en==r){

        if(mx[node]<3)return ;
    }

    if(st==en){

        tree[node] = dv[tree[node]];
        mx[node] = tree[node];
        return ;
    }

    int mid = (st+en)/2;

    if(r<=mid)update(2*node , st , mid , l , r);
    else if(l>mid)update(2*node+1 , mid+1 , en , l, r);
    else{

        update(2*node , st , mid , l , mid);
        update(2*node+1 , mid+1 , en , mid+1 , r);
    }

    tree[node] = tree[2*node]+tree[2*node+1];
    mx[node] = max(mx[2*node] ,mx[2*node+1]);
}

ll query(int node , int st , int en , int l , int r)
{
    if(st>r||en<l)return 0;
    if(st>=l&&en<=r)return tree[node];

    int mid = (st+en)/2;

    return query(2*node , st , mid , l , r)+query(2*node+1 , mid+1 , en , l , r);
}

int main(void)
{
    for(int i=1;i<1000005;i++){

        for(int j=i;j<1000005;j+=i){

            dv[j]++;
        }
    }

    int n , m;
    scanf("%d %d",&n , &m);

    for(int i=0;i<n;i++){

        ll in;
        scanf("%lld",&in);
        v.push_back(in);
    }

    build(1 , 1 , n);

    while(m--){

        int in1 , in2 , in3;
        scanf("%d %d %d",&in1 , &in2 , &in3);

        if(in1==1){

            update(1 , 1 , n , in2 , in3);
        }

        else{

            printf("%lld\n",query(1 , 1 , n , in2 , in3));
        }
    }

    return 0;
}

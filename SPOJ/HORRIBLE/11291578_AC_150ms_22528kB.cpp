// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5 + 9;

ll tree[4*MAX] , lazy[4*MAX];

void lazy_work(ll node , ll st , ll en)
{
    tree[node] +=(en-st+1)*lazy[node];

    if(st!=en){

        lazy[2*node]+=lazy[node];
        lazy[2*node+1]+=lazy[node];
    }

    lazy[node] = 0;
}

void up(ll node , ll st , ll en , ll value)
{
    tree[node] +=(en-st+1)*value;

    if(st!=en){

        lazy[2*node]+=value;
        lazy[2*node+1]+=value;
    }

}

void _merge(int node)
{
    tree[node]=tree[2*node]+tree[2*node+1];
}

void update(ll node , ll st , ll en , ll l , ll r , ll value)
{
    if(lazy[node]!=0)lazy_work(node , st , en);

    if(st>=l&&en<=r){

        up(node , st , en , value);
        return ;
    }

    if(r<st||l>en)return ;

    int mid = (st+en)/2;

    update(2*node , st , mid , l , r , value);
    update(2*node+1 , mid+1 , en , l , r , value);

    _merge(node);
}

ll query(ll node , ll st , ll en , ll l , ll r)
{
    if(lazy[node]!=0)lazy_work(node , st , en);

    if(st>=l&&en<=r)return tree[node];

    if(r<st||l>en)return 0;

    int mid = (st+en)/2;

    ll p1 = query(2*node , st , mid , l , r);
    ll p2 = query(2*node+1 , mid+1 , en , l , r);

    return p1+p2;
}

int main(void)
{
    int t;
    scanf("%d",&t);

    while(t--){

        memset(tree , 0 , sizeof(tree));
        memset(lazy , 0 , sizeof(lazy));

        int n , q;
        scanf("%d %d",&n , &q);

        while(q--){

            int w;
            scanf("%d",&w);

            if(w==0){

                int in1 , in2 , in3;
                scanf("%d %d %d",&in1 , &in2 , &in3);

                update(1 , 1 , n , in1 , in2 , in3);
            }
            else{

                int in1 , in2;
                scanf("%d %d",&in1 , &in2);

                printf("%lld\n",query(1 , 1 , n , in1 , in2));
            }
        }
    }

    return 0;
}

// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e4 + 9;

ll tree[5*MAX] , lazy[5*MAX];
vector<ll>v;

bool prime[1000005+1000];

void sieve()
{
    ll lim = 1000005+1000;

    for(ll i=0;i<lim;i++)prime[i] = true;

    prime[0] = false;
    prime[1] = false;

    for(ll i=2;i<lim;i++){

        for(ll j=2;i*j<lim;j++){

            if(prime[i]==true)prime[i*j] = false;
        }
    }
}

void lazy_work(ll node , ll st , ll en)
{
    tree[node] =(en-st+1)*lazy[node];

    if(st!=en){

        lazy[2*node]=lazy[node];
        lazy[2*node+1]=lazy[node];
    }

    lazy[node] = -1;
}

void up(ll node , ll st , ll en , ll value)
{
    tree[node] =(en-st+1)*value;

    if(st!=en){

        lazy[2*node]=value;
        lazy[2*node+1]=value;
    }

    lazy[node] = -1;
}

void _merge(int node)
{
    tree[node]=tree[2*node]+tree[2*node+1];
}

void build(int node , int st , int en)
{
    if(st==en){

        tree[node] = v[st-1];
        return ;
    }

    int mid = (st+en)/2;

    build(2*node , st , mid);
    build(2*node+1 , mid+1 , en);
    _merge(node);
}

void update(ll node , ll st , ll en , ll l , ll r , ll value)
{
    if(st>=l&&en<=r){

        up(node , st , en , value);
        return ;
    }

    if(lazy[node]!=-1)lazy_work(node , st , en);

    if(r<st||l>en)return ;

    int mid = (st+en)/2;

    update(2*node , st , mid , l , r , value);
    update(2*node+1 , mid+1 , en , l , r , value);

    _merge(node);
}

ll query(ll node , ll st , ll en , ll l , ll r)
{
    if(lazy[node]!=-1)lazy_work(node , st , en);

    if(st>=l&&en<=r)return tree[node];

    if(r<st||l>en)return 0;

    int mid = (st+en)/2;

    ll p1 = query(2*node , st , mid , l , r);
    ll p2 = query(2*node+1 , mid+1 , en , l , r);

    return p1+p2;
}

int main(void)
{
    sieve();
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        v.clear();
        memset(tree , 0 , sizeof(tree));
        memset(lazy , -1 , sizeof(lazy));

        int n , q;
        scanf("%d %d",&n , &q);

        for(int i=0;i<n;i++){

            ll in;
            scanf("%lld",&in);

            if(prime[in]==true){

                v.push_back(1);
            }
            else{

                v.push_back(0);
            }
        }

        build(1 , 1 , n);

        printf("Case %d:\n",++c);

        while(q--){

            int w;
            scanf("%d",&w);

            if(w==0){

                int in1 , in2 , in3;
                scanf("%d %d %d",&in1 , &in2 , &in3);

                update(1 , 1 , n , in1 , in2 , prime[in3]);
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

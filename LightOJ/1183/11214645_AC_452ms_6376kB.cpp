// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5 + 9;
ll tree[3*MAX+9] , lazy[3*MAX+9];

void update(int node , int st , int en , int l , int r , int value)
{

    if(st>=l&&en<=r){

        tree[node] = (en-st+1)*value;
        if(st!=en){

            lazy[2*node] = value;
            lazy[2*node+1] = value;
        }

        lazy[node] = -1;

        return ;
    }

    if(lazy[node]!=-1){

        tree[node] = (en-st+1)*lazy[node];

        if(st!=en){

            lazy[2*node] = lazy[node];
            lazy[2*node+1] = lazy[node];
        }

        lazy[node] = -1;
    }

    if(r<st||l>en)return ;

    int mid = (st+en)/2;

    update(2*node , st , mid , l , r , value);
    update(2*node+1 , mid+1 , en , l , r , value);

    tree[node]=tree[2*node]+tree[2*node+1];
}

ll query(int node , int st , int en , int l , int r)
{

    if(lazy[node]!=-1){

        tree[node] = (en-st+1)*lazy[node];

        if(st!=en){

            lazy[2*node] = lazy[node];
            lazy[2*node+1] = lazy[node];
        }

        lazy[node] = -1;
    }

    if(r<st||l>en)return 0;

    if(st>=l&&en<=r){

        return tree[node];
    }

    int mid = (st+en)/2;

    ll p1 = query(2*node , st , mid , l , r);
    ll p2 = query(2*node+1 , mid+1 , en , l , r);

    return p1+p2;
}

int main(void)
{
    int t , c = 0;

    scanf("%d",&t);
    while(t--){

        int n , q;
        scanf("%d %d",&n , &q);

        memset(tree , 0 , sizeof(tree));
        memset(lazy , -1 , sizeof(lazy));

        printf("Case %d:\n",++c);

        while(q--){

            int w;
            scanf("%d",&w);

            if(w==1){

                int in1 , in2 , value;
                scanf("%d %d %d",&in1 , &in2 , &value);
                update(1 , 1 , n , in1+1 , in2+1 , value);
            }
            else{

                int in1 , in2;
                scanf("%d %d",&in1, &in2);

                ll ans = query(1 , 1 , n, in1+1 , in2+1);

                ll dem = (in2-in1+1);

                ll gcd = __gcd(ans , dem);

                ans/=gcd;
                dem/=gcd;

                if(dem==1)printf("%lld\n",ans);
                else printf("%lld/%lld\n",ans , dem);
            }
        }
    }
    return 0;
}

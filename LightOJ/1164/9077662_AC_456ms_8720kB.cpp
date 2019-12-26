// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5;

ll ar[MAX+9] , tree[4*MAX+9] , lazy[4*MAX+9];

void build(int node , int b , int e)
{
    if(b==e){

        tree[node] = ar[b];
    }

    else{

        int mid = (b+e)/2;
        int left = 2*node;
        int right = 2*node+1;

        build(left , b , mid);
        build(right , mid+1, e);

        tree[node] = tree[left] + tree[right];
    }
}

void update(ll node , ll b , ll e , ll i , ll j , ll value)
{

    if(lazy[node]!=0){

        tree[node]+= (e-b+1)*lazy[node];

        if(b!=e){

            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }

        lazy[node] = 0;
    }

    if(b>j||e<i||b>e)return ;

    if(b>=i&&e<=j){

        tree[node]+=(e-b+1)*value;

        if(b!=e){

            lazy[2*node]+=value;
            lazy[2*node+1]+=value;
        }

        return ;
    }

    ll mid = (b+e)/2;
    ll left = 2*node;
    ll right = 2*node+1;

    update(left , b , mid , i , j , value);
    update(right , mid+1 , e , i , j , value);

    tree[node]=tree[left]+tree[right];
}

ll query(ll node , ll b , ll e , ll i , ll j)
{
    if(b>j||e<i||b>e)return 0;

    if(lazy[node]!=0){

        tree[node]+=(e-b+1)*lazy[node];

        if(b!=e){

            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }

        lazy[node] = 0;
    }

    if(b>=i&&e<=j){

        return tree[node];
    }

    ll mid = (b+e)/2;
    ll left = 2*node;
    ll right = 2*node+1;

    ll p1 = query(left , b , mid , i , j );
    ll p2 = query(right , mid+1 , e , i , j);

    return (p1+p2);
}

int main(void)
{
    //freopen("input.txt","r",stdin);
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        int n , q;
        scanf("%d %d",&n, &q);

        memset(tree , 0 , sizeof(tree));
        memset(lazy , 0 , sizeof(lazy));

        printf("Case %d:\n", ++c);

        while(q--){

            int indi;
            scanf("%d",&indi);

            if(indi==0){

                int i , j , v;
                scanf("%d %d %d",&i , &j , &v);

                update(1 , 0 , n-1 , i , j , v);
            }

            else{

                int i , j;
                scanf("%d %d",&i , &j);

                printf("%lld\n",query(1 , 0 , n-1 , i , j));
            }
        }
    }

    return 0;
}

// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5+9;

ll tree[4*MAX] , ar[4*MAX] , lazy[4*MAX];

void build(int node, int st , int en)
{
    if(st>en)return ;
    if(st==en){

        tree[node] = ar[st]*ar[st];
    }
    else{

        int mid = (st+en)/2;

        build(2*node , st , mid);
        build(2*node+1 , mid+1 ,en);

        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

void update1(int node , int st , int en , int idx , int v)
{
    if(st==en){

        ar[idx]+=v;
        tree[node] = ar[idx]*ar[idx];
        //cout << tree[node] << " " << ar[idx] << endl;
        //return ;
    }

    else{

        int mid = (st+en)/2;

        if(idx>=st&&idx<=mid){

            update1(2*node , st , mid , idx , v);
        }

        else{

            update1(2*node+1 , mid+1 , en , idx , v);
        }

        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

void update2(int node , int st , int en , int idx , int v)
{
    if(st==en){

        ar[idx] = v;
        tree[node] = ar[idx]*ar[idx];
        return ;
    }

    else{

        int mid = (st+en)/2;

        if(idx>=st&&idx<=mid){

            update2(2*node , st , mid , idx , v);
        }

        else{

            update2(2*node+1 , mid+1 , en , idx , v);
        }

        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

ll query(int node , int st , int en , int l , int r)
{
    if(l>en||st>r)return 0;

    if(st>=l&&r>=en){

        return tree[node];
    }

    int mid = (st+en)/2;

    ll p1 = query(2*node , st , mid , l , r);
    ll p2 = query(2*node+1 , mid+1, en , l , r);

    return p1+p2;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        int n , q;
        scanf("%d %d",&n, &q);

        for(int i=1;i<=n;i++){

            scanf("%lld",&ar[i]);
        }

        build(1 , 1 , n);
        printf("Case %d:\n", ++c);

        while(q--){

            int qt;
            scanf("%d",&qt);

            if(qt==2){

                int l , r;

                scanf("%d %d",&l , &r);

                ll ans = query(1 , 1 , n , l , r);

                printf("%lld\n",ans);
            }

            if(qt==1){

                int l , r , v;
                scanf("%d %d %d",&l , &r , &v);

                for(int i=l;i<=r;i++)
                    update1(1 , 1 , n , i , v);
            }

            if(qt==0){

                int l , r , v;
                scanf("%d %d %d",&l , &r , &v);

                for(int i=l;i<=r;i++)
                    update2(1 , 1 , n , i , v);
            }
        }
    }

    return 0;
}

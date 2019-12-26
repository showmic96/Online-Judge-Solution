// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5+9;

ll tree1[5*MAX] , tree2[5*MAX] , ar[MAX];

void build1(int node , int st , int en)
{
    if(st>=en){

        if(st==en)tree1[node] = ar[st];
    }

    else{

        int mid = (st+en)/2;

        build1(2*node , st , mid);
        build1(2*node+1 , mid+1 , en);

        tree1[node] = min(tree1[2*node], tree1[2*node+1]);
    }
}

void build2(int node , int st , int en)
{
    if(st>=en){

        if(st==en)tree2[node] = ar[st];
    }

    else{

        int mid = (st+en)/2;

        build2(2*node , st , mid);
        build2(2*node+1 , mid+1 , en);

        tree2[node] = max(tree2[2*node], tree2[2*node+1]);
    }
}

ll query_max(int node , int st , int en , int l , int r)
{
    if(st>=l&&en<=r){

        return tree2[node];
    }

    if(r<st||l>en){

        return -1e19;
    }

    int mid = (st+en)/2;

    ll p1 = query_max(2*node , st , mid , l ,r);
    ll p2 = query_max(2*node+1 , mid+1 , en , l , r);

    return max(p1 , p2);
}

ll query_min(int node , int st , int en , int l , int r)
{
    if(st>=l&&en<=r){

        return tree1[node];
    }

    if(r<st||l>en){

        return 1e19;
    }

    int mid = (st+en)/2;

    ll p1 = query_min(2*node , st , mid , l ,r);
    ll p2 = query_min(2*node+1 , mid+1 , en , l , r);

    return min(p1 , p2);
}

int main(void)
{
    int t, c = 0;
    scanf("%d",&t);

    while(t--){

        int n , k;
        scanf("%d %d",&n , &k);

        for(int i=1;i<=n;i++){

            scanf("%lld",&ar[i]);
        }

        build1(1 , 1 , n);

        build2(1 , 1 , n);

        ll ans = 0;

        for(int i=1;i<=n;i++){

            if(i+k-1>n)break;

            ll t1 = query_max(1 , 1 , n , i , i+k-1);
            ll t2 = query_min(1 , 1 , n , i , i+k-1);

            ans = max(ans , abs(t2-t1));
        }

        printf("Case %d: %lld\n", ++c , ans);
    }

    return 0;
}

// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 30000 + 9;

ll ar[MAX] , tree[3*MAX];
int n;

void build(int node , int st , int en)
{
    if(st==en){

        tree[node] = st;
    }

    else{

        int mid = (st+en)/2;

        build(2*node , st , mid);
        build(2*node+1 , mid+1 , en);

        if(ar[tree[2*node]]<ar[tree[2*node+1]]){

            tree[node] = tree[2*node];
        }
        else{
            tree[node] = tree[2*node+1];
        }
    }
}

int query(int node , int st , int en , int l , int r)
{

    if(st>=l&&en<=r){

        return tree[node];
    }

    if(st>r||en<l){

        return -1;
    }

    int mid = (st+en)/2;

    int p1 = query(2*node , st ,mid , l , r);
    int p2 = query(2*node+1 , mid+1 , en , l , r);

    if(p1==-1)return p2;
    if(p2==-1)return p1;

    if(ar[p1]<ar[p2]){

        return p1;
    }
    else{

        return p2;
    }
}

ll f(int st , int en)
{
    if(st<=en){

        int mi = query(1 , 1 , n , st , en);

        ll area1 = (en-st+1)*ar[mi];

        ll area2 = max(f(st , mi-1), f(mi+1 , en));

        return max(area1 , area2);
    }

    return 0;
}

int main(void)
{

    int t , c = 0 ;
    scanf("%d",&t);

    while(t--){

        scanf("%d",&n);

        for(int i=1;i<=n;i++){

            scanf("%lld",&ar[i]);
        }

        build(1 , 1 , n);

        printf("Case %d: %lld\n",++c , f(1 , n));
    }

    return 0;
}

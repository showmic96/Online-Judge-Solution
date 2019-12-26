// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll>v;
ll tree[20000*4];

void build(int node , int st , int en)
{
    if(st==en){

        tree[node] = v[st];
        return ;
    }

    int mid = (st+en)/2;

    build(2*node , st , mid);
    build(2*node+1 , mid+1 , en);

    tree[node] = tree[2*node]&tree[2*node+1];
}

ll query(int node , int st , int en , int l , int r)
{
    if(st>r||en<l)return -1;
    if(st>=l&&en<=r)return tree[node];

    int mid = (st+en)/2;

    return query(2*node , st , mid , l , r)&query(2*node+1 , mid+1 , en , l , r);
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        int n , k;
        scanf("%d %d",&n , &k);
        v.clear();

        for(int i=0;i<n;i++){

            ll in;
            scanf("%lld",&in);
            v.push_back(in);
        }

        build(1 , 0 , n-1);

        k = min(n , k);

        for(int i=0;i<n;i++){

            int st = (i-k+n)%n;
            int en = (i+k)%n;

            ll ans = -1;

            if(st<i)ans&=query(1 , 0 , n-1 , st , i);
            else ans&=query(1 , 0 , n-1 , 0 , i)&query(1 , 0 , n-1 , st , n-1);

            if(en>i)ans&=query(1 , 0 , n-1 , i , en);
            else ans&=query(1 , 0 , n-1 , i , n-1)&query(1 , 0 , n-1 , 0 , en);

            if(i>0)printf(" ");
            printf("%lld",ans);
        }

        printf("\n");
    }
    return 0;
}

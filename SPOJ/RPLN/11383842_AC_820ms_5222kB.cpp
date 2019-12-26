// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5+9;

ll tree[3*MAX];

vector<int>v;

void build(int node ,int st , int en)
{
    if(st==en){

        tree[node] = v[st-1];
        return ;
    }

    int mid = (st+en)/2;

    build(2*node , st , mid );
    build(2*node+1 , mid+1 , en);

    tree[node] = min(tree[2*node] , tree[2*node+1]);
}

int query(int node , int st ,int en , int l , int r)
{
    if(st>=l&&en<=r){

        return tree[node];
    }

    if(l>en||r<st)return 1e9;

    int mid = (st+en)/2;

    int p1 = query(2*node , st , mid , l , r);
    int p2 = query(2*node+1 , mid+1 , en , l ,r);

    return min(p1 , p2);
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n , q;
        scanf("%d %d",&n ,&q);

        v.clear();

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            v.push_back(in);
        }

        build(1 , 1 , n);

        printf("Scenario #%d:\n",++c);

        while(q--){

            int in1 , in2;
            scanf("%d %d",&in1, &in2);

            printf("%d\n",query(1 , 1 , n , in1 , in2));
        }
    }

    return 0;
}

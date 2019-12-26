// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 50000 + 9;

vector<int>v;

ll tree[4*MAX];

void build(int node , int st , int en)
{
    if(st==en){

        tree[node] = v[st-1];
        return ;
    }

    int mid = (st+en)/2;

    build(2*node , st , mid);
    build(2*node+1 , mid+1 , en);

    tree[node] = max(tree[2*node] , tree[2*node+1]);
}

ll query(int node , int st , int en , int l , int r)
{
    if(st>=l&&en<=r){

        return tree[node];
    }

    if(r<st||l>en)return 0;

    int mid = (st+en)/2;

    ll p1 = query(2*node , st , mid , l , r);
    ll p2 = query(2*node+1 , mid+1 , en , l , r);

    return max(p1 , p2);
}

int main(void)
{
    int n , m;
    scanf("%d %d",&n ,&m);

    for(int i=0;i<n;i++){

        int in;
        scanf("%d",&in);
        v.push_back(in);
    }

    build(1 , 1 , n);

    int counter = 0;

    while(m--){

        int in1 , in2;
        scanf("%d %d",&in1, &in2);

        ll value = query(1 , 1 , n , in1 , in2-1);

        if(value<=v[in1-1])counter++;
    }

    printf("%d\n",counter);

    return 0;
}

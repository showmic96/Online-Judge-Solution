#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX = 10000000+9;
ll tree[4*MAX];

void update(int node ,int st , int en , int idx)
{
    if(st==en){

        tree[node] = 1;
        return ;
    }
    int mid = (st+en)/2;

    if(idx>=st&&idx<=mid)update(2*node , st , mid , idx);
    else update(2*node+1 , mid+1 , en , idx);

    tree[node] = tree[2*node]+tree[2*node+1];
}

ll query(int node ,int st , int en , int l , int r)
{
    if(l>en||r<st)return 0;
    if(st>=l&&en<=r)return tree[node];

    int mid = (st+en)/2;

    return query(2*node , st ,mid , l , r)+query(2*node+1 , mid+1 , en , l , r);
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        memset(tree , 0 , sizeof(tree));

        int n;
        scanf("%d",&n);
        unsigned long long counter = 0;

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            counter+=query(1 , 1 , MAX , in+1 , MAX);
            update(1 , 1 , MAX , in);
        }

        printf("%llu\n",counter);
    }
    return 0;
}
// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 131072+1009;

ll tree[3*MAX] , pre[3*MAX];
vector<int>v;

void build(int node , int st , int en)
{
    if(st==en){

        tree[node] = v[st-1];
        pre[node] = 0;

        return ;
    }

    int mid = (st+en)/2;

    build(2*node , st , mid);
    build(2*node+1 , mid+1 , en);

    if(pre[2*node]==0)tree[node] = tree[2*node]|tree[2*node+1] , pre[node] = 1;
    else tree[node] = tree[2*node]^tree[2*node+1] , pre[node] = 0;
}

void update(int node , int st , int en , int idx , int value)
{
    if(st==en){

        tree[node] = value;

        return ;
    }

    int mid = (st+en)/2;

    if(idx>=st&&idx<=mid)update(2*node , st , mid , idx , value);
    else update(2*node+1 , mid+1 , en , idx , value);

    if(pre[2*node]==0)tree[node] = tree[2*node]|tree[2*node+1] , pre[node] = 1;
    else tree[node] = tree[2*node]^tree[2*node+1] , pre[node] = 0;
}

int main(void)
{
    memset(tree , 0 ,sizeof(tree));
    memset(pre , 0 ,sizeof(pre));
    int n , m;
    scanf("%d %d",&n , &m);

    n = pow(2 , n);

    for(int i=0;i<n;i++){

        int in;
        scanf("%d",&in);
        v.push_back(in);
    }

    build(1 , 1 , n);

    while(m--){

        int in1 , in2;
        scanf("%d %d",&in1 , &in2);

        update(1 ,1 , n , in1 , in2);

        printf("%lld\n",tree[1]);

    }

    return 0;
}

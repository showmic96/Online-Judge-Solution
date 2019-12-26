// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 50000+9;

struct node{

    ll sum , pre , post , mx;
};

ll tree[3*MAX] , pre[3*MAX] , post[3*MAX] , mxsum[3*MAX];
vector<int>v;

void _assign(int node , int value)
{
    tree[node] = pre[node] = post[node] = mxsum[node] = value;
}

void _merge(int node)
{
    tree[node] = tree[2*node] + tree[2*node+1];
    pre[node] = max(pre[2*node] , tree[2*node]+pre[2*node+1]);
    post[node] = max(post[2*node+1] , tree[2*node+1]+post[2*node]);
    mxsum[node] = max(mxsum[2*node] ,max(mxsum[2*node+1] , pre[2*node+1]+post[2*node]));
}

void build(int node , int st , int en)
{
    if(st==en){

        _assign(node , v[st-1]);
        return ;
    }

    int mid = (st+en)/2;

    build(2*node , st , mid);
    build(2*node+1 , mid+1 , en);

    _merge(node);
}

void update(int node ,int st , int en , int idx , int value)
{
    if(st==en){

        _assign(node, value);
        return ;
    }

    int mid = (st+en)/2;

    if(idx>=st&&idx<=mid)update(2*node , st , mid , idx , value);
    else update(2*node+1 , mid+1 , en , idx , value);
    _merge(node);
}

node query(int node , int st , int en , int l , int r)
{
    if(st>=l&&en<=r){

        struct node f;
        f.mx = mxsum[node];
        f.post = post[node];
        f.pre = pre[node];
        f.sum = tree[node];
        return f;
    }

    if(r<st||l>en){

        struct node f;
        f.mx = -1e9;
        f.post = -1e9;
        f.pre = -1e9;
        f.sum = -1e9;

        return f;
    }

    int mid = (st+en)/2;

    struct node f1 , f2;
    f1 = query(2*node , st , mid , l , r);
    f2 = query(2*node+1 , mid+1 , en , l , r);

    struct node f;

    f.sum = f1.sum+f2.sum;
    f.pre = max(f1.pre , f1.sum+f2.pre);
    f.post = max(f2.post , f2.sum+f1.post);
    f.mx = max(f1.mx , max(f2.mx,f2.pre+f1.post ));

    return f;
}

int main(void)
{
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){

        int in;
        scanf("%d",&in);
        v.push_back(in);
    }

    build(1 , 1 , n);

    int q;
    scanf("%d",&q);

    while(q--){

        int w;
        scanf("%d",&w);

        if(w==0){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);
            update(1 , 1 , n , in1 , in2);
        }
        else{

            int in1 , in2;
            scanf("%d %d",&in1, &in2);

            struct node temp = query(1 , 1 , n , in1 , in2);

            printf("%lld\n",temp.mx);
        }
    }

    return 0;
}

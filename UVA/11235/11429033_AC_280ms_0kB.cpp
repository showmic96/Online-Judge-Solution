// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5 + 9;

ll tree[4*MAX] , lvalue[4*MAX] , rvalue[4*MAX] , lfre[4*MAX] , rfre[4*MAX] , ans[4*MAX];
vector<int>v;

struct data{

    ll tree , lvalue , rvalue , lfre , rfre , ans;
};

void _merge(int node)
{
    lvalue[node] = lvalue[2*node];
    rvalue[node] = rvalue[2*node+1];

    if(lvalue[2*node]==lvalue[2*node+1])lfre[node] = lfre[2*node]+lfre[2*node+1];
    else lfre[node] = lfre[2*node];

    if(rvalue[2*node]==rvalue[2*node+1])rfre[node] = rfre[2*node]+rfre[2*node+1];
    else rfre[node] = rfre[2*node+1];

    tree[node] = max(tree[2*node] , tree[2*node+1]);

    if(tree[node]==tree[2*node])ans[node] = ans[2*node];
    else ans[node] = ans[2*node+1];

    if(lvalue[2*node+1]==rvalue[2*node]){

        if(lfre[2*node+1]+rfre[2*node]>tree[node])ans[node] = lvalue[2*node+1];

        tree[node] = max(tree[node] , lfre[2*node+1]+rfre[2*node]);
    }
}

void build(int node , int st , int en)
{
    if(st==en){

        tree[node] = lfre[node] = rfre[node] = 1;
        lvalue[node] = rvalue[node] = ans[node] = v[st-1];

        return ;
    }

    int mid = (st+en)/2;
    build(2*node , st , mid);
    build(2*node+1 , mid+1 , en);

    _merge(node);
}

data query(int node ,int st , int en , int l , int r)
{
    if(st>=l&&en<=r){

        data t;
        t.tree = tree[node];
        t.ans = ans[node];
        t.lfre = lfre[node];
        t.rfre = rfre[node];
        t.lvalue = lvalue[node];
        t.rvalue = rvalue[node];

        return t;
    }

    if(l>en||r<st){

        data t;
        t.tree = 0;
        t.ans = 0;
        t.lfre = 0;
        t.rfre = 0;
        t.lvalue = 0;
        t.rvalue = 0;

        return t;
    }

    int mid = (st+en)/2;

    data p1 = query(2*node , st , mid , l , r);
    data p2 = query(2*node+1 , mid+1 , en , l , r);

    data p;

    p.lvalue = p1.lvalue;
    p.rvalue = p2.rvalue;

    if(p1.lvalue==p2.lvalue)p.lfre = p1.lfre+p2.lfre;
    else p.lfre = p1.lfre;

    if(p1.rvalue==p2.rvalue)p.rfre = p1.rfre+p2.rfre;
    else p.rfre = p2.rfre;

    p.tree = max(p1.tree , p2.tree);

    if(p.tree==p1.tree)p.ans = p1.ans;
    else p.ans = p2.ans;

    if(p2.lvalue==p1.rvalue){

        if(p2.lfre+p1.rfre>p.tree)p.ans = p2.lvalue;

        p.tree = max(p.tree, p2.lfre+p1.rfre);
    }

    return p;
}

int main(void)
{
    int n;
    while(scanf("%d",&n)==1){

        if(n==0)break;

        int q;
        scanf("%d",&q);

        v.clear();

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            v.push_back(in);
        }

        build(1 , 1 , n);

        while(q--){

            int in1 , in2 ;
            scanf("%d %d",&in1 , &in2);

            data temp = query(1 , 1 , n , in1 , in2);

            printf("%lld\n",temp.tree);
        }
    }
    return 0;
}

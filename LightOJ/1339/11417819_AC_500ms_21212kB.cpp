// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 100000+9;

vector<int>v;

ll tree[4*MAX] , lvalue[4*MAX] , rvalue[4*MAX] , lfre[4*MAX], rfre[4*MAX] , ans[4*MAX];

struct data{

    ll value , lvalue , rvalue , lfre , rfre , ans;
};

void build(int node , int st ,int en)
{
    if(st==en){

        ans[node] = lvalue[node] = rvalue[node] = v[st-1];
        tree[node] = lfre[node] = rfre[node] = 1;

        return ;
    }

    int mid = (st+en)/2;

    build(2*node , st , mid);
    build(2*node+1 , mid+1 , en);

    lvalue[node] = lvalue[2*node];
    rvalue[node] = rvalue[2*node+1];

    if(lvalue[2*node]==lvalue[2*node+1]){

        lfre[node] = lfre[2*node]+lfre[2*node+1];
    }
    else lfre[node] = lfre[2*node];

    if(rvalue[2*node]==rvalue[2*node+1]){

        rfre[node] = rfre[2*node]+rfre[2*node+1];
    }
    else rfre[node] = rfre[2*node+1];

    tree[node] = max(tree[2*node] , tree[2*node+1]);

    if(lvalue[2*node+1]==rvalue[2*node]){

        tree[node] = max(tree[node] , rfre[2*node]+lfre[2*node+1]);
        //ans[node] = lvlaue[node];
    }
}

data query(int node ,int st ,int en , int l , int r)
{
    if(st>=l&&en<=r){

        data f;
        f.value = tree[node];
        f.lfre = lfre[node];
        f.rfre = rfre[node];
        f.lvalue = lvalue[node];
        f.rvalue = rvalue[node];
        return f;
    }

    if(r<st||l>en){

        data f;
        f.value = 0;
        f.lfre = 0;
        f.lvalue = 0;
        f.rfre = 0;
        f.rvalue = 0;

        return f;
    }

    int mid = (st+en)/2;

    data p1 = query(2*node , st , mid , l , r);
    data p2 = query(2*node+1 , mid+1 , en , l , r);

    data p;

    p.lvalue = p1.lvalue;
    p.rvalue = p2.rvalue;

    if(p1.lvalue==p2.lvalue){

        p.lfre = p1.lfre+p2.lfre;
    }
    else p.lfre = p1.lfre;

    if(p1.rvalue==p2.rvalue){

        p.rfre = p1.rfre+p2.rfre;
    }
    else p.rfre = p2.rfre;

    p.value = max(p1.value , p2.value);

    if(p2.lvalue==p1.rvalue){

        p.value = max(p.value , p1.rfre+p2.lfre);
        //ans[node] = lvlaue[node];
    }

    return p;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n , k , q;
        scanf("%d %d %d",&n, &k, &q);

        v.clear();

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            v.push_back(in);
        }

        build(1 , 1 , n);
        printf("Case %d:\n", ++c);
        while(q--){

            int in1 ,in2;
            scanf("%d %d",&in1 , &in2);

            data ans = query(1 , 1 , n , in1 , in2);
            printf("%lld\n",ans.value);
        }
    }
    return 0;
}

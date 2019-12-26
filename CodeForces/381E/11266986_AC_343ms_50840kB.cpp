// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6+9;

int tree[3*MAX] , op[3*MAX] , ans[3*MAX] , cl[3*MAX];
string ar;

struct fin{

    int o , c , a;
};

void _merge(int node)
{
    tree[node] = tree[2*node]+tree[2*node+1];
    ans[node] = ans[2*node] + ans[2*node+1] + min(op[2*node] , cl[2*node+1]);

    op[node] = op[2*node] + op[2*node+1] - min(op[2*node] , cl[2*node+1]);
    cl[node] = cl[2*node] + cl[2*node+1] - min(op[2*node] , cl[2*node+1]);
}

void build(int node , int st , int en)
{

    if(st==en){

        if(ar[st-1]=='(')tree[node] = 1 , op[node] = 1;
        else tree[node] = -1 , cl[node] = 1;

        return ;
    }

    int mid = (st+en)/2;

    build(2*node , st , mid);
    build(2*node+1 , mid+1 , en);

    _merge(node);
}

fin query(int node ,int st ,int en , int l , int r)
{
    if(st>=l&&en<=r){

        fin temp;
        temp.a = ans[node];
        temp.c = cl[node];
        temp.o = op[node];

        return temp;
    }

    if(l>en||r<st) {

        fin temp;
        temp.a = 0;
        temp.o = 0;
        temp.c = 0;

        return temp;
    }

    int mid = (st+en)/2;

    fin f1 = query(2*node , st , mid , l , r);
    fin f2 = query(2*node+1 , mid+1 , en , l , r);

    fin f;

    f.a = (f1.a+f2.a) + min(f1.o , f2.c);
    f.o = (f1.o+f2.o) - min(f1.o , f2.c);
    f.c = (f1.c+f2.c) - min(f1.o , f2.c);

    return f;
}

int main(void)
{

    memset(tree , 0 ,sizeof(tree));
    memset(ans , 0 , sizeof(ans));
    memset(op , 0 , sizeof(op));
    memset(cl , 0 , sizeof(cl));

    cin >> ar;

    int n = ar.size();

    build(1 , 1 , n);

    int m;
    scanf("%d",&m);

    while(m--){

        int in1 , in2;
        scanf("%d %d",&in1 , &in2);

        printf("%d\n",query(1 , 1 , n , in1 , in2).a*2);
    }

    return 0;
}

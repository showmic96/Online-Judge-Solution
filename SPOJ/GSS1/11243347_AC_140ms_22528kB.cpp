// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 50000+9;

vector<int>v , store;

ll tree[4*MAX] , suml[4*MAX] , sumr[4*MAX] , summ[4*MAX];

void _merge(int node)
{
    tree[node] = tree[2*node]+tree[2*node+1];
    suml[node] = max(suml[2*node] , tree[2*node]+suml[2*node+1]);
    sumr[node] = max(sumr[2*node+1] , tree[2*node+1]+sumr[2*node]);
    summ[node] = max(summ[2*node] , max(summ[2*node+1] ,suml[2*node+1]+sumr[2*node]));
}

void _assign(int node , int value)
{
    tree[node] = suml[node] = sumr[node] = summ[node] = value;
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

void query(int node , int st , int en , int l , int r)
{

    if(st>=l&&en<=r){

        store.push_back(node);
        return ;
    }

    if(st>r||en<l)return ;

    int mid = (st+en)/2;

    query(2*node , st , mid , l , r);
    query(2*node+1 , mid+1 , en , l , r);

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

    int m;
    scanf("%d",&m);

    while(m--){

        int in1 ,in2;
        scanf("%d %d",&in1 ,&in2);
        store.clear();
        query(1 ,1 , n , in1 , in2);

        int si = store.size();
        ll ans = -1e15 , temp = -1e15;

        for(int i=0;i<si;i++){

            ans = max(ans , summ[store[i]]);
            ans = max(ans , temp+suml[store[i]]);
            temp = max(temp+tree[store[i]] , sumr[store[i]]);
        }

        printf("%lld\n",ans);
    }

    return 0;
}

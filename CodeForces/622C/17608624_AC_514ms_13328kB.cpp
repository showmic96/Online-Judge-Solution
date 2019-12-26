// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 2e5+9;
vector<int>v(MAX);
pair<int , int> mi[4*MAX] , mx[4*MAX];

void _merge(int node)
{
    if(mi[2*node].first<mi[2*node+1].first){

        mi[node] = mi[2*node];
    }
    else{

        mi[node] = mi[2*node+1];
    }

    if(mx[2*node].first>mx[2*node+1].first){

        mx[node] = mx[2*node];
    }
    else{

        mx[node] = mx[2*node+1];
    }
}

void build(int node , int st , int en)
{
    if(st==en){

        mi[node].first = v[st-1];
        mi[node].second = st;
        mx[node] = mi[node];
        return ;
    }

    int mid = (st+en)/2;
    build(2*node , st , mid);
    build(2*node+1 , mid+1 , en);

    _merge(node);
}

pair<int , int> query(int node , int st , int en , int l , int r , int type)
{
    if(st>r||en<l){

        if(type==0)return {1e9 , 1e9};
        return {0 , 0};
    }
    if(st>=l&&en<=r){

        if(type==0)return mi[node];
        return mx[node];
    }

    int mid = (st+en)/2;

    if(type==0)return min(query(2*node , st , mid , l , r , type),query(2*node+1 , mid+1 , en , l , r ,type));
    return max(query(2*node , st , mid , l , r , type) , query(2*node+1 , mid+1 , en , l , r , type));
}

int main(void)
{
    int n , m;
    scanf("%d %d",&n , &m);

    for(int i=0;i<n;i++)scanf("%d",&v[i]);
    build(1 , 1 , n);

    while(m--){

        int in1 , in2 , in3;
        scanf("%d %d %d",&in1 , &in2 , &in3);

        pair<int , int>t1 = query(1 , 1 , n , in1 , in2 , 0);
        pair<int , int>t2 = query(1 , 1 , n , in1 , in2 , 1);

        if(t1.first!=in3)printf("%d\n",t1.second);
        else if(t2.first!=in3)printf("%d\n",t2.second);
        else printf("-1\n");
    }

    return 0;
}

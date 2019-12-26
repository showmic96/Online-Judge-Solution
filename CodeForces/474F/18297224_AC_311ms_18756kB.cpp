// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1e5+9;

int gcd[4*MAX];
vector<int>v , tree[4*MAX];

void build(int node , int st , int en)
{
    if(st==en){

        tree[node].push_back(v[st-1]);
        gcd[node] = v[st-1];
        return ;
    }
    int mid = (st+en)/2;
    build(2*node , st , mid);
    build(2*node+1 , mid+1 , en);
    merge(tree[2*node].begin() , tree[2*node].end() , tree[2*node+1].begin() , tree[2*node+1].end() , back_inserter(tree[node]));
    gcd[node] = __gcd(gcd[2*node] , gcd[2*node+1]);
}

int query(int node , int st , int en , int l , int r)
{
    if(st>r||en<l)return 0;
    if(st>=l&&en<=r)return gcd[node];
    int mid = (st+en)/2;
    return __gcd(query(2*node , st , mid , l , r) , query(2*node+1 , mid+1 , en , l , r));
}

int q(int node , int st , int en , int l , int r , int val)
{
    if(st>r||en<l)return 0;
    if(st>=l&&en<=r)return upper_bound(tree[node].begin() , tree[node].end() , val) - lower_bound(tree[node].begin() , tree[node].end() , val);
    int mid = (st+en)/2;
    return q(2*node , st , mid , l , r , val) + q(2*node+1 , mid+1 , en , l , r , val);
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

        int in1 , in2;
        scanf("%d %d",&in1 , &in2);
        printf("%d\n",in2-in1+1-q(1 , 1 , n , in1 , in2 , query(1 , 1 , n , in1 , in2)));
    }
    return 0;
}

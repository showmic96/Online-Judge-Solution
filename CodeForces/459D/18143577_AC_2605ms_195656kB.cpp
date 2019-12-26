// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1e6+9;
vector<int>tree[4*MAX] , v , temp;
map<int , int>mp;

void build(int node , int st , int en)
{
    if(st==en){

        tree[node].emplace_back(v[st-1]);
        return ;
    }
    int mid = (st+en)/2;
    build(2*node , st , mid);
    build(2*node+1 , mid+1 , en);

    merge(tree[2*node].begin() , tree[2*node].end() , tree[2*node+1].begin() , tree[2*node+1].end(),back_inserter(tree[node]));
}

int query(int node , int st , int en , int l , int r , ll val)
{
    if(st>r||en<l)return 0;
    if(st>=l&&en<=r){

        ll temp = lower_bound(tree[node].begin() , tree[node].end() , val) - tree[node].begin();
        return temp;
    }
    int mid = (st+en)/2;
    return query(2*node , st , mid , l , r , val) + query(2*node+1 , mid+1 , en , l , r , val);
}

int main(void)
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){

        int in;
        scanf("%d",&in);
        v.emplace_back(in);
    }
    temp = v;
    for(int i=n-1;i>=0;i--){

        mp[v[i]]++;
        v[i] = mp[v[i]];
    }
    build(1 , 1 , n);
    ll ans = 0 , counter;
    mp.clear();

    for(int i=0;i<n;i++){

        mp[temp[i]]++;
        ans+=query(1 , 1 , n , i+2 , n , mp[temp[i]]);
    }

    printf("%lld\n",ans);
    return 0;
}

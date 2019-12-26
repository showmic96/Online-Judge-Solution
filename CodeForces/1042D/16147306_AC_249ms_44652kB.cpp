// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n , t;
vector<ll>tree[4*200005];
vector<ll>v;
ll sum[200005];

void build(int node , int st , int en)
{
    if(st==en){

        tree[node].push_back(sum[st]);
        return ;
    }

    int mid = (st+en)/2;
    build(2*node , st , mid);
    build(2*node+1 , mid+1 , en);
    tree[node].resize(tree[2*node].size()+tree[2*node+1].size());
    merge(tree[2*node].begin() , tree[2*node].end() , tree[2*node+1].begin() , tree[2*node+1].end() , tree[node].begin());
}

ll query(int node , int st , int en , int l , int r , ll k)
{
    if(st>r||en<l||l>r)return 0;
    if(st>=l&&en<=r)return tree[node].size()-(upper_bound(tree[node].begin() , tree[node].end() , k) - tree[node].begin());

    int mid = (st+en)/2;

    return query(2*node , st , mid , l , r ,k) + query(2*node+1 , mid+1 , en , l , r,k);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> t;

    memset(sum , 0 , sizeof(sum));

    ll counter = 0;

    for(int i=0;i<n;i++){

        ll in;
        cin >> in;
        sum[i+1]+=sum[i]+in;
        if(sum[i+1]<t)counter++;
    }
    build(1 , 1 , n);
    for(int i=1;i<=n;i++){

        counter+=query(1 , 1 , n , 1 , i-1 , sum[i]-t);
    }

    cout << counter << endl;

    return 0;
}

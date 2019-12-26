// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>v , tree[4*1000005];

void _merge(int node)
{
    int i = 0 , j = 0 , l = 2*node , r = 2*node+1;
    for(int k=0;k<tree[l].size()+tree[r].size();k++){

        if(i==tree[l].size()){

            tree[node].push_back(tree[r][j]);
            j++;
        }
        else if(j==tree[r].size()){

            tree[node].push_back(tree[l][i]);
            i++;
        }
        else if(tree[l][i]>tree[r][j]){

            tree[node].push_back(tree[r][j]);
            j++;
        }
        else{

            tree[node].push_back(tree[l][i]);
            i++;
        }
    }
}

void build(int node , int st , int en)
{
    if(st==en){

        tree[node].push_back(v[st-1]);
        return ;
    }

    int mid = (st+en)/2;

    build(2*node , st , mid);
    build(2*node+1 , mid+1 , en);
    _merge(node);
}

ll query1(int node , int st , int en , int l , int r , int val)
{
    if(st>r||en<l)return 0;
    if(st>=l&&en<=r){

        ll ans = lower_bound(tree[node].begin() , tree[node].end() , val) - tree[node].begin();
        return ans;
    }

    int mid = (st+en)/2;
    return query1(2*node , st , mid , l , r , val) + query1(2*node+1 , mid+1 , en , l , r , val);
}

ll query2(int node , int st , int en , int l , int r , int val)
{
    if(st>r||en<l)return 0;
    if(st>=l&&en<=r){

        ll ans = tree[node].end() - upper_bound(tree[node].begin() , tree[node].end() , val);
        return ans;
    }

    int mid = (st+en)/2;
    return query2(2*node , st , mid , l , r , val) + query2(2*node+1 , mid+1 , en , l , r , val);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;

    for(int i=0;i<n;i++){

        int in;
        cin >> in;
        v.push_back(in);
    }

    build(1 , 1 , n);

    ll ans = 0;

    for(int i=1;i<n-1;i++){

        ans+=query2(1 , 1 , n , 1 , i , v[i]) * query1(1 , 1 , n , i+2 , n , v[i]);
    }

    cout << ans << endl;

    return 0;
}

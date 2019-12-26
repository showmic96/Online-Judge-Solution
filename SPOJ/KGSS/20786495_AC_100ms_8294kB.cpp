// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5+9;
pair<ll , ll> tree[4*MAX+9];
ll v[MAX+9];

void build(int node , int st , int en)
{
    if(st==en){
        tree[node] = {v[st] , st};
        return ;
    }
    int mid = (st+en)/2;
    build(2*node , st , mid);
    build(2*node+1 , mid+1 , en);
    if(tree[2*node].first>tree[2*node+1].first){
        tree[node] = tree[2*node];
    }
    else{
        tree[node] = tree[2*node+1];
    }
}
void update(int node , int st , int en , int idx , ll val)
{
    if(st==en){
        tree[node] = {val , idx};
        return ;
    }
    int mid = (st+en)/2;
    if(idx<=mid)update(2*node , st , mid , idx , val);
    else update(2*node+1 , mid+1 , en , idx , val);
    if(tree[2*node].first>tree[2*node+1].first){
        tree[node] = tree[2*node];
    }
    else{
        tree[node] = tree[2*node+1];
    }
}
pair<ll , ll > query(int node , int st , int en , int l , int r)
{
    if(st>r||en<l)return {-1e17 , -3};
    if(st>=l&&en<=r)return tree[node];
    int mid = (st+en)/2;
    pair<ll , ll > q1 = query(2*node , st , mid , l , r);
    pair<ll , ll > q2 = query(2*node+1 , mid+1 , en , l , r);
    if(q1.first>q2.first)return q1;
    return q2;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)cin >> v[i];
    build(1 , 1 , n);
    int q;
    cin >> q;
    while(q--){
        string ar;
        int in1 , in2;
        cin >> ar >> in1 >> in2;
        if(ar=="U"){
            update(1 , 1 , n , in1 , in2);
        }
        else{
            pair<ll , ll > q1 = query(1 , 1 , n , in1 , in2);
            update(1 , 1 , n , q1.second , -1e17);
            pair<ll , ll > q2 = query(1 , 1, n , in1 ,in2);
            cout << q1.first+q2.first << endl;
            update(1 , 1 , n , q1.second , q1.first);
        }
    }
    return 0;
}

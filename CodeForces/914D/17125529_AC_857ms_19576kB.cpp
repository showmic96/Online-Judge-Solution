// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 5e5 + 9;
ll tree[4*MAX+9];
vector<ll>v(MAX+9);

void build(int node , int st , int en)
{
    if(st==en){

        tree[node] = v[st-1];
        return ;
    }

    int mid = (st+en)/2;
    build(2*node , st , mid);
    build(2*node+1 , mid+1 , en);

    tree[node] = __gcd(tree[2*node] , tree[2*node+1]);
}

void update(int node ,int st , int en , int idx , ll val)
{
    if(st==en){

        tree[node] = val;
        return ;
    }

    int mid = (st+en)/2;
    if(idx<=mid)update(2*node , st , mid , idx , val);
    else update(2*node+1 , mid+1 , en , idx , val);

    tree[node] = __gcd(tree[2*node] , tree[2*node+1]);
}

int query(int node , int st , int en , int l , int r , ll x)
{
    if(st>r||en<l)return 0;

    int mid = (st+en)/2;
    if(st==en){
        return min(1LL , tree[node]%x);
    }
    if(st>=l&&en<=r){

        if(tree[node]%x==0)return 0;
        else if(tree[2*node]%x&&tree[2*node+1]%x)return 11;
        else if(tree[2*node]%x)return query(2*node , st , mid , l , r , x);
        else return query(2*node+1 , mid+1 , en , l , r , x);
    }

    return query(2*node , st , mid , l , r , x) + query(2*node+1 , mid+1 , en , l , r , x);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;

    for(int i=0;i<n;i++){

        cin >> v[i];
    }

    build(1 , 1 , n);

    int m;
    cin >> m;
    while(m--){

        int in;
        cin >> in;

        if(in==1){

            int in1 , in2 , in3;
            cin >> in1 >> in2 >> in3;

            int ans = query(1 , 1 , n , in1 , in2 , in3);
            if(ans<2)cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
        else{

            int in1 , in2;
            cin >> in1 >> in2;
            update(1 , 1 , n , in1 , in2);
        }
    }

    return 0;
}

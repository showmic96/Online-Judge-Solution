// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll>v;
ll tree[4000000];

void build(int node , int st , int en)
{
    if(st==en){

        tree[node] = v[st-1];
        return ;
    }

    int mid = (st+en)/2;

    build(2*node , st , mid);
    build(2*node+1 , mid+1 , en);

    tree[node] = tree[2*node]+tree[2*node+1];
}

void update(int node , int st , int en , int idx , ll val)
{
    if(st==en){

        tree[node]+=val;
        return ;
    }

    int mid = (st+en)/2;

    if(idx>=st&&idx<=mid)update(2*node , st , mid , idx , val);
    else update(2*node+1 , mid+1 , en , idx , val);

    tree[node] = tree[2*node]+tree[2*node+1];
}

ll query(int node , int st , int en , int l , int r)
{
    if(st>r||en<l)return 0;
    if(st>=l&&en<=r)return tree[node];

    int mid = (st+en)/2;

    return query(2*node , st , mid , l , r)+query(2*node+1 , mid+1 , en , l , r);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for(int i=0;i<n;i++){

        ll in;
        cin >> in;
        v.push_back(in);
    }

    build(1 , 1 , n);

    int q;
    cin >> q;

    while(q--){

        string ar;
        cin >> ar;

        if(ar=="q"){

            int in1 , in2;
            cin >> in1 >> in2;

            cout << query(1 , 1 , n , in1 , in2) << endl;
        }

        else{

            int in1 , in2;
            cin >> in1 >> in2;

            update(1 , 1 , n , in1 , in2);
        }
    }

    return 0;
}

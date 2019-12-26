// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5 + 9;

vector<int>v;

pair<ll , ll > tree[4*MAX];

void _merge(int node)
{
    ll ar[4];

    ar[0] = tree[2*node].first;
    ar[1] = tree[2*node].second;
    ar[2] = tree[2*node+1].first;
    ar[3] = tree[2*node+1].second;

    sort(ar , ar+4);

    tree[node].first = ar[3];
    tree[node].second = ar[2];
}

void build(int node , int st , int en)
{
    if(st==en){

        tree[node].first = v[st-1];
        tree[node].second = 0;

        return ;
    }

    int mid = (st+en)/2;

    build(2*node , st , mid);
    build(2*node+1 , mid+1 , en);

    _merge(node);
}

void update(int node , int st , int en , int idx , int value)
{
    if(st==en){

        tree[node].first = value;
        tree[node].second = 0;

        return ;
    }

    int mid = (st+en)/2;

    if(idx>=st&&idx<=mid)update(2*node , st , mid , idx , value);
    else update(2*node+1 , mid+1 , en , idx , value);

    _merge(node);
}

pair<ll , ll > query(int node , int st , int en , int l , int r)
{
    if(st>=l&&en<=r){

        return tree[node];
    }

    if(l>en||r<st){

        return make_pair(0 , 0);
    }

    int mid = (st+en)/2;

    pair<ll , ll > p1 = query(2*node , st , mid , l , r);
    pair<ll , ll > p2 = query(2*node+1 , mid+1 , en , l , r);

    pair<ll , ll > p;

    p.first = max(p1.first , p2.first);
    p.second = max(min(p1.first , p2.first) , max(p1.second , p2.second));

    return p;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0;i<n;i++){

        int in;
        cin >> in;
        v.push_back(in);
    }

    build(1 , 1 , n);

    int q;
    cin >> q;

    while(q--){

        char x;
        cin >> x;

        if(x=='Q'){

            int in1 , in2;
            cin >> in1 >> in2;

            pair<int , int> p = query(1 , 1 , n , in1 ,in2);

            cout << p.first+p.second << endl;
        }

        else{

            int in1 ,in2;
            cin >> in1 >> in2;

            update(1 , 1 , n , in1 , in2);
        }
    }

    return 0;
}

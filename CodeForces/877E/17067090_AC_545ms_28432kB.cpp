// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>edges[200005] , store , v;
int cur = 0 , st[200005] , en[200005];
ll tree[800005] , lazy[800005];

void dfs(int u , int par = -1)
{
    cur++;
    st[u] = cur;
    store.push_back(u);

    for(auto v : edges[u]){

        if(v!=par)dfs(v , u);
    }

    en[u] = cur;
}

void build(int node , int st , int en)
{
    if(st==en){

        tree[node] = v[store[st]-1];
        return ;
    }

    int mid = (st+en)/2;
    build(2*node , st , mid);
    build(2*node+1 , mid+1 , en);

    tree[node] = tree[2*node] + tree[2*node+1];
}

void update(int node , int st , int en , int l , int r)
{
    lazy[node]%=2;

    if(lazy[node]!=0){

        if(st!=en){
            lazy[2*node]++;
            lazy[2*node+1]++;
        }

        lazy[node] = 0;

        tree[node] = (en-st+1)-tree[node];
    }

    if(r<st||l>en)return ;
    if(st>=l&&en<=r){

        lazy[node]++;
        lazy[node]%=2;

        if(lazy[node]!=0){

            if(st!=en){
                lazy[2*node]++;
                lazy[2*node+1]++;
            }

            lazy[node] = 0;

            tree[node] = (en-st+1)-tree[node];
        }
        return ;
    }

    int mid = (st+en)/2;
    update(2*node , st , mid , l , r);
    update(2*node+1 , mid+1 , en , l , r);

    tree[node] = tree[2*node] + tree[2*node+1];
}

ll query (int node , int st , int en , int l , int r)
{
    lazy[node]%=2;

    if(lazy[node]!=0){

        if(st!=en){
            lazy[2*node]++;
            lazy[2*node+1]++;
        }

        lazy[node] = 0;

        tree[node] = (en-st+1)-tree[node];
    }

    if(r<st||l>en)return 0;
    if(st>=l&&en<=r){

        return tree[node];
    }

    int mid = (st+en)/2;
    ll q1 = query(2*node , st , mid , l , r);
    ll q2 = query(2*node+1 , mid+1 , en , l , r);

    return q1+q2;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    store.emplace_back(0);

    int n;
    cin >> n;

    for(int i=2;i<=n;i++){

        int in;
        cin >> in;

        edges[in].emplace_back(i);
        edges[i].emplace_back(in);
    }

    for(int i=0;i<n;i++){

        int in;
        cin >> in;
        v.emplace_back(in);
    }

    dfs(1);
    build(1 , 1 , n);

    int q;
    cin >> q;

    while(q--){

        string ar;
        cin >> ar;

        if(ar[0]=='g'){

            int in;
            cin >> in;
            cout << query(1 , 1 , n , st[in] , en[in]) << '\n';
        }
        else{

            int in;
            cin >> in;
            update(1 , 1 , n , st[in] , en[in]);
        }
    }

    return 0;
}

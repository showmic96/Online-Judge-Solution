// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5+9;

ll tree[4*MAX][26];
string ar;
void calculate(int node)
{
    for(int i=0;i<26;i++){
        tree[node][i] = tree[2*node][i] + tree[2*node+1][i];
    }
}
int query(int node , int st , int en , int l , int r , int val)
{
    if(st>r||en<l)return 0;
    if(st>=l&&en<=r)return tree[node][val];
    int mid = (st+en)/2;
    return query(2*node , st , mid , l , r , val) + query(2*node+1 , mid+1 , en , l , r , val);
}
void update(int node , int st , int en , int idx , int val)
{
    if(st==en){
        memset(tree[node] , 0 , sizeof(tree[node]));
        tree[node][val] = 1;
        return ;
    }
    int mid = (st+en)/2;
    if(idx<=mid)update(2*node, st , mid , idx , val);
    else update(2*node+1 , mid+1 , en , idx , val);
    calculate(node);
}
void build(int node , int st , int en)
{
    if(st==en){
        tree[node][ar[st-1]-'a'] = 1;
        return ;
    }
    int mid = (st+en)/2;
    build(2*node , st , mid);
    build(2*node+1 , mid+1 , en);
    calculate(node);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n , m;
    cin >> n >> m;
    cin >> ar;
    build(1 , 1, n);
    while(m--){
        int t;
        cin >> t;
        if(t==1){
             int idx;
             char x;
             cin >> idx >> x;
             update(1 , 1 , n , idx , x-'a');
        }
        else{
            int in1 , in2;
            char x;
            cin >> in1 >> in2 >> x;
            cout << query(1 , 1, n , in1 , in2 , x-'a') << endl;
        }
    }
    return 0;
}

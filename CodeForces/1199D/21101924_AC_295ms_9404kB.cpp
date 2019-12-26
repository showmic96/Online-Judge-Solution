// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 2e5+9;
ll tree[4*MAX] , lst[MAX] , ar[MAX];
vector<ll>v;

void update(int node , int st , int en , int idx , int val)
{
    if(st==en){
        tree[node] = val;
        return ;
    }
    int mid = (st+en)/2;
    if(idx<=mid)update(2*node , st , mid , idx , val);
    else update(2*node+1 , mid+1 , en , idx , val);
    tree[node] = max(tree[2*node] , tree[2*node+1]);
}
ll query(int node , int st , int en , int l , int r)
{
    if(st>r||en<l)return -1e18;
    if(st>=l&&en<=r)return tree[node];
    int mid = (st+en)/2;
    return max(query(2*node , st , mid , l , r) , query(2*node+1 , mid+1 , en , l , r));
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    for(int i=1;i<=n;i++)cin >> ar[i];
    int q;
    cin >> q;
    for(int i=1;i<=q;i++){
        int in;
        cin >> in;
        if(in==1){
            int in1 , in2;
            cin >> in1 >> in2;
            ar[in1] = in2;
            lst[in1] = i;
        }
        else{
            int in1;
            cin >> in1;
            update(1 , 1 , q , i , in1);
        }
    }
    for(int i=1;i<=n;i++){
        ll temp = query(1 , 1 , q , lst[i]+1 , q);
        cout << max(temp , ar[i]) << " ";
    }

    return 0;
}

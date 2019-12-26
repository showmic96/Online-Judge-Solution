// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1e5+9;
ll tree[4*MAX];
vector<ll>v;

void build(int node , int st , int en)
{
    if(st==en){
        tree[node] = v[st-1];
        return ;
    }
    int mid = (st+en)/2;
    build(2*node , st , mid);
    build(2*node+1 , mid+1 , en);
    tree[node] = min(tree[2*node] , tree[2*node+1]);
}
ll query(int node , int st , int en , int l , int r)
{
    if(st>r||en<l)return 1e18;
    if(st>=l&&en<=r)return tree[node];
    int mid = (st+en)/2;
    return min(query(2*node , st , mid , l , r) , query(2*node+1 , mid+1 , en , l , r));
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n , x , y;
    cin >> n >> x >> y;
    for(int i=0;i<n;i++){
        ll in;
        cin >> in;
        v.push_back(in);
    }
    build(1 , 1 , n);
    int ans = -1;
    for(int i=1;i<=n;i++){
        if(i==1){
            ll q1 = query(1 , 1, n , i+1 , min(n , i+y));
            if(q1>v[i-1]){
                cout << i << endl;
                return 0;
            }
        }
        else if(i==n){
            ll q1 = query(1 , 1 , n , max(1 , i-x) , i-1);
            if(q1>v[i-1]){
                cout << i << endl;
                return 0;
            }
        }
        else{
            ll q1 = query(1 , 1, n , i+1 , min(n , i+y));
            ll q2 = query(1 , 1 , n , max(1 , i-x) , i-1);
            if(q1>v[i-1]&&q2>v[i-1]){
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

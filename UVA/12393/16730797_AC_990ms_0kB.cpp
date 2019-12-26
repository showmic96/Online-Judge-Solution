// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 2e6;

ll tree[4*MAX] , sum[2*MAX+9];
int n;
vector<ll>v;

void build(int node , int st , int en)
{
    if(st==en){

        tree[node] = sum[st];
        return ;
    }

    int mid = (st+en)/2;
    build(2*node , st , mid);
    build(2*node+1 , mid+1 , en);

    tree[node] = min(tree[2*node] , tree[2*node+1]);
}

ll query(int node , int st , int en , int l , int r)
{
    if(st>r||en<l)return 1e9;
    if(st>=l&&en<=r)return tree[node];

    int mid = (st+en)/2;

    return min(query(2*node , st , mid , l , r) , query(2*node+1 , mid+1 , en , l , r));
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    while(cin >> n){

        if(n==0)break;
        v.clear();

        for(int i=0;i<n;i++){

            ll in;
            cin >> in;
            v.push_back(in);
        }

        for(int i=0;i<n;i++){

            v.push_back(v[i]);
        }

        sum[0] = 0;
        for(int i=1;i<=2*n;i++){

            sum[i] = sum[i-1]+v[i-1];

        }

        build(1 , 1 , 2*n);

        ll ans = 0;

        for(int i=1;i<=n;i++){

            ll temp = query(1 , 1 , 2*n , i , i+n-1);

            if(temp-sum[i-1]>=0)ans++;
        }

        cout << ans << endl;
    }

    return 0;
}

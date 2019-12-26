// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5 + 9;
ll tree[6*MAX+9] , lazy[6*MAX+9];

void update(int node , int st , int en , int l , int r , int value)
{

    if(st>=l&&en<=r){

        tree[node] = (en-st+1)*value;
        if(st!=en){

            lazy[2*node] = value;
            lazy[2*node+1] = value;
        }

        lazy[node] = -1;

        return ;
    }

    if(lazy[node]!=-1){

        tree[node] = (en-st+1)*lazy[node];

        if(st!=en){

            lazy[2*node] = lazy[node];
            lazy[2*node+1] = lazy[node];
        }

        lazy[node] = -1;
    }

    if(r<st||l>en)return ;

    int mid = (st+en)/2;

    update(2*node , st , mid , l , r , value);
    update(2*node+1 , mid+1 , en , l , r , value);

    tree[node]=tree[2*node]+tree[2*node+1];
}

ll query(int node , int st , int en , int l , int r)
{

    if(lazy[node]!=-1){

        tree[node] = (en-st+1)*lazy[node];

        if(st!=en){

            lazy[2*node] = lazy[node];
            lazy[2*node+1] = lazy[node];
        }

        lazy[node] = -1;
    }

    if(r<st||l>en)return 0;

    if(st>=l&&en<=r){

        return tree[node];
    }

    int mid = (st+en)/2;

    ll p1 = query(2*node , st , mid , l , r);
    ll p2 = query(2*node+1 , mid+1 , en , l , r);

    return p1+p2;
}

int main(void)
{
    int t , c = 0;

    scanf("%d",&t);
    while(t--){

        int n , q;
        scanf("%d",&n);

        memset(tree , 0 , sizeof(tree));
        memset(lazy , -1 , sizeof(lazy));

        vector<pair<int , int> > v;

        for(int i=0;i<n;i++){

            int in1 , in2;
            scanf("%d %d",&in1, &in2);

            v.push_back(make_pair(in1 , in2));
            update(1 , 1 , 2*n , in1 , in2 , 1);
        }

        int ans = 0;

        for(int i=n-1;i>=0;i--){

            int value = query(1 ,1 , 2*n , v[i].first , v[i].second);

            if(value!=0){

                update(1 , 1 , 2*n , v[i].first , v[i].second , 0);
                ans++;
            }
        }

        printf("Case %d: %d\n",++c , ans);
    }
    return 0;
}

// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 40000*4;

ll tree[3*MAX] , lazy[3*MAX];

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
    int t;
    scanf("%d",&t);

    while(t--){

        memset(tree , 0 , sizeof(tree));
        memset(lazy , -1 , sizeof(lazy));

        int n;
        scanf("%d",&n);

        set<int>st;
        vector<pair< int , int > > v;
        map<int , int>mp;

        for(int i=0;i<n;i++){

            int in1 , in2;
            scanf("%d %d",&in1 ,&in2);
            st.insert(in1);
            st.insert(in2);

            v.push_back(make_pair(in1 , in2));
        }

        int c = 1;

        for(set<int>::iterator it = st.begin();it!=st.end();it++){

            mp[*it] = ++c;
        }

        c+=10;

        for(int i=0;i<n;i++){

            update(1 , 1 , c , mp[v[i].first] , mp[v[i].second] , 1);
        }

        int ans = 0;

        for(int i=n-1;i>=0;i--){

            if(query(1 , 1 , c , mp[v[i].first] , mp[v[i].second])!=0){

                ans++;
                update(1 , 1 , c , mp[v[i].first] , mp[v[i].second] , 0);
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}

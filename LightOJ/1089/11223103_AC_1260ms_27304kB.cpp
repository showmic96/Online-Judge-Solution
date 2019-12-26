// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 50000*3;

ll tree[5*MAX] , lazy[5*MAX];

void update(int node , int st , int en , int l , int r , int v)
{
    if(lazy[node]!=0){

        tree[node]+=(en-st+1)*lazy[node];

        if(st!=en){

            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }

        lazy[node]=0;
    }

    if(st>=l&&en<=r){

        tree[node]+=(en-st+1)*v;
        if(st!=en){

            lazy[2*node]+=v;
            lazy[2*node+1]+=v;
        }

        //lazy[node] = 0;
        return ;
    }

    if(st>r||en<l)return ;

    int mid = (st+en)/2;

    update(2*node , st , mid , l , r , v);
    update(2*node+1, mid+1 , en , l , r , v);

    tree[node]+=tree[2*node]+tree[2*node+1];
}

ll query(int node , int st , int en , int idx)
{

    if(lazy[node]!=0){

        tree[node] += (en-st+1)*lazy[node];

        if(st!=en){

            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }

        lazy[node] = 0;
    }


    if(st==en){

        return tree[node];
    }

    int mid = (st+en)/2;

    if(idx>=st&&idx<=mid)return query(2*node , st , mid , idx);
    else return query(2*node+1 , mid+1 , en , idx);
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        memset(tree , 0 , sizeof(tree));
        memset(lazy , 0 , sizeof(lazy));

        int n , q;
        scanf("%d %d", &n , &q);

        map<int , int>mp;
        vector<pair<int , int> > v;
        vector<int>data;
        set<int>st;

        for(int i=0;i<n;i++){

            int in1 ,in2;
            scanf("%d %d",&in1 , &in2);

            in1++;in2++;

            v.push_back(make_pair(in1 , in2));
            st.insert(in1);
            st.insert(in2);
        }

        int en = 1;

        for(int i=0;i<q;i++){

            int in;
            scanf("%d",&in);
            in++;
            st.insert(in);
            data.push_back(in);
        }

        for(set<int>::iterator it = st.begin();it!=st.end();it++){

            mp[*it] = en;

            en++;
        }

        for(int i=0;i<n;i++){

            update(1 , 1 , en , mp[v[i].first] , mp[v[i].second] , 1);
        }

        printf("Case %d:\n",++c);

        for(int i=0;i<q;i++){

            printf("%d\n",query(1 , 1 , en , mp[data[i]]));
        }
    }

    return 0;
}

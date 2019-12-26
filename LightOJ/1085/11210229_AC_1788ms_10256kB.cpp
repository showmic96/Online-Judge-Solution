// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MOD = 1000000007;
const int MAX = 1e5 + 9;

ll tree[3*MAX];

void update(int node , int st , int en , int idx , int value)
{
    if(st==en&&st==idx){

        tree[node]+=value;
        tree[node]%=MOD;
        return ;
    }

    int mid = (st+en)/2;

    if(idx<=mid&&idx>=st){

        update(2*node , st , mid , idx , value);
    }
    else{
        update(2*node+1 , mid+1 , en , idx, value);
    }

    tree[node] = tree[2*node]+tree[2*node+1];
    tree[node]%=MOD;
}

ll query(int node , int st , int en , int l , int r)
{
    if(l>en||st>r)return 0;
    if(st>=l&&en<=r)return tree[node];

    int mid = (st+en)/2;

    ll p1 = query(2*node , st , mid , l , r);
    ll p2 = query(2*node+1 , mid+1 , en , l , r);

    p1%=MOD;
    p2%=MOD;

    return (p1+p2)%MOD;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        memset(tree , 0 , sizeof(tree));

        int n;
        scanf("%d",&n);
        vector<int>v , sv;
        set<int>st;

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            v.push_back(in);
            st.insert(in);
        }

        for(set<int>::iterator it = st.begin();it!=st.end();it++){

            sv.push_back(*it);
        }

        for(int i=0;i<n;i++){

            int idx = lower_bound(sv.begin() , sv.end() ,v[i]) - sv.begin();

            if(idx==0){

                update(1 , 1 , n , 1 , 1);
            }

            else{

                ll last_value = query(1 , 1 , n , 1 , idx);
                update(1 , 1 , n , idx+1 , last_value+1);
            }
        }

        printf("Case %d: %lld\n", ++c , tree[1]);
    }

    return 0;
}

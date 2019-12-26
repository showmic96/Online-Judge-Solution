// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll block , a , n , m , k;
ll ar[2000005];

struct s{

    ll l , r , idx;
    s(ll _l , ll _r , ll _idx){

        l = _l;
        r = _r;
        idx = _idx;
    }
};

vector<ll>v , ans;
vector<s>query;

bool cmp(s A , s B)
{
    if(A.l/block!=B.l/block){

        return A.l/block<B.l/block;
    }

    return A.r<B.r;
}

void add(ll idx)
{
    ll temp = k^v[idx];
    a+=ar[temp];
    ar[v[idx]]++;
}

void rem(ll idx)
{
    ll temp = k^v[idx];
    ar[v[idx]]--;
    a-=ar[temp];
}

int main(void)
{
    memset(ar , 0 , sizeof(ar));

    scanf("%lld %lld %lld",&n , &m , &k);

    v.push_back(0);

    for(int i=0;i<n;i++){

        ll in;
        scanf("%lld",&in);
        v.push_back(in);
    }

    for(int i=1;i<=n;i++){

        v[i] = v[i]^v[i-1];
    }

    for(int i=0;i<m;i++){

        ll in1 , in2;
        scanf("%lld %lld",&in1 , &in2);

        query.push_back(s(in1-1, in2 , i));
        ans.push_back(0);
    }

    block = sqrt(n);
    sort(query.begin() , query.end() , cmp);

    ll l = 0 , r = 0;
    a = 0;

    for(int i=0;i<m;i++){

        ll left = query[i].l;
        ll right = query[i].r;

        while(l<left){

            rem(l);
            l++;
        }
        while(l>left){

            add(l-1);
            l--;
        }

        while(r<=right){

            add(r);
            r++;
        }
        while(r>right+1){

            rem(r-1);
            r--;
        }

        ans[query[i].idx] = a;
    }

    for(int i=0;i<m;i++)printf("%lld\n",ans[i]);

    return 0;
}

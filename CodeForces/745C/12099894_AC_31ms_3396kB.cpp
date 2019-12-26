// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>edges[1010] , v;
bool visited[1010];
int c , cc;
map<pair<int ,int> , int >mp;

void dfs(int u)
{
    if(visited[u]==true)return ;

    visited[u] = true;

    c++;
    int si = edges[u].size();

    for(int i=0;i<si;i++){

        dfs(edges[u][i]);
    }
}

int main(void)
{
    memset(visited , false ,sizeof(visited));

    int n , m , k;
    scanf("%d %d %d",&n , &m ,&k);

    for(int i=0;i<k;i++){

        int in;
        scanf("%d",&in);
        v.push_back(in);
    }

    for(int i=0;i<m;i++){

        int in1 , in2;
        scanf("%d %d",&in1 , &in2);
        edges[in1].push_back(in2);
        edges[in2].push_back(in1);
    }

    vector<pair<ll, ll> >store;
    ll sum = 0;

    for(int i=0;i<k;i++){

        c = 0;
        cc = 0;

        dfs(v[i]);
        store.push_back(make_pair(c , cc));
        sum+=c;
    }

    sort(store.begin() , store.end());

    store[store.size()-1].first+=(n-sum);

    ll ans = 0;

    for(int i=0;i<store.size();i++){

        ll temp = store[i].first;
        ans+=temp*(temp-1)/2;
    }

    ans-=m;

    printf("%lld\n",ans);

    return 0;
}

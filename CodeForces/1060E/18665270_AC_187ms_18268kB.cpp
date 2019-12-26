// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll sum[200005] , odd[200005] , even[200005] , ans = 0 , n;
vector<int>edges[200005];

void dfs(int u , int d = 0 , int par = -1)
{
    sum[u] = 1;
    if(d%2)odd[u] = 1;
    else even[u] = 1;

    for(auto v : edges[u]){

        if(v!=par){
            dfs(v , d+1 , u);
            sum[u]+=sum[v];
            odd[u]+=odd[v];
            even[u]+=even[v];
        }
    }
    ans+=sum[u]*(n-sum[u]);
}

int main(void)
{
    scanf("%lld",&n);
    for(int i=0;i<n-1;i++){
        int in1 , in2;
        scanf("%d %d",&in1 , &in2);
        edges[in1].push_back(in2);
        edges[in2].push_back(in1);
    }
    dfs(1);
    ans+=(odd[1]*even[1]);
    printf("%lld\n",ans/2);
    return 0;
}

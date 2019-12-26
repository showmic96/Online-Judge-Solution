// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1e5+9;
vector<int>v[MAX] , store;
int n , dp[MAX];

int f(int now)
{
    if(now==n)return 0;
    if(dp[now]!=-1)return dp[now];
    int value = f(now+1);
    auto it = upper_bound(v[store[now]].begin() , v[store[now]].end() , now);
    if(it!=v[store[now]].end()){
        int nxt = *it;
        value = max(value , f(nxt)+1);
    }
    return dp[now] = value;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(dp , -1 , sizeof(dp));
        store.clear();
        for(int i=0;i<MAX;i++)v[i].clear();
        for(int i=0;i<n;i++){
            int in;
            scanf("%d",&in);
            v[in].push_back(i);
            store.push_back(in);
        }
        printf("%d\n",f(0));
    }
    return 0;
}

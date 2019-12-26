#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e3+9;
vector<int>edges[MAX];
vector<int>store[MAX];

int dp[MAX][3][MAX];
int counter = 0;
bool vis[MAX];

void dfs(int u , int par = 0)
{
    if(vis[u]==true)return ;
    vis[u] = true;
    store[counter].push_back(u);
    for(auto v : edges[u]){
        if(v!=par)dfs(v);
    }
}

int f(int u , int now , int par = 0)
{
    int value = 0;
    if(dp[u][now][par]!=-1)return dp[u][now][par];
    if(now==1)value = 1;
    for(auto v : edges[u]){
        if(par!=v)value+=f(v , now^1 , u);
    }
    int value2 = 0;
    for(auto v : edges[u]){
        if(par!=v&&now==1)value2+=f(v , 1 , u);
    }
    return dp[u][now][par] = max(value2 , value);
}
int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){
        memset(dp , -1 , sizeof(dp));
        int n , m;
        for(int i=0;i<MAX;i++)store[i].clear();
        scanf("%d %d",&n , &m);
        for(int i=0;i<=n;i++)edges[i].clear();
        for(int i=0;i<m;i++){
            int in1 ,in2;
            scanf("%d %d",&in1 , &in2);
            edges[in1].push_back(in2);
            edges[in2].push_back(in1);
        }
        counter = 0;
        memset(vis , false , sizeof(vis));
        for(int i=1;i<=n;i++){
            if(vis[i]==false){
                dfs(i);
                counter++;
            }
        }
        int ans = 0;
        for(int i1=0;i1<counter;i1++){
            int temp = 0;
            for(auto i : store[i1]){
                temp = max(temp , max(f(i , 1) , f(i , 0)));
            }
            ans+=temp;
        }
        printf("Case %d: %d\n",++c , ans);
    }
    return 0;
}

// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<pair<int , int> >edges[105] , redges[105];
int n , st , en , c , cf[105][105] , cap[105][105];
bool vis[105];
int bfs(int st , int en)
{
    memset(vis , false , sizeof(vis));
    vis[st] = true;
    queue<int>current;
    current.push(st);
    while(!current.empty()){
        int u = current.front();
        current.pop();
        for(int i=1;i<=n;i++){
            if(vis[i]==false&&cf[u][i]>0){
                vis[i]=true;
                current.push(i);
            }
        }
    }
    if(vis[en]==true)return 1;
    return 0;
}
int dfs(int u , int tot)
{
    if(u==en)return tot;
    for(int i=1;i<=n;i++){
        if(vis[i]==false&&cf[u][i]>0){
            vis[i] = true;
            int temp = dfs(i , min(tot , cf[u][i]));
            if(temp>0){
                cf[u][i]-=temp;
                cf[i][u]+=temp;
                return temp;
            }
        }
    }
    return 0;
}
int main(void)
{
    int t , tc = 0;
    cin >> t;
    while(t--){
        scanf("%d %d %d %d",&n , &st, &en , &c);
        memset(cf , 0 , sizeof(cf));
        for(int i=0;i<c;i++){
            int in1 , in2 , in3;
            scanf("%d %d %d",&in1 , &in2 , &in3);
            cf[in1][in2] += in3;
            cf[in2][in1] += in3;
        }
        int tot = 0;
        while(true){
            if(!bfs(st , en))break;
            memset(vis , false , sizeof(vis));
            tot+=dfs(st , 2e9);
        }
        printf("Case %d: %d\n",++tc , tot);
    }
    return 0;
}

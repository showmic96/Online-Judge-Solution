// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 3005;
vector<int>edges[MAX];
int dis[MAX][MAX];

void bfs(int st)
{
    queue<int>current;
    dis[st][st] = 0;
    current.push(st);
    while(!current.empty()){
        int u = current.front();
        current.pop();
        for(auto v:edges[u]){
            if(dis[st][v]==-1){
                current.push(v);
                dis[st][v] = dis[st][u]+1;
            }
        }
    }
}

int main(void)
{
    int n , m;
    scanf("%d %d",&n , &m);
    for(int i=0;i<m;i++){
        int in1 , in2;
        scanf("%d %d",&in1 , &in2);
        edges[in1].push_back(in2);
        edges[in2].push_back(in1);
    }
    memset(dis , -1 , sizeof(dis));
    for(int i=1;i<=n;i++){
        bfs(i);
    }
    int s1 , t1 , l1 , s2 , t2 , l2;
    scanf("%d %d %d",&s1 , &t1 , &l1);
    scanf("%d %d %d",&s2 , &t2 , &l2);
    if(dis[s1][t1]>l1||dis[s2][t2]>l2)printf("-1\n");
    else{
        int ans = m-dis[s1][t1]-dis[s2][t2];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int d1 = min(dis[s1][i],dis[s1][j]) + dis[i][j] + min(dis[i][t1],dis[j][t1]);
                int d2 = min(dis[s2][i],dis[s2][j]) + dis[i][j] + min(dis[i][t2],dis[j][t2]);
                if(d1>l1||d2>l2)continue;
                ans = max(ans , m-d1-d2+dis[i][j]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

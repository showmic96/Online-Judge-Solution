// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1e4+9;
bool vis[MAX+9];
int lvl[MAX+9];

void sieve()
{
    memset(vis , true , sizeof(vis));
    for(int i=2;i<=MAX;i++){
        if(vis[i]==true){
            for(int j=2*i;j<=MAX;j+=i)vis[j] = false;
        }
    }
}

int bfs(int st , int en)
{
    memset(lvl , -1 , sizeof(lvl));
    lvl[st] = 0;
    queue<int>current;
    current.push(st);
    while(!current.empty()){
        int u = current.front();
        current.pop();
        if(u==en)return lvl[u];
        for(int i=1;i<=9;i++){
            int t1 = u%1000;
            int t2 = i*1000 + t1;
            if(lvl[t2]==-1&&vis[t2]==true){
                lvl[t2] = lvl[u]+1;
                current.push(t2);
            }
        }
        for(int i=0;i<=9;i++){
            int t1 = u%100;
            int t2 = u/1000;
            int t3 = t2*1000+i*100+t1;
            if(lvl[t3]==-1&&vis[t3]==true){
                lvl[t3] = lvl[u]+1;
                current.push(t3);
            }
        }
        for(int i=0;i<=9;i++){
            int t1 = u%10;
            int t2 = u/100;
            int t3 = t2*100+i*10+t1;
            if(lvl[t3]==-1&&vis[t3]==true){
                lvl[t3] = lvl[u]+1;
                current.push(t3);
            }
        }
        for(int i=0;i<=9;i++){
            int t1 = u/10;
            int t2 = t1*10+i;
            int t3 = t2;
            if(lvl[t3]==-1&&vis[t3]==true){
                lvl[t3] = lvl[u]+1;
                current.push(t3);
            }
        }
    }
    return -1;
}

int main(void)
{
    sieve();
    int t;
    scanf("%d",&t);
    while(t--){
        int st , en;
        scanf("%d %d",&st , &en);
        int ans = bfs(st , en);
        if(ans==-1)printf("Impossible\n");
        else printf("%d\n",ans);
    }
    return 0;
}

// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 10000+9;
int lvl[MAX];

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
        int temp = (u+1)%10000;
        if(lvl[temp]==-1){

            lvl[temp] = lvl[u]+1;
            current.push(temp);
        }
        temp = (u*2)%10000;
        if(lvl[temp]==-1){

            lvl[temp] = lvl[u]+1;
            current.push(temp);
        }
        temp = (u/3)%10000;
        if(lvl[temp]==-1){

            lvl[temp] = lvl[u]+1;
            current.push(temp);
        }
    }
}

int main(void)
{
    int a , b;
    while(scanf("%d %d",&a , &b)==2){

        int ans = bfs(a , b);
        printf("%d\n",ans);
    }
    return 0;
}

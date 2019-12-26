// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>v;
int l , u , r , c = 0;
int lvl[10005];

void bfs(int u)
{
    lvl[u] = 0;
    queue<int>current;
    current.push(u);

    while(!current.empty()){

        u = current.front();
        current.pop();

        for(int i=0;i<r;i++){

            int now = (u+v[i])%10000;

            if(lvl[now]==1e9){

                lvl[now] = lvl[u]+1;
                current.push(now);
            }
        }
    }
}

int main(void)
{
    while(scanf("%d %d %d",&l , &u , &r)==3){

        if(l==0&&r==0&&r==0)break;
        v.clear();

        for(int i=0;i<r;i++){

            int in;
            scanf("%d",&in);
            v.push_back(in);
        }

        for(int i=0;i<10005;i++)lvl[i] = 1e9;
        bfs(l);

        int ans = lvl[u];;

        if(ans>=1e9)printf("Case %d: Permanently Locked\n",++c);
        else printf("Case %d: %d\n",++c , ans);
    }

    return 0;
}

// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 30005;

int par[MAX] , sz[MAX];

int Find(int x)
{
    if(x==par[x])return x;
    return par[x] = Find(par[x]);
}
void Union(int x , int y)
{
    int px = Find(x);
    int py = Find(y);
    if(px==py)return ;
    if(sz[px]<sz[py])swap(px , py);
    par[py] = px;
    sz[px]+=sz[py];
}

int main(void)
{
    int n , m;
    while(scanf("%d %d",&n, &m)==2){
        if(!n&&!m)break;
        for(int i=0;i<=n;i++){
            par[i] = i;
            sz[i] = 1;
        }
        for(int i=0;i<m;i++){
            int k;
            scanf("%d",&k);
            int now;
            scanf("%d",&now);
            for(int j=1;j<k;j++){
                int in;
                scanf("%d",&in);
                Union(now , in);
            }
        }
        printf("%d\n",sz[Find(0)]);
    }

    return 0;
}

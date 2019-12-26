// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int edges[55][55];
int deg[55];

void dfs(int now)
{
    for(int i=0;i<55;i++){
        if(edges[now][i]){
            edges[now][i]--;
            edges[i][now]--;
            dfs(i);
            printf("%d %d\n",i , now);
        }
    }
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){
        if(c>0)printf("\n");
        memset(edges , 0 , sizeof(edges));
        memset(deg , 0 , sizeof(deg));
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int in1 , in2;
            scanf("%d %d",&in1 , &in2);
            edges[in1][in2]++;
            edges[in2][in1]++;
            deg[in1]++;deg[in2]++;
        }
        bool check = true;
        for(int i=0;i<55;i++){
            if(deg[i]%2==1)check = false;
        }
        printf("Case #%d\n",++c);
        if(check==false)printf("some beads may be lost\n");
        else{
            for(int i=0;i<55;i++){
                dfs(i);
            }
        }

    }

    return 0;
}

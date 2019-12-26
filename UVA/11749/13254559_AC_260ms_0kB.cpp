// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int n , m , mx;
int ar[505][505];
bool vis[505];
set<int>st;

void dfs(int i)
{
    for(int j=1;j<=n;j++){

        if(vis[j]==false){

            if(ar[i][j]==mx){

                vis[i] = true;
                vis[j] = true;
                st.insert(i);
                st.insert(j);
                dfs(j);
            }
        }
    }
}

int main(void)
{
    while(scanf("%d %d",&n , &m)==2){

        if(!n&&!m)break;

        for(int i=0;i<=n;i++){

            for(int j=0;j<=n;j++){

                ar[i][j] = -2147483648;
            }
        }

        mx = -2147483648;

        for(int i=0;i<m;i++){

            int in1 , in2 , in3;
            scanf("%d %d %d",&in1 , &in2 , &in3);

            ar[in1][in2] = max(ar[in1][in2] , in3);
            ar[in2][in1] = max(ar[in2][in1] , in3);

            mx = max(mx , in3);
        }

        memset(vis , false ,sizeof(vis));

        int ans = 0;

        for(int i=1;i<=n;i++){

            if(vis[i]==false){

                st.clear();
                dfs(i);
                ans = max(ans , (int)st.size());
            }
        }

        printf("%d\n",ans);
    }

    return 0;
}

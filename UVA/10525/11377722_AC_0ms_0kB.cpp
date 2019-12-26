// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 30;
ll INF = 1e18;

ll dis[MAX][MAX];
ll tim[MAX][MAX];

int main(void)
{
    int t;
    scanf("%d",&t);

    bool space = false;

    while(t--){

        if(space)printf("\n");
        space = true;

        int n , m;
        scanf("%d %d",&n , &m);

        for(int i=0;i<=n;i++){

            for(int j=0;j<=n;j++){
                
                if(i==j){
                    
                    dis[i][j] = 0;
                    tim[i][j] = 0;
                    continue;
                }
                
                dis[i][j] = INF;
                tim[i][j] = INF;
            }
        }

        for(int i=0;i<m;i++){

            int in1 , in2 , in3 , in4;
            scanf("%d %d %d %d",&in1 , &in2 , &in3 , &in4);

            if(dis[in1][in2] == in3){

                tim[in1][in2] = min(tim[in1][in2] , (ll)in4);
            }

            else if(dis[in1][in2]>in3){

                tim[in1][in2] = in4;
                dis[in1][in2] = in3;
            }

            dis[in2][in1] = dis[in1][in2];
            tim[in2][in1] = tim[in1][in2];

        }

        for(int k=1;k<=n;k++){

            for(int i=1;i<=n;i++){

                for(int j=1;j<=n;j++){

                    if(dis[i][j]==dis[i][k]+dis[k][j]){

                        tim[i][j] = min(tim[i][j] , tim[i][k]+tim[k][j]);
                        tim[j][i] = tim[i][j];
                    }

                    if(dis[i][j]>dis[i][k]+dis[k][j]){

                        dis[i][j] = dis[i][k]+dis[k][j];
                        tim[i][j] = tim[i][k]+tim[k][j];

                        tim[j][i] = tim[i][j];
                        dis[j][i] = dis[i][j];
                    }
                }
            }
        }

        int q;
        scanf("%d",&q);
        while(q--){

            int in1 , in2;
            scanf("%d %d",&in1 ,&in2);

            if(dis[in1][in2]==INF)printf("No Path.\n");
            else printf("Distance and time to reach destination is %lld & %lld.\n",tim[in1][in2] , dis[in1][in2]);
        }
    }

    return 0;
}

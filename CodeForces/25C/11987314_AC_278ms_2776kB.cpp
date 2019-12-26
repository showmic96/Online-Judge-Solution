// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 300;
const int INF = 2e9;

int ar[MAX+9][MAX+9];
int dis[MAX+9][MAX+9];

void init()
{
    for(int i=0;i<=MAX;i++){

        for(int j=0;j<=MAX;j++){

            dis[i][j] = INF;
        }
    }
}

int main(void)
{
    init();

    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++){

        for(int j=1;j<=n;j++){

            scanf("%d",&ar[i][j]);
        }
    }

    for(int k=1;k<=n;k++){

        for(int i=1;i<=n;i++){

            for(int j=1;j<=n;j++){

                dis[i][j] = min(dis[i][j] , ar[i][k]+ar[k][j]);
            }
        }
    }

    int q;
    scanf("%d",&q);

    while(q--){

        int in1 , in2 , in3;
        scanf("%d %d %d",&in1 , &in2 , &in3);

        for(int i=1;i<=n;i++){

            for(int j=1;j<=n;j++){

                dis[i][j] = min(dis[i][j] , dis[i][in1]+dis[in2][j]+in3);
            }
        }

        for(int i=1;i<=n;i++){

            for(int j=1;j<=n;j++){

                dis[i][j] = min(dis[i][j] , dis[in2][i]+dis[j][in1]+in3);
            }
        }

        ll ans = 0;

        for(int i=1;i<=n;i++){

            for(int j=i+1;j<=n;j++){

                ans+=dis[i][j];
            }
        }

        printf("%lld ",ans);
    }

    return 0;
}

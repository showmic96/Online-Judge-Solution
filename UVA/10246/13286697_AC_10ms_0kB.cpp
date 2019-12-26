// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll INF = 123456789;

ll dis[85][85] , cost[85][85];
vector<ll>v;

int main(void)
{
    int n , m , q , tc = 0;
    while(scanf("%d %d %d",&n , &m , &q)==3){
        if(!n&&!m&&!q)break;
        if(tc>0)printf("\n");
        v.clear();
        v.push_back(0);


        for(int i=1;i<=n;i++){

            ll in;
            scanf("%lld",&in);
            v.push_back(in);
        }

        for(int i=1;i<=n;i++){

            for(int j=i+1;j<=n;j++){

                dis[i][j] = dis[j][i] = INF;
                cost[i][j] = cost[j][i] = INF;
            }

            cost[i][i] = v[i];
            dis[i][i] = 0;
        }

        for(int i=0;i<m;i++){

            ll in1 , in2 , in3;
            scanf("%lld %lld %lld",&in1 , &in2 , &in3);

            dis[in1][in2] = dis[in2][in1] = in3;
            cost[in1][in2] = cost[in2][in1] = max(v[in1] , v[in2]);
        }

        for(int k=1;k<=n;k++){

            for(int i=1;i<=n;i++){

                for(int j=1;j<=n;j++){

                    ll temp = dis[i][k]+dis[k][j];
                    ll t = max(cost[i][k] , cost[k][j]);

                    if(temp+t<dis[i][j]+cost[i][j]){

                        dis[i][j] = dis[j][i] = temp;
                        cost[i][j] = cost[j][i] = t;
                    }
                }
            }
        }

        for(int k=1;k<=n;k++){

            for(int i=1;i<=n;i++){

                for(int j=1;j<=n;j++){

                    ll temp = dis[i][k]+dis[k][j];
                    ll t = max(cost[i][k] , cost[k][j]);

                    if(temp+t<dis[i][j]+cost[i][j]){

                        dis[i][j] = dis[j][i] = temp;
                        cost[i][j] = cost[j][i] = t;
                    }
                }
            }
        }

        printf("Case #%d\n",++tc);

        while(q--){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);
            ll temp = dis[in1][in2]+cost[in1][in2];

            if(temp>=INF)temp = -1;

            printf("%lld\n",temp);
        }
    }

    return 0;
}

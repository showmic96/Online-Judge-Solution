// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[35][35];
bool ar[35][35][2];

int s1 , s2 , e1 , e2 , n;

ll f(int i , int j)
{
    if(i==e1&&j==e2)return 1;
    if(i<=0||j<=0)return 0;
    if(i>n||j>n)return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    ll value = 0;

    if(ar[i][j][0]==true)value+=f(i+1 , j);
    if(ar[i][j][1]==true)value+=f(i , j+1);

    return dp[i][j] = value;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        memset(dp , -1 , sizeof(dp));
        memset(ar , true ,sizeof(ar));
        scanf("%d",&n);

        scanf("%d %d %d %d",&s2 , &s1 , &e2 , &e1);

        int q;
        scanf("%d",&q);

        while(q--){

            int in1 , in2;
            char in3[3];
            scanf("%d %d %s",&in2 , &in1 , &in3);

            if(in3[0]=='N'){

                ar[in1][in2][0] = false;
            }

            if(in3[0]=='E'){

                ar[in1][in2][1] = false;
            }

            if(in3[0]=='W'){

                ar[in1][in2-1][1] = false;

            }

            if(in3[0]=='S'){

                ar[in1-1][in2][0] = false;
            }
        }

        printf("%lld\n",f(s1 , s2));
    }
    return 0;
}

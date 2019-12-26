// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int dp[55][1005];

vector<int>v1 , v2;
int w , k;

int f(int i , int ww)
{
    if(i==k)return 0;
    if(dp[i][ww]!=-1)return dp[i][ww];

    int value = f(i+1 , ww);
    if(ww+v1[i]<=w){

        value = max(value , f(i+1 , ww+v1[i])+v2[i]);
    }

    return dp[i][ww] = value;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        memset(dp , -1 , sizeof(dp));
        v1.clear();v2.clear();

        scanf("%d %d",&w , &k);

        for(int i=0;i<k;i++){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);
            v1.push_back(in1);
            v2.push_back(in2);
        }

        printf("Hey stupid robber, you can get %d.\n",f(0 , 0));
    }
    return 0;
}

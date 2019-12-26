// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int dp[105][1005];
int ar[105][105];
int c , s , e , t;
vector<int>v;

int f(int i , int j)
{
    if(j==0){

        for(int i1=0;i1<v.size();i1++){

            if(v[i1]==i)return 0;
        }
        return -1e8;
    }

    if(dp[i][j]!=-1)return dp[i][j];
    dp[i][j] = -1e8;

    int value = -1e8;


    for(int i1=1;i1<=c;i1++){

        value = max(value , f(i1 , j-1)+ar[i][i1]);
    }

    return dp[i][j] = value;
}

int main(void)
{
    while(scanf("%d %d %d %d",&c , &s , &e , &t)==4){

        if(c==0&&s==0&&e==0&&t==0)break;
        memset(dp , -1 , sizeof(dp));

        for(int i=1;i<=c;i++){

            for(int j=1;j<=c;j++){

                scanf("%d",&ar[i][j]);
            }
        }

        v.clear();

        for(int i=0;i<e;i++){

            int in;
            scanf("%d",&in);
            v.push_back(in);
        }

        printf("%d\n",max(0, f(s , t)));
    }
    return 0;
}

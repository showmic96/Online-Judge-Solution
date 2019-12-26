// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int dp[1005][35][350];
int t , w;
int n , total;
vector<int>v1 , v2 , ans;

int f(int time , int i , int j, vector<int>v)
{

    if(j>total){

        ans = v;
        total = j;
    }

    if(i==n)return 0;


    if(dp[time][i][j]!=-1)return dp[time][i][j];

    int value = 0;

    value = f(time , i+1 , j , v);

    if(time-w*v1[i]-2*w*v1[i]>=0){

        vector<int>temp = v;

        temp.push_back(i);

        value = f(time-w*v1[i]-2*w*v1[i] , i+1 , j+v2[i] , temp);
    }

    return dp[time][i][j] = value;
}

int main(void)
{
    bool space = false;

    while(scanf("%d %d",&t ,&w)==2){

        if(space)printf("\n");
        space = true;

        ans.clear();
        v1.clear();
        v2.clear();

        memset(dp , -1 , sizeof(dp));

        scanf("%d",&n);

        for(int i=0;i<n;i++){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);

            v1.push_back(in1);
            v2.push_back(in2);
        }

        vector<int>v;

        total = 0;

        f(t , 0 , 0 , v);

        printf("%d\n",total);
        int si = ans.size();
        printf("%d\n",si);

        for(int i=0;i<si;i++){

            printf("%d %d\n",v1[ans[i]] , v2[ans[i]]);
        }

    }
    return 0;
}

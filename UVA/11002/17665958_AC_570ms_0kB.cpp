// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>v[65];
int dp[65][65][65*100] , n;

int get(int x)
{
    if(x>=0)return x;
    return 64*100+x;
}

int f(int i , int j , int sum)
{
    if(i==2*n-2){

        return min(abs(sum+v[i][j]) , abs(sum-v[i][j]));
    }
    int s = get(sum);

    if(dp[i][j][s]!=-1)return dp[i][j][s];

    int value = 1e9;
    if(i<n-1){

        value = min(value , f(i+1 , j , sum+v[i][j]));
        value = min(value , f(i+1 , j , sum-v[i][j]));
        value = min(value , f(i+1 , j+1 , sum+v[i][j]));
        value = min(value , f(i+1 , j+1 , sum-v[i][j]));
    }
    else{

        if(j>0)value = min(value , f(i+1 , j-1 , sum+v[i][j]));
        if(j>0)value = min(value , f(i+1 , j-1 , sum-v[i][j]));
        if(j!=v[i].size()-1)value = min(value , f(i+1 , j , sum+v[i][j]));
        if(j!=v[i].size()-1)value = min(value , f(i+1 , j , sum-v[i][j]));
    }
    return dp[i][j][s] = value;
}

int main(void)
{
    while(scanf("%d",&n)==1){
        if(!n)break;
        for(int i=0;i<65;i++)v[i].clear();

        for(int i=0;i<n;i++){

            for(int j=0;j<=i;j++){

                int in;
                scanf("%d",&in);
                v[i].emplace_back(in);
            }
        }

        for(int i=0;i<n-1;i++){

            for(int j=0;j<n-i-1;j++){

                int in;
                scanf("%d",&in);
                v[n+i].emplace_back(in);
            }
        }
        memset(dp , -1 , sizeof(dp));
        printf("%d\n",f(0 , 0 , 0));
    }
    return 0;
}

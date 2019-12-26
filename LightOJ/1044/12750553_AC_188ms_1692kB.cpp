// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int dp[1005] , n;
char ar[1005];

bool pal(int i , int j)
{
    while(i<j){

        if(ar[i]!=ar[j])return false;
        i++;
        j--;
    }

    return true;
}

int f(int i)
{
    if(i==n)return 0;
    if(dp[i]!=-1)return dp[i];

    int value = 1e9;

    for(int i1=i;i1<n;i1++){

        if(pal(i , i1)){

            value = min(value , f(i1+1)+1);
        }
    }

    return dp[i] = value;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        memset(dp , -1 , sizeof(dp));

        scanf("%s",&ar);
        n = strlen(ar);

        printf("Case %d: %d\n",++c , f(0));
    }
    return 0;
}

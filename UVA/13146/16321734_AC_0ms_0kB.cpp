// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char a[105] , b[105];
int dp[105][105] , s1 , s2;

int f(int i , int j)
{
    if(j==s2){
        return s1-i;
    }
    if(i==s1){

        return s2-j;
    }

    if(dp[i][j]!=-1)return dp[i][j];
    int value = 1e9;

    if(a[i]==b[j]){

        value = min(value , f(i+1 , j+1));
        value = min(value , f(i+1 , j)+1);
        value = min(value , f(i , j+1)+1);
    }
    else{

        value = min(value , f(i+1 , j+1)+1);
        value = min(value , f(i+1 , j)+1);
        value = min(value , f(i , j+1)+1);
    }
    return dp[i][j] = value;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    getchar();

    while(t--){

        gets(a);
        gets(b);
        s1 = strlen(a) , s2 = strlen(b);

        memset(dp , -1 , sizeof(dp));
        printf("%d\n",f(0 , 0));
    }
    return 0;
}

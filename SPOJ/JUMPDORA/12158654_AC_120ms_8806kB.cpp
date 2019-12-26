// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1110;

int dp[MAX][MAX];
char ar[MAX+9][MAX+9];
int n , m;

int f(int i , int j)
{
    if(i==n-1&&j==m-1)return 0;
    if(i>=n||j>=m)return 1234567;
    if(i<0||j<0)return 1234567;

    if(ar[i][j]=='#')return 1234567;

    if(dp[i][j]!=-1)return dp[i][j];

    int value = INT_MAX;

    value = min(value , f(i+1 , j)+1);
    value = min(value , f(i , j+1)+1);

    if(ar[i][j]!='0'){

        value = min(value , f(i+1+ar[i][j]-'0' , j)+1);
        value = min(value , f(i , j+1+ar[i][j]-'0')+1);
    }

    return dp[i][j] = value;
}

int main(void)
{
    int t;
    scanf("%d",&t);

    while(t--){

        memset(dp , -1 , sizeof(dp));

        scanf("%d %d",&n , &m);

        for(int i=0;i<n;i++){

            scanf("%s",&ar[i]);
        }
        
        int ans = f(0 , 0);
        if(ans>12345) ans = -1;
        
        printf("%d\n",ans);
    }

    return 0;
}

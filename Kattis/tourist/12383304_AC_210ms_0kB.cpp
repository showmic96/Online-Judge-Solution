// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int dp[105][105][105];
int n , m;
string ar[105];
char x[105];

int f(int r1 , int c1 , int r2 , int c2)
{
    if(r1>=n||r2>=n||c1>=m||c2>=m)return -123456;

    if(r1==n-1&&c1==m-1){
        if(ar[r1][c1]=='*')return 1;
        return 0;
    }

    if(ar[r1][c1]=='#'||ar[r2][c2]=='#')return -123456;

    if(dp[r1][c1][r2]!=-1)return dp[r1][c1][r2];

    int value = -123456;

    value = max(value , f(r1+1 , c1 , r2+1 , c2));
    value = max(value , f(r1+1 , c1 , r2 , c2+1));
    value = max(value , f(r1 , c1+1 , r2+1 , c2));
    value = max(value , f(r1 , c1+1 , r2 , c2+1));

    int temp = 0;
    if(ar[r1][c1]=='*')temp++;
    if(r1!=r2&&c1!=c2)if(ar[r2][c2]=='*')temp++;

    return dp[r1][c1][r2] = value+temp;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        memset(dp , -1 , sizeof(dp));

        scanf("%d %d",&m , &n);

        for(int i=0;i<n;i++){

            scanf("%s",&x);
            string t(x);
            ar[i] = t;
        }

        int temp = 0;
        if(ar[0][0]=='*')temp = 1;

        printf("%d\n", f(0 , 0 , 0 , 0));
    }
    return 0;
}

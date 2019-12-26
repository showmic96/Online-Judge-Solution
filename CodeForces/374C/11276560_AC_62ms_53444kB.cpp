// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e3;

string ar[MAX+9];

int n , m;
ll dp[MAX][MAX][5];

ll f(int i , int j , int c)
{
    if(i>=n||j>=m)return 0;
    if(i<0||j<0)return 0;

    if(c==0&&ar[i][j]!='D')return 0;
    if(c==1&&ar[i][j]!='I')return 0;
    if(c==2&&ar[i][j]!='M')return 0;
    if(c==3&&ar[i][j]!='A')return 0;

    if(dp[i][j][c] == -2)return 1e18;

    if(dp[i][j][c]!=-1)return dp[i][j][c];

    dp[i][j][c] = -2;

    ll value = 0;

    //if(c==3)value++;

    value = max(value , f(i+1 , j , (c+1)%4));
    value = max(value , f(i-1 , j , (c+1)%4));
    value = max(value , f(i , j+1 , (c+1)%4));
    value = max(value , f(i , j-1 , (c+1)%4));

    if(c==3)value++;

    return dp[i][j][c] = value;
}

int main(void)
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(dp , -1 , sizeof(dp));

    cin >> n >> m;

    for(int i=0;i<n;i++)cin >> ar[i];

    ll ans = 0;

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            if(ar[i][j] == 'D'){

                ans = max(ans , f(i , j , 0));
                //cout << i << " " << j << " " << ans << endl;
                //return 0;

            }
        }
    }

    if(ans>1e6)printf("Poor Inna!\n");
    else if(ans==0)printf("Poor Dima!\n");
    else printf("%lld\n",ans);

    return 0;
}

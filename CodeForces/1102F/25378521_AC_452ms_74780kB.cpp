// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1e4+9;
int dp[(1<<16)+5][17][17] , ar[16][MAX] , dif[16][16];
int n , m;

int Set(int n , int pos)
{
    return n|(1<<pos);
}
bool Check(int n , int pos)
{
    return n&(1<<pos);
}

int f(int mask , int i , int j)
{
    if(mask==(1<<n)-1){
        int ans = 1e9;
        for(int k=0;k<m-1;k++){
            ans = min(ans , abs(ar[j][k]-ar[i][k+1]));
        }
        return ans;
    }
    if(dp[mask][i][j]!=-1)return dp[mask][i][j];
    int ans = 0;
    for(int k=0;k<n;k++){
        if(Check(mask, k)==false){
            ans = max(ans , min(dif[j][k] , f(Set(mask , k) , i , k)));
        }
    }
    return dp[mask][i][j] = ans;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> ar[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int d = 1e9;
            for(int k=0;k<m;k++){
                d = min(d , abs(ar[i][k]-ar[j][k]));
            }
            dif[i][j] = d;
        }
    }
    memset(dp , -1 , sizeof(dp));
    int ans = 0;
    for(int i=0;i<n;i++){
        ans = max(ans , f(Set(0 , i) , i , i));
    }
    cout << ans << endl;

    return 0;
}

// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 105;
ll dp[MAX+9][MAX+9];
ll MOD = 1000007;
int n;

string ar[105];

ll f(int i , int j)
{
    if(i<0||j<0)return 0;
    if(i>=n||j>=n)return 0;
    if(ar[i][j]=='B')return 0;
    if(i==0)return 1;

    if(dp[i][j]!=-1)return dp[i][j];

    ll value = 0;

    if(i-1>=0){

        if(j+1<n){

            if(ar[i-1][j+1]=='B')value+=f(i-2 , j+2);
            else value+=f(i-1 , j+1);
        }
        if(j-1>=0){

            if(ar[i-1][j-1]=='B')value+=f(i-2 , j-2);
            else value+=f(i-1 , j-1);
        }
    }

    return dp[i][j] = value%MOD;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t , c = 0;
    cin >> t;
    while(t--){

        memset(dp , -1 , sizeof(dp));
        cin >> n;

        for(int i=0;i<n;i++)cin >> ar[i];

        ll ans = 0;

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                if(ar[i][j]=='W')ans = f(i , j);
            }
        }

        cout << "Case " << ++c << ": " << ans << endl;
    }
    return 0;
}

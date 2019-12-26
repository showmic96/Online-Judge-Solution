// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6;
const ll INF = 12345678910111213;
ll cost[MAX+9];
string ar[MAX+9];
ll dp[MAX+9][2];
int n;

ll f(int i , int pre)
{

    if(i==n){

        return 0;
    }

    ll value1 = 0 , value2 = 0;

    if(dp[i][pre]!=-1)return dp[i][pre];

    if(i==0){

        value1 = f(i+1 , 0);
        value2 = f(i+1 , 1)+cost[i];
    }

    else if(pre==0){

        if(ar[i]>=ar[i-1]){

            value1 = f(i+1 , 0);
        }

        else value1 = INF;

        string temp = ar[i];
        reverse(temp.begin(), temp.end());

        if(temp>=ar[i-1]){

            value2 = f(i+1 , 1) + cost[i];
        }

        else value2 = INF;
    }

    else if(pre==1){

        string t = ar[i-1];
        reverse(t.begin() , t.end());

        if(ar[i]>=t){

            value1 = f(i+1 , 0);
        }

        else value1 = INF;

        string temp = ar[i];
        reverse(temp.begin(), temp.end());

        if(temp>=t){

            value2 = f(i+1 , 1) + cost[i];
        }

        else value2 = INF;
    }

    return dp[i][pre] = min(value1 , value2);
}



int main(void)
{
    memset(dp , -1 , sizeof(dp));

    cin >> n;

    for(int i=0;i<n;i++)cin >> cost[i];
    for(int i=0;i<n;i++)cin >> ar[i];

    ll ans = f(0 , 0);

    if(ans==INF)cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}

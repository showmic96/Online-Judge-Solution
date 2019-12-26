// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[5005];

ll f(int i)
{
    if(i==1)return 2;
    if(i==2)return 3;
    if(dp[i]!=-1)return dp[i];
    return dp[i] = f(i-1)+f(i-2);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    memset(dp , -1 , sizeof(dp));

    int t , c = 0;
    cin >> t;
    while(t--){

        int n;
        cin >> n;

        cout << "Scenario #" << ++c << ":" << endl << f(n) << endl;
        cout << endl;
    }

    return 0;
}

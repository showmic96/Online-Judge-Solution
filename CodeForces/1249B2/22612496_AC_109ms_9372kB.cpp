// In the name of Allah the Lord of the Worlds.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 2e5+9;
ll dp[MAX] , ar[MAX];
int len = 1;
void f(int now)
{
    if(dp[now]!=-1){
        dp[now] = len;
        return ;
    }
    dp[now] = 1;
    len++;
    f(ar[now]);
    dp[now] = len;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> ar[i];
            dp[i] = -1;
        }
        for(int i=1;i<=n;i++){
            if(i>1)cout << " ";
            if(dp[i]==-1)len = 0 , f(i);
            cout << dp[i];
        }
        cout << endl;
    }

    return 0;
}

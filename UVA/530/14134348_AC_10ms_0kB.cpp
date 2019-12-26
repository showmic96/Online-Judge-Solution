// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[5005][5005];

ll f(int i , int j)
{
    if(i==j)return 1;
    if(j==0)return 1;
    if(j==1)return i;

    if(dp[i][j]!=-1)return dp[i][j];
    return dp[i][j] = f(i-1 , j) + f(i-1 , j-1);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    memset(dp , -1 , sizeof(dp));

    int n , m;
    while(cin >> n >> m){

        if(n==0&&m==0)break;
        int temp = n-m;
        m = min(temp , m);

        if(m==2){

            ll t1 = n , t2 = n-1;
            if(t1%2==0)t1/=2;
            else t2/=2;

            t1 = t1*t2;
            cout << t1 << endl;
        }

        else cout << f(n , m) << endl;
    }

    return 0;
}

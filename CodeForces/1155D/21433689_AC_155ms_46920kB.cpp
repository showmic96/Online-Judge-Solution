// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX = 3e5+9;
ll dp[MAX][3][3] , n , x;
ll v[MAX];

ll f(int i , int n1 , int n2)
{
    if(i==n)return 0;
    if(dp[i][n1][n2]!=-1)return dp[i][n1][n2];
    ll value = 0;
    if(n1==0){
        value = max(value , f(i+1 , n1 , n2));
        value = max(value , f(i+1 , 1 , n2)+v[i]);
        value = max(value , f(i+1 , 1 , 1)+v[i]*x);
    }
    if(n1==1){
        if(n2==0){
            value = max(value , f(i+1 , 2 , n2));
            value = max(value , f(i+1 , 2 , n2)+v[i]);
            value = max(value , f(i+1 , 1 , n2)+v[i]);
            value = max(value , f(i+1 , 1 , 1)+v[i]*x);
        }
        if(n2==1){
            value = max(value , f(i+1 , n1 , n2)+v[i]*x);
            value = max(value , f(i+1 , n1 , 2)+v[i]);
            value = max(value , f(i+1 , 2 , 2)+v[i]*x);
            value = max(value , f(i+1 , 2 , 2)+v[i]);
            value = max(value , f(i+1 , 2 , 2));

        }
        if(n2==2){
            value = max(value , f(i+1 , n1 , n2)+v[i]);
            value = max(value , f(i+1 , 2 , n2)+v[i]);
            value = max(value , f(i+1 , 2 , n2));
        }
    }
    if(n1==2){
        value = max(value , f(i+1 , n1 , n2));
    }
    return dp[i][n1][n2] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> x;
    for(int i=0;i<n;i++)cin >> v[i];
    memset(dp , -1 , sizeof(dp));
    cout << f(0 , 0 , 0) << endl;

    return 0;
}

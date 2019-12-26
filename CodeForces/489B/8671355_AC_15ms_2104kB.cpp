// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int n , m;
int dp [123][123];
int boys[123] , girls[123];

int f(int i , int j)
{
    if(i>=n||j>=m)return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    int value1 = 0  , value2 = 0;

    if(abs(boys[i]-girls[j])<=1){

        value1 = f(i+1 , j+1) + 1;
    }

    else{

        value1 = f(i+1 , j);
        value2 = f(i , j+1);
    }

    return dp[i][j] = max(value1 , value2);
}

int main(void)
{
    memset(dp , -1 , sizeof(dp));
    cin >> n;
    for(int i=0;i<n;i++)cin >> boys[i];
    cin >> m;
    for(int i=0;i<m;i++)cin >> girls[i];

    sort(boys , boys+n);
    sort(girls , girls+m);

    cout << f(0 , 0) << endl;
    return 0;
}

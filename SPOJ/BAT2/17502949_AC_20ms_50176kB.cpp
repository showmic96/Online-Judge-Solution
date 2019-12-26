// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 205;

int n , dp[MAX][MAX][MAX];
vector<int>v(MAX);

int f(int i , int j , int k)
{
    if(i==n)return 0;
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    int value = f(i+1 , j , k);

    if(v[i]<v[j])value = max(value , f(i+1 , i , k)+1);
    if(v[i]>v[k])value = max(value , f(i+1 , j , i)+1);

    return dp[i][j][k] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    v[0] = -1e9;
    v[1] = 1e9;

    while(t--){

        cin >> n;
        for(int i=0;i<n;i++)cin >> v[i+2];
        n+=2;

        memset(dp , -1 , sizeof(dp));
        cout << f(2 , 1 , 0) << endl;
    }

    return 0;
}

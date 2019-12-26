// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 105;
int dp[MAX][MAX][MAX];
int n , si1 , si2;
string s1 , s2;

int f(int i , int j , int k)
{
    if(i==si1||j==si2){

        if(k==n)return 0;
        return -1e9;
    }
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    int value = f(i+1 , j , k);
    value = max(value , f(i , j+1 , k));

    if(s1[i]==s2[j])value = max(value , f(i+1 , j+1 , k+1)+s1[i]);

    return dp[i][j][k] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){

        cin >> s1 >> s2;
        cin >> n;

        si1 = s1.size() , si2 = s2.size();
        memset(dp , -1 , sizeof(dp));

        int ans = f(0 , 0 , 0);
        if(ans<0)ans = 0;

        cout << ans << endl;
    }

    return 0;
}

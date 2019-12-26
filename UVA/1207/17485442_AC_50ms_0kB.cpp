// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 5005;
int dp[MAX][MAX];

string s1 , s2;
int n , m;

int f(int i , int j)
{
    if(i==n)return m-j;
    if(j==m)return n-i;

    if(dp[i][j]!=-1)return dp[i][j];

    int value = 1e9;
    if(s1[i]==s2[j])value = min(value , f(i+1 , j+1));
    value = min(value , f(i+1 , j)+1);
    value = min(value , f(i , j+1)+1);
    value = min(value , f(i+1 , j+1)+1);

    return dp[i][j] = value;
}

int main(void)
{
    while(cin >> n >> s1 >> m >> s2){

        memset(dp , -1 , sizeof(dp));
        cout << f(0 , 0) << endl;
    }

    return 0;
}

// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 2005;
int n , m , ar[26];
int dp[MAX][MAX];
string s1 , s2;

int f(int i , int j)
{
    if(i>=n||j>=m)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int value = f(i+1 , j);
    value = max(value , f(i , j+1));
    if(s1[i]==s2[j])value = max(value , f(i+1 , j+1)+ar[s1[i]-'a']);
    return dp[i][j] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for(int i=0;i<26;i++)cin >> ar[i];
    cin >> s1 >> s2;

    memset(dp , -1 , sizeof(dp));
    cout << f(0 , 0) << endl;

    return 0;
}

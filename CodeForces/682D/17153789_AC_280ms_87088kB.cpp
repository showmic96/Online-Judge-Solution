// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e3+5;
int dp[MAX][MAX][11][2];
string s , t;
int n , m , k;

int f(int i , int j , int l , int yn)
{
    if(l>k)return -1e7;
    if(i>=n||j>=m){

        if(l==k&&yn==0)return 0;
        return -1e7;
    }

    if(dp[i][j][l][yn]!=-1)return dp[i][j][l][yn];

    int value = -1e7;

    if(yn==1){

        if(s[i]!=t[j])return -1e7;
        value = max(value , f(i+1 , j+1 , l , 0)+1);
        value = max(value , f(i+1 , j+1 , l , 1)+1);
    }
    else{

        value = max(value , f(i+1 , j , l , 0));
        value = max(value , f(i , j+1 , l , 0));

        if(s[i]==t[j]){

            value = max(value , f(i+1 , j+1 , l+1 , 1)+1);
            value = max(value , f(i+1 , j+1 , l+1 , 0)+1);
        }
    }

    return dp[i][j][l][yn] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> k;
    memset(dp , -1 , sizeof(dp));
    cin >> s >> t;

    cout << f(0 , 0 , 0 , 0) << endl;

    return 0;
}

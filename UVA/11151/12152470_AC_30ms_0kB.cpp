// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1000+9;

int dp[MAX+9][MAX+9];

string ar;

int f(int i , int j)
{
    if(i==j)return 1;
    if(i>j)return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    int value = 0;

    value = max(value , f(i+1 , j));
    value = max(value , f(i , j-1));

    if(ar[i]==ar[j])value = max(value , f(i+1 , j-1)+2);

    return dp[i][j] = value;
}

int main(void)
{
    int t;
    cin >> t;
    getchar();

    while(t--){

        memset(dp , -1 , sizeof(dp));

        getline(cin , ar);

        printf("%d\n",f(0 , ar.size()-1));
    }
    return 0;
}

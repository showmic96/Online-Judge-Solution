// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 60+9;
ll dp[MAX+9][MAX+9];

string ar;

ll f(int i , int j)
{
    if(i>j)return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    ll value = 0;

    value += f(i+1 , j);
    value += f(i , j-1);
    value -= f(i+1 , j-1);

    if(ar[i]==ar[j])value += f(i+1 , j-1)+1;

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

        printf("%lld\n",f(0 , ar.size()-1));
    }
    return 0;
}

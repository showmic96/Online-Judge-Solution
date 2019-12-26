// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int n , dp[111];
string ar;

int f(int i)
{

    if(dp[i]!=-1)return dp[i];

    if(i>=n)return 0;

    int v1=1e9 , v2=1e9 , v3 = 1e9;

    if(ar[i]=='.'){

        v1 = f(i+2) + 1;
        v2 = f(i+3) + 1;
    }

    else{

        v1 = f(i+1);
        v2 = f(i+2) + 1;
    }

    return dp[i] = min(v1 , v2);
}

int main(void)
{
    int t;
    cin >> t;
    int c = 0;

    while(t--){

        memset(dp , -1 , sizeof(dp));
        cin >> n;
        cin >> ar;
        printf("Case %d: ",++c);
        cout << min(f(0),f(1)+1) << endl;
    }

    return 0;
}

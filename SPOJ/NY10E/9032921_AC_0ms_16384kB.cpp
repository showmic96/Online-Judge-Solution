  // In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

ll dp[1234][10];

ll f(int i , int last)
{   //cout << "value of i " << i << endl;
    if(i==n){return 1;}

    if(dp[i][last]!=-1)return dp[i][last];
//cout << "YUE";
    ll value = 0;

    for(int j=0;j<=9;j++){
//cout << "yes";
        if(last<=j)value+=f(i+1 , j);
    }

    return dp[i][last] = value;
}

int main(void)
{
    int t;
    cin >> t;

    while(t--){

        int i;

        memset(dp , -1 , sizeof(dp));

        cin >> i >> n;

        cout << i << " " << f(0 , 0) << endl;
    }

    return 0;
}

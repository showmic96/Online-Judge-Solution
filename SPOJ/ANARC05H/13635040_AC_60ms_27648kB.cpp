// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string ar;
ll dp[25][250][250];

ll f(int i , int sum , int pre)
{
    if(i==ar.size()){

        if(sum<=pre)return 1;
        return 0;
    }

    if(dp[i][sum][pre]!=-1)return dp[i][sum][pre];
    ll value = 0;

    if(sum+ar[i]-'0'<=pre){

        value+=f(i+1 , 0 , sum+ar[i]-'0');
        value+=f(i+1 , sum+ar[i]-'0' , pre);
    }

    return dp[i][sum][pre] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int c = 0;

    while(cin >> ar){

        if(ar=="bye")break;
        reverse(ar.begin() , ar.end());

        memset(dp , -1 , sizeof(dp));

        cout << ++c << ". " << f(0 , 0 , 249)/2 << endl;
    }

    return 0;
}

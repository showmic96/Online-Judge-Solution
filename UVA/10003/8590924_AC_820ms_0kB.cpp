// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int n;

int ar[111];

bool taken[111];

int dp[1111][1111];

int f(int l , int r)
{
    if(dp[l][r]!=-1){return dp[l][r];}
    int ans = 1111111;

    bool check = false;

    for(int i=0;i<n;i++){

        int temp = 0;

        if((ar[i]>l && ar[i]<r)){

            temp = r-l;

            temp += f(ar[i] , r);
            temp += f(l , ar[i]);
            check = true;
            ans = min(ans , temp);
        }

    }

    if(check==false)return dp[l][r] = 0;

    return dp[l][r] = ans;
}

int main(void)
{
    int l;
    while(cin >> l){

        if(!l)break;
        memset(taken , false , sizeof(taken));
        memset(dp , -1 , sizeof(dp));
        cin >> n;

        for(int i=0;i<n;i++)cin >> ar[i];

        cout << "The minimum cutting is " << f(0 , l) << "." << endl;
    }
    return 0;
}

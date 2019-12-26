// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

bool check;

int n , k , ar[12345];
int dp[12345][123];

int f(int i , int value)
{
    value = (value+k)%k;

    if(i==n){

        if(value%k==0)return 1;
        return 0;
    }

    if(dp[i][value]!=-1)return dp[i][value];

    int temp1 = f(i+1 , value+ar[i]);
    int temp2 = f(i+1 , value-ar[i]);

    return dp[i][value] = max(temp1 , temp2);
}

int main(void)
{
    int t;
    cin >> t;
    while(t--){

        memset(dp , -1 , sizeof(dp));

        cin >> n >> k;

        for(int i=0;i<n;i++){

            cin >> ar[i];
        }

        if(f(1 , ar[0])==0)cout << "Not divisible" << endl;
        else cout << "Divisible" << endl;
    }
    return 0;
}

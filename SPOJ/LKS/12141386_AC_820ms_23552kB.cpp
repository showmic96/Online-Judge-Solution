// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

vector<int>v1 , v2;

int dp[2000000+5];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k , n;
    cin >> k >> n;

    memset(dp , 0 , sizeof(dp));

    for(int i=0;i<n;i++){

        int in1 , in2;
        cin >> in1 >> in2;
        v1.push_back(in1);
        v2.push_back(in2);
    }

    for(int i=0;i<n;i++){

        for(int j=k;j>=v2[i];j--){

            dp[j] = max(dp[j] , v1[i]+dp[j-v2[i]]);
        }
    }

    cout << dp[k] << endl;

    return 0;
}

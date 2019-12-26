// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int dp[100][211][211];

int n;
vector<int>v1 , v2;

int f(int i , int j , int k)
{
    if(k>210)return 1e9;
    if(i==n){

        if(k>j)return 1e9;
        return j;
    }

    if(dp[i][j][k]!=-1)return dp[i][j][k];

    int value = 1e9;

    value = min(value , f(i+1 , j+v1[i] , k));
    value = min(value , f(i+1 , j , k+v2[i]));

    return dp[i][j][k] = value;
}

int main(void)
{
    memset(dp , -1 , sizeof(dp));

    cin >> n;

    for(int i=0;i<n;i++){

        int in1 , in2;
        cin >> in1 >> in2;
        v1.push_back(in1);
        v2.push_back(in2);
    }

    cout << f(0 , 0 , 0) << endl;

    return 0;
}

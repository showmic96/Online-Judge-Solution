// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 5005;

int n , dp[MAX][MAX][3];
vector<int>v(MAX);

int f(int i , int last , int now)
{
    if(i==n)return 0;
    if(dp[i][last][now]!=-1)return dp[i][last][now];

    int value = f(i+1 , last , now);

    if(now==2){

        if(v[i]<0)value = max(value , f(i+1 , i , 0)+1);
        else value = max(value , f(i+1 , i , 1)+1);
    }
    if(now==0){

        if(v[i]>0&&abs(v[i])>abs(v[last]))value = max(value , f(i+1 , i , 1)+1);
    }
    if(now==1){

        if(v[i]<0&&abs(v[i])>abs(v[last]))value = max(value , f(i+1 , i , 0)+1);
    }

    return dp[i][last][now] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)cin >> v[i];

    memset(dp , -1 , sizeof(dp));
    cout << f(0 , 0 , 2) << endl;

    return 0;
}

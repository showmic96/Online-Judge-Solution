// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int n , m , x , y;
string ar[1005];
vector<int>v;

int dp[1005][1005][3];

int f(int i , int j , int k)
{
    if(i==m){

        if(j>=x&&j<=y)return 0;
        return 123456789;
    }

    if(dp[i][j][k]!=-1)return dp[i][j][k];

    int value = 123456789;

    if(k==2){

        value = min(value , f(i+1 , j+1 , 0) + v[i]);
        value = min(value , f(i+1 , j+1 , 1) + n-v[i]);
    }

    else if(j<x){

        if(k==0)value = min(value , f(i+1 , j+1 , 0) + v[i]);
        else value = min(value , f(i+1 , j+1 , 1) + n-v[i]);
    }

    else if(j>=x&&j<=y){

        if(k==0){

            if(j!=y)value = min(value , f(i+1 , j+1 , 0) + v[i]);
            value = min(value , f(i+1 , 1 , 1) + n - v[i]);
        }

        else{

            value = min(value , f(i+1 , 1 , 0) + v[i]);
            if(j!=y)value = min(value , f(i+1 ,j+1, 1) + n - v[i]);
        }
    }

    return dp[i][j][k] = value;
}

int main (void)
{
    cin >> n >> m >> x >> y;

    for(int i=0;i<n;i++)cin >> ar[i];

    for(int i=0;i<m;i++){

        int counter = 0;

        for(int j=0;j<n;j++){

            if(ar[j][i]=='#')counter++;
        }

        v.push_back(counter);

    }

    memset(dp , -1 , sizeof(dp));

    cout << f(0 , 0 , 2) << endl;

    return 0;
}

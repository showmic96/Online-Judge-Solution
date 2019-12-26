// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 209;

string ar[MAX+9];
int dp[MAX+9][MAX+9][2];
int n , m;

int f(int i , int j , int d)
{

    if(j==m||i==n)return 0;
    if(j==-1)return 0;
    int value = 0 , temp = 0;
    if(ar[i][j]=='#')return 0;
    if(ar[i][j]=='T')temp = 1;

    if(dp[i][j][d]!=-1)return dp[i][j][d];

    if(d==0){

        value = f(i , j+1 , d) + temp;
        value = max(value , f(i+1 , j , 1)+temp);
    }

    else{

        value = f(i , j-1 , d) + temp;
        value = max(value , f(i+1 , j , 0)+temp);
    }

    return dp[i][j][d] = value;
}

int main(void)
{
    int t;
    cin >> t;
    while(t--){

        memset(dp , -1 , sizeof(dp));

        cin >> n >> m;

        for(int i=0;i<n;i++)cin >> ar[i];

        cout << max(0, f(0 , 0 , 0)) << endl;
    }
    return 0;
}

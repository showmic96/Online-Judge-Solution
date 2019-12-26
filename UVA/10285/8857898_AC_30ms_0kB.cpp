// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 123;
int ar[MAX][MAX];
int dp[MAX][MAX][MAX];
int n , m , c = 0;

int f(int i , int j , int value)
{
    //cout << i << " " << j << " " << value << endl;
    if(i==n)return 0;
    if(j==m)return 0;
    if(i==-1)return 0;
    if(j==-1)return 0;
    //if(c==200)return 0;c++;
    if(value<=ar[i][j])return 0;

    if(dp[i][j][value]!=-1)return dp[i][j][value];

    int v1 = 0 , v2 = 0 , v3 = 0 , v4 = 0;

    v1 = f(i+1 ,j , ar[i][j]) + 1;
    v2 = f(i-1 , j , ar[i][j]) + 1;
    v3 = f(i , j+1 , ar[i][j]) + 1;
    v4 = f(i , j-1 , ar[i][j]) + 1;

    return dp[i][j][value] = max(v1 , max(v2 , max(v3 , v4)));
}

int main(void)
{
    int t;
    cin >> t;
    while(t--){

        memset(dp , -1 , sizeof(dp));

        string name;
        cin >> name;
        cin >> n >> m;

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++)cin >> ar[i][j];
        }

        int mx = 0;

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                mx = max(mx , f(i , j , 123));
            }
        }

        cout << name << ": " << mx << endl;
    }
    return 0;
}

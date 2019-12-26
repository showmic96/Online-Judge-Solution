// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 22;
int ar[MAX][MAX] , dp[MAX][MAX][1005][2] , br[MAX][MAX];
int n , m , k , v[MAX];

int f(int i , int j , int k , int l)
{
    if(j==m){

        i++;
        j = 0;
        l = 0;
    }
    if(i==n){

        return 0;
    }

    if(dp[i][j][k][l]!=-1)return dp[i][j][k][l];

    int value = 0;

    if(l==0){

        if(v[i]<=k)value = max(value , f(i , j , k-v[i] , 1));
        value = max(value , f(i+1 , j , k , 0));
    }
    else{

        if(ar[i][j]<=k)value = max(value , f(i , j , k-ar[i][j] , l)+br[i][j]);
        value = max(value , f(i , j+1 , k , l));
    }

    return dp[i][j][k][l] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){

        cin >> n >> m >> k;
        for(int i=0;i<n;i++)cin >> v[i];
        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                cin >> ar[i][j];
            }
        }

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                cin >> br[i][j];
            }
        }

        memset(dp , -1 , sizeof(dp));
        cout << f(0 , 0 , k , 0) << endl;
    }

    return 0;
}

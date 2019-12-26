// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5+9;
const ll INF = 1234567891011121314;

ll dp[MAX+9][3];
ll ar[MAX+9][3];

void setUp()
{
    for(int i=0;i<MAX;i++){

        for(int j=0;j<3;j++){

            dp[i][j] = -INF;
        }
    }
}

int n ;

ll f(int i , int j)
{

    //cout << i << " " << j << endl;
    if(i==n-1&&j==1){

        return ar[i][j];
    }
    if(i>n)return INF;

    if(dp[i][j]!=-INF)return dp[i][j];

    ll value = INF;

    if(j==0){

        value = f(i+1 ,j) + ar[i][j];

        value = min(value , f(i , j+1) + ar[i][j]);

        value = min(value , f(i+1, j+1) + ar[i][j]);

    }

    if(j==1){

        value = f(i+1 ,j) + ar[i][j];

        value = min(value , f(i , j+1) + ar[i][j]);

        value = min(value , f(i+1, j+1) + ar[i][j]);

        value = min(value , f(i+1, j-1) + ar[i][j]);

    }

    if(j==2){

        value = f(i+1 ,j) + ar[i][j];

        value = min(value , f(i+1, j-1) + ar[i][j]);
    }

    return dp[i][j] = value;
}

int main(void)
{
    int c = 0;
    while(cin >> n){

        if(!n)break;
        setUp();

        for(int i=0;i<n;i++){

            for(int j=0;j<3;++j){

                cin >> ar[i][j];//scanf("%lld",&ar[i][j]);
            }
        }

        cout << ++c << ". " << f( 0 , 1) << endl;
    }
    return 0;
}

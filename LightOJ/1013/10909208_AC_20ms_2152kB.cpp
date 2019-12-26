// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[31][31][62];
ll n1 , n2 , n;
string ar , br;

ll f(int i , int j , int k)
{
    if(i==n1&&j==n2){

        if(k==n)return 1;
        return 0;
    }

    if(dp[i][j][k]!=-1)return dp[i][j][k];

    ll value = 0;

    if(i==n1){

        value+=f(i , j+1 , k+1);
    }

    if(j==n2){

        value+=f(i+1 , j , k+1);
    }

    if(i<n1&&j<n2){

        if(ar[i]==br[j]){

            value+=f(i+1 , j+1 , k+1);
        }
        else{

            value+=f(i+1 , j , k+1);
            value+=f(i , j+1 , k+1);
        }

    }

    return dp[i][j][k] = value;
}

ll f2(int i , int j , int k)
{
    if(i==n1&&j==n2){

        return k;
    }

    if(dp[i][j][k]!=-1)return dp[i][j][k];

    ll value = 123456;

    if(i==n1){

        value=min(value , f2(i , j+1 , k+1));
    }

    if(j==n2){

        value=min(value , f2(i+1 , j , k+1));
    }

    if(i<n1&&j<n2){

        if(ar[i]==br[j]){

            value=min(value , f2(i+1 , j+1 , k+1));
        }
        else{
            value=min(value , f2(i , j+1 , k+1));
            value=min(value , f2(i+1 , j , k+1));
        }

    }

    return dp[i][j][k] = value;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        memset(dp ,-1 , sizeof(dp));

        cin >> ar >> br;

        n1 = ar.size();
        n2 = br.size();

        n = f2(0 , 0 , 0);

        memset(dp , -1 , sizeof(dp));

        printf("Case %d: %lld %lld\n",++c ,(ll)n ,f(0 , 0 , 0));
    }

    return 0;
}

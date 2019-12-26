// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int n;
int dp[123][123][2];
int ar[123];

int f(int l , int r , int w)
{
    //cout << l << " " << r << " " << w << endl;
    if(l>r)return 0;
    if(dp[l][r][w]!=-1)return dp[l][r][w];

    int value1 = INT_MIN , value2 = INT_MIN , value;

    if(w==0){

        int sum = 0;
        for(int j=0;j+l<=r;j++){

            sum+=ar[j+l];

            value1 = max(value1 , f(l+j+1 , r , 1)+sum);

        }
        sum = 0;
        for(int j=0;r-j>=l;j++){

            sum+=ar[r-j];
            value2 = max(value2 , f(l , r-j-1 , 1)+sum);
        }

        value = max(value1 , value2);
    }

    if(w==1){

        value1 = INT_MAX , value2 = INT_MAX;

        int sum = 0;
        for(int j=0;j+l<=r;j++){

            sum-=ar[j+l];

            value1 = min(value1 , f(l+j+1 , r , 0)+sum);

        }
        sum = 0;
        for(int j=0;r-j>=l;j++){

            sum-=ar[r-j];
            value2 = min(value2 , f(l , r-j-1 , 0)+sum);
        }

        value = min(value1 , value2);
    }


    return dp[l][r][w] = value;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){

        memset(dp , -1 , sizeof(dp));

        scanf("%d",&n);

        for(int j=0;j<n;j++){

            scanf("%d",&ar[j]);
        }

        printf("Case %d: %d\n",i+1 , f(0 , n-1 , 0));
    }

    return 0;
}

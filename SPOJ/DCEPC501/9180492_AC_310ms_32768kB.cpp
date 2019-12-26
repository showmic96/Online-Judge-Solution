// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1e5+9;

ll dp[MAX+9][4][3];
ll ar[MAX+9];
int n;

ll f(int i , int h , int w)
{
    //cout << i << " " << h << " " << w << " " << n << endl;
    if(i>=n)return 0;

    if(dp[i][h][w]!=-1)return dp[i][h][w];

    ll value = 0;

    if(w==1){

        value = f(i+1 , 1 , 2) + ar[i];

        if(i+2<=n)value = max(value , f(i+2 , 2 , 2)+ar[i]+ar[i+1]);

        if(i+3<=n)value = max(value , f(i+3 , 3 , 2)+ar[i]+ar[i+1]+ar[i+2]);
    }

    else{

        value = f(i+h , 0 , 1);
    }

    return dp[i][h][w] = value;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        memset(dp , -1 , sizeof(dp));
        scanf("%d",&n);

        for(int i=0;i<n;i++)scanf("%lld",&ar[i]);

        printf("%lld\n",f(0 , 0 , 1));
    }
    return 0;
}

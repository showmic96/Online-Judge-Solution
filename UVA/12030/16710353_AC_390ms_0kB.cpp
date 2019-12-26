#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n , ar[16][16];
ll dp[16][(1<<15)+10][2][2];

bool Check(int n , int pos)
{
    return n&(1<<pos);
}

int Set(int n , int pos)
{
    return n|(1<<pos);
}

ll f(int i , int mask , int umatch , int smatch)
{
    if(i==n){

        if(smatch==1)return 1;
        if(umatch==0)return 1;
        return 0;
    }

    if(dp[i][mask][umatch][smatch]!=-1)return dp[i][mask][umatch][smatch];

    ll value = 0;

    for(int j=0;j<n;j++){

        if(Check(mask , j)==false){

            if(ar[i][j]==0)value+=f(i+1 , Set(mask , j) , 1 , smatch);
            else if(ar[i][j]==1)value+=f(i+1 , Set(mask , j) , umatch , smatch);
            else value+=f(i+1 , Set(mask , j) , umatch , 1);
        }
    }

    return dp[i][mask][umatch][smatch] = value;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        scanf("%d",&n);

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                scanf("%d",&ar[i][j]);
            }
        }

        memset(dp , -1 , sizeof(dp));
        printf("Case %d: %lld\n",++c , f(0 , 0 , 0 , 0));
    }
    return 0;
}
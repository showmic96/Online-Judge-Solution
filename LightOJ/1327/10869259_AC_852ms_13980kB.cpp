// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[16][(1<<15)+5][3];
ll ar[16][16];
int n;

int Set(int n , int pos)
{
    return n|(1<<pos);
}

bool Check(int n , int pos)
{
    return n&(1<<pos);
}

ll f(int i , int mask , int s)
{
    if(i==n){

        if(s==2)return 1;
        if(s==0)return 0;

        bool check = true;

        for(int j=0;j<n;j++){

            if(Check(mask , j)==false)check = false;
        }

        if(check==true)return true;
        return false;
    }

    if(dp[i][mask][s]!=-1)return dp[i][mask][s];

    ll value = 0;

    for(int j=0;j<n;j++){

        if(ar[i][j]==1){

            if(Check(mask , j)==false){

                value+=f(i+1, Set(mask , j), s);
            }
        }

        if(ar[i][j]==2){

            if(Check(mask , j)==false){

                value+=f(i+1 , Set(mask , j) , 2);
            }
        }

        if(ar[i][j]==0){

            if(Check(mask , j)==false){

                if(s==1||s==0)value+=f(i+1 , Set(mask , j), 0);
                else value+=f(i+1 , Set(mask , j), s);
            }
        }
    }

    return dp[i][mask][s] = value;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        memset(dp , -1 , sizeof(dp));

        scanf("%d",&n);

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                scanf("%lld",&ar[i][j]);
            }
        }

        printf("Case %d: %lld\n",++c, f(0 , 0 , 1));
    }
    return 0;
}

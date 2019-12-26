// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char ar[15];
int m , n;
int dp[(1<<10) + 5][1002];

int Set(int n , int pos)
{
    return n|(1<<pos);
}

bool Check(int n , int pos)
{
    return n&(1<<pos);
}

int f(int mask , int mod)
{

    if(mask==(1<<n)-1){

        if(mod==0)return 1;
        return 0;
    }

    if(dp[mask][mod]!=-1)return dp[mask][mod];

    bool taken[10];
    memset(taken , false , sizeof(taken));

    int value = 0;

    for(int i=0;i<n;i++){

        if(Check(mask , i)==false){

            if(taken[ar[i]-'0']==false){

                value+=f(Set(mask, i), (mod*10+ar[i]-'0')%m);
                taken[ar[i]-'0'] = true;
            }
        }
    }

    return dp[mask][mod] = value;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        memset(dp , -1 , sizeof(dp));

        cin >> ar;
        scanf("%d",&m);

        n = strlen(ar);

        printf("Case %d: %d\n",++c , f(0 , 0));
    }

    return 0;
}

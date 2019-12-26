// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[(1<<16)+5][20];
int n , k , si;

string ar;

int Set(int n , int pos)
{
    return n|(1<<pos);
}

bool Check(int n , int pos)
{
    return n&(1<<pos);
}

int get(char x)
{
    if(x>='0'&&x<='9')return x - '0';
    return x-'A'+10;
}

ll f(int mask , int mod)
{
    if(mask==(1<<si)-1){

        if(mod==0)return 1;
        return 0;
    }

    if(dp[mask][mod]!=-1)return dp[mask][mod];

    ll value = 0;

    for(int j=0;j<si;j++){

        if(Check(mask , j)==false){

            value+=f(Set(mask, j), (mod*n+get(ar[j]))%k);
        }
    }

    return dp[mask][mod] = value;
}

int main(void)
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        memset(dp , -1 , sizeof(dp));

        scanf("%d %d",&n , &k);
        cin >> ar;

        si = ar.size();

        printf("Case %d: %lld\n",++c , f(0 , 0));
    }
    return 0;
}

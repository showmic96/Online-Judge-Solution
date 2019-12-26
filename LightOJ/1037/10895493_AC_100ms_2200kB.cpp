// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<ll>v;
string ar[17];

ll dp[(1<<16)+5];

int Set(int n , int pos)
{
    return n|(1<<pos);
}

bool Check(int n , int pos)
{
    return n&(1<<pos);
}

ll f(int mask)
{
    if(mask==(1<<n )- 1){

        return 0;
    }

    if(dp[mask]!=-1)return dp[mask];

    ll value = 1234567891011121314;

    for(int i=0;i<n;i++){

        if(Check(mask , i)==false){

            ll mx = 1;

            for(int j=0;j<n;j++){

                if(Check(mask, j)==true){

                    mx = max(mx , (ll)(ar[j][i]-'0'));
                }
            }

            value=min(value , f(Set(mask , i)) + (ll)(double)ceil(1.00*v[i]/mx));
        }
    }

    return dp[mask] = value;
}

int main(void)
{
    int t, c = 0;
    scanf("%d",&t);

    while(t--){

        v.clear();

        memset(dp , -1 , sizeof(dp));

        scanf("%d",&n);

        for(int i=0;i<n;i++){

            ll in;

            scanf("%lld",&in);
            v.push_back(in);
        }

        for(int i=0;i<n;i++){

            cin >> ar[i];
        }

        printf("Case %d: %lld\n",++c , f(0));
    }
    return 0;
}

// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int Set(int n , int pos)
{
    return n|(1<<pos);
}

bool Check(int n , int pos)
{
    return n&(1<<pos);
}

ll dp[(1<<16)+5];

string ar[16];
string temp;
int n;

ll f(int mask)
{
    if(mask==(1<<n)-1){

        return 1;
    }

    if(dp[mask]!=-1)return dp[mask];

    ll value = 0;

    for(int i=0;i<n;i++){

        if(Check(mask ,i)==false){

            if(temp[i]=='1'){

                value+=f(Set(mask, i));
            }

            else{

                for(int j=0;j<n;j++){

                    if(Check(mask, j)==true){

                        if(ar[j][i]=='1'){

                            value+=f(Set(mask , i));
                            break;
                        }
                    }
                }
            }
        }
    }

    return dp[mask] = value;
}

int main(void)
{

    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        memset(dp , -1 , sizeof(dp));


        scanf("%d",&n);

        cin >> temp;

        for(int i=0;i<n;i++)cin >> ar[i];

        ll value = f(0);

        printf("Case %d: %lld\n",++c , value);
    }

    return 0;
}

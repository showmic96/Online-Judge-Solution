// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[(1<<12) + 5];

int Set(int n , int pos)
{
    return (n|(1<<pos));
}

int reSet(int n , int pos)
{
    return (n&~(1<<pos));
}

bool Check(int n , int pos)
{
    return (n&(1<<pos));
}

ll f(int mask)
{
    if(mask==0)return 0;

    if(dp[mask]!=-1)return dp[mask];

    ll value = 123456789;

    for(int i=0;i<12;i++){

        if(i+2<12){

            if(Check(mask , i)==true&&Check(mask , i+1)==true&&(Check(mask , i+2)==false)){

                int temp = mask;

                temp = Set(temp , i+2);
                temp = reSet(temp , i+1);
                temp = reSet(temp , i);

                value = min(value , f(temp));
            }
        }

        if(i-2>=0){

            if(Check(mask , i)==true&&Check(mask , i-1)==true&&(Check(mask , i-2)==false)){

                int temp = mask;

                temp = Set(temp , i-2);
                temp = reSet(temp , i-1);
                temp = reSet(temp , i);

                value = min(value , f(temp));
            }
        }
    }

    ll counter = 0;

    for(int i=0;i<12;i++){

        if(Check(mask , i)==true)counter++;
    }

    return dp[mask] = min(value , counter);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){

        memset(dp , -1 , sizeof(dp));
        string ar;
        cin >> ar;

        int mask = 0;

        for(int i=0;i<12;i++){

            if(ar[i]=='o'){

                mask = Set(mask , i);
            }
        }

        ll ans = f(mask);

        cout << ans << endl;

    }
    return 0;
}

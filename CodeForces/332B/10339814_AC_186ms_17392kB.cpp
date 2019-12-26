// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[200005][3];
int n , k;
vector<ll>v1 , v2;

ll f(int i , int j)
{
    if(j==2)return 0;

    if(i+k>n)return -1e9;

    if(dp[i][j]!=-1)return dp[i][j];

    ll value = 0;

    if(j==0)value = f(i+k , 1) + v2[i];
    else{

        value = f(i+1 , j);
        value = max(value , f(i+k , 2) + v2[i]);
    }

    return dp[i][j] = value;
}

int main(void)
{
    scanf("%d %d",&n , &k);

    for(int i=0;i<n;i++){

        ll in;
        scanf("%lld",&in);

        v1.push_back(in);
        v2.push_back(0);
    }

    ll sum = 0;

    for(int i=n-1;i>=0;i--){

        sum+=v1[i];

        if(i+k<=n){

            if(i+k==n){

                v2[i] = sum;
            }

            else{

                sum-=v1[i+k];
                v2[i] = sum;
            }
        }
    }

    ll mx = 0 , st1 = 0 , st2 = 0;
    memset(dp , -1 , sizeof(dp));

    for(int i=0;i<n;i++){

        ll value = f(i , 0);

        if(value>mx){

            mx = value;
            st1 = i;
        }
    }

    for(int i=st1+k;i<n;i++){

        if(mx - v2[i]==v2[st1]){

            st2 = i;
            break;
        }
    }

    printf("%lld %lld\n",st1+1 , st2+1);

    return 0;
}

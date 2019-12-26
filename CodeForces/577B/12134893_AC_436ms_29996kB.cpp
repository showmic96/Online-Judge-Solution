// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[1005][1005][2];

vector<ll>v;
bool check = false;
ll n , m;

int f(ll i, ll mod , ll now)
{
    if(i==n){

        if(now==0)return 1;
        if(mod%m==0)check = true;
        return 1;
    }

    if(dp[i][mod][now]!=-1)return dp[i][mod][now];

    int value = 0;

    value = f(i+1 , mod , now);
    value = f(i+1 , (ll)((ll)mod+v[i])%m , 1);

    return dp[i][mod][now] = value;
}

int main(void)
{
    scanf("%lld %lld",&n , &m);

    for(int i=0;i<n;i++){

        ll in;
        scanf("%lld",&in);
        v.push_back(in);
    }

    if(n>m){
        v[0]%=m;
        for(int i=1;i<n;i++){

            v[i] = v[i] + v[i-1];
            v[i]%=m;
        }

        sort(v.begin() , v.end());

        for(int i=0;i<n-1;i++){

            if(v[i]==v[i+1]){

                printf("YES\n");
                return 0;
            }
        }

        printf("NO\n");
    }

    else{

        memset(dp , -1 , sizeof(dp));

        int v = f(0 , 0 , 0);

        if(check==true){

            printf("YES\n");
        }

        else{

            printf("NO\n");
        }
    }

    return 0;
}

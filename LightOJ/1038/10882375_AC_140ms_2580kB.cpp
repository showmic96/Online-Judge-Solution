// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

double dp[100005];
bool visited[100005];

ll n;

double f(ll i)
{
    if(i==1)return 0;

    if(visited[i])return dp[i];
    dp[i] = 0;
    visited[i] = true;

    double value = 0 , counter = 0;

    ll lim = sqrt(i);

    for(ll j=1;j<=lim;j++){

        if(i%j==0){

            if(j*j==i){

                counter++;
                value+= 1 + f(j);
            }
            else{

                counter+=2;
                value+= 2 + f(j) + f(i/j);
            }
        }
    }

    return dp[i] = (double)(value)/(counter-1);
}

int main(void)
{
    int t , c =0;
    scanf("%d", &t);
    while(t--){

        memset(visited , false , sizeof(visited));
        scanf("%lld",&n);

        printf("Case %d: %.14f\n", ++c , f(n));
    }

    return 0;
}

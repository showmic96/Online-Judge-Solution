// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

ll dp[55][55][2];
int n , m;
bool taken[55] , vis[55][55][2];

ll f(int i , int last , int now)
{
    if(i==n)return 1;
    if(vis[i][last][now]==true)return dp[i][last][now];

    vis[i][last][now] = true;

    ll value = 0;

    if(now==0){

        for(int j=1;j<last;j++){

            if(taken[j]==false){

                taken[j] = true;
                value+=f(i+1 , j , 1);
                taken[j] = false;
            }
        }
    }
    else{

        for(int j=last+1;j<=n;j++){

            if(taken[j]==false){

                taken[j] = true;
                value+=f(i+1 , j , 0);
                taken[j] = false;
            }
        }
    }

    return dp[i][last][now] = value;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        memset(vis , false , sizeof(vis));
        memset(taken , false , sizeof(taken));

        scanf("%d %d",&n , &m);

        if(m==1){

            taken[1] = true;
            taken[3] = true;

            printf("Case %d: %llu\n",++c , max((ll)1, f(2 , 3 , 0)));
        }
        else{

            taken[m] = true;

            printf("Case %d: %llu\n",++c , max((ll)1 , f(1 , m , 0)));
        }
    }
    return 0;
}

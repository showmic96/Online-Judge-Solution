#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
ll dp[4][(1<<15)+5][60];
vector<int>v;

bool Check(int n , int pos)
{
    return n&(1<<pos);
}
int Set(int n , int pos)
{
    return n|(1<<pos);
}

ll f(int i, int mask , int sum)
{

    if(dp[i][mask][sum]!=-1)return dp[i][mask][sum];

    ll value = 0;

    if(i==3){

        if(sum>=20){
            value = f(0 , mask , 0) + 1;
        }
        else value = f(0 , mask , 0);
    }
    else{

        for(int j=0;j<n;j++){

            if(Check(mask , j)==false){

                value = max(value , f(i+1 , Set(mask , j) , sum+v[j]));
            }
        }
    }

    return dp[i][mask][sum] = value;
}

int main(void)
{
    int c = 0;
    while(scanf("%d",&n)==1){

        if(n==0)break;
        v.clear();

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            v.push_back(in);
        }

        memset(dp , -1 , sizeof(dp));
        printf("Case %d: %lld\n",++c , f(0 , 0 , 0));
    }
    return 0;
}


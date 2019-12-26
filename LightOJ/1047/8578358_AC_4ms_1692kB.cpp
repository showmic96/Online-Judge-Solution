// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 25;
typedef long long ll;

int n;
ll dp[MAX][MAX];

struct myStruct{

    ll red , green , blue;

}data[MAX+9];

ll f(int i , int pre)
{
    if(i==n)return 0;
    if(dp[i][pre]!=-1)return dp[i][pre];

    ll value1 = 0 , value2 = 0;

    if(pre==1){

        value1 = f(i+1 , 2) + data[i].green;
        value2 = f(i+1 , 3) + data[i].blue;
    }

    if(pre==2){

        value1 = f(i+1 , 1) + data[i].red;
        value2 = f(i+1 , 3) + data[i].blue;
    }

    if(pre==3){

        value1 = f(i+1 , 2) + data[i].green;
        value2 = f(i+1 , 1) + data[i].red;
    }

    return dp[i][pre] = min(value1 , value2);
}


int main(void)
{
    int t;
    scanf("%d" , &t);//cin >> t;
    for(int i=0;i<t;i++){

        memset(dp , -1 , sizeof(dp));
        cin >> n;

        for(int i=0;i<n;i++){

            scanf("%lld",&data[i].red);
            scanf("%lld",&data[i].green);
            scanf("%lld",&data[i].blue);
        }

        ll value = min(f(1 , 1)+data[0].red , min(f(1 , 2)+data[0].green , f(1 , 3)+data[0].blue));

        printf("Case %d: %lld\n",i+1, value);
    }
    return 0;
}

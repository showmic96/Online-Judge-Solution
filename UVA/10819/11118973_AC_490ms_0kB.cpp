// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll m , n;

vector<int>v1 , v2;

ll dp[10205][105][2];

ll f(int w , int i , int b)
{

    if(w>m+200){

        return -1e9;
    }

    if(i==n){

        if(w>2000){

            if(w<=m+200)return 0;
        }

        else if(w<=m)return 0;

        return -1e9;
    }
    if(dp[w][i][b]!=-1)return dp[w][i][b];

    ll value = 0;

    value = f(w+v1[i] , i+1 , b) + v2[i];

    value = max(value , f(w , i+1 , b));

    return dp[w][i][b] = value;
}

int main(void)
{
    while(scanf("%lld %lld",&m , &n)==2){

        v1.clear() , v2.clear();

        memset(dp , -1 , sizeof(dp));

        for(int i=0;i<n;i++){

            int in1 , in2;
            scanf("%d %d",&in1,&in2);
            v1.push_back(in1);
            v2.push_back(in2);
        }

        printf("%lld\n",f(0 , 0 , 0));
    }
    return 0;
}

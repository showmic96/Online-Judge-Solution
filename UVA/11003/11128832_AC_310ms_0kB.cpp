//In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<int>v1 , v2;
ll dp[1005][3009][2];

ll f(int i , int w , int first)
{
    if(i==n)return 0;

    if(dp[i][w][first]!=-1)return dp[i][w][first];

    ll value = 0;

    if(first==0){

        value = f(i+1 ,w , 0);

        value = max(value , f(i+1 , v2[i] , 1)+1);
    }

    else{

        value = f(i+1 , w , first);

        if(w-v1[i]>=0){

            value = max(value , f(i+1 , min(w-v1[i] , v2[i]) , first) + 1);
        }
    }

    return dp[i][w][first] = value;
}

int main(void)
{
    while(scanf("%d",&n)==1){

        if(n==0)break;

        v1.clear() , v2.clear();
        memset(dp , -1 , sizeof(dp));

        for(int i=0;i<n;i++){

            int in1 , in2;
            scanf("%d %d",&in1 ,&in2);

            v1.push_back(in1);
            v2.push_back(in2);
        }

        printf("%lld\n",f(0 , 0 , 0));
    }
    return 0;
}

// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int dp[(1<<20)+5] , n , sum;
vector<int>v;

int Set(int n , int pos)
{
    return n|(1<<pos);
}

bool Check(int n , int pos)
{
    return n&(1<<pos);
}

int f(int mask , int tot)
{
    if(dp[mask]!=-1)return dp[mask];
    if(tot>sum/4)return 0;
    if(tot==sum/4){

        if(mask==(1<<n)-1)return 1;
        tot = 0;
    }

    int value = 0;

    for(int i=0;i<n;i++){

        if(Check(mask , i)==false){

            value = max(value , f(Set(mask , i) , tot+v[i]));
        }
    }

    return dp[mask] = value;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        scanf("%d",&n);
        v.clear();

        sum = 0;
        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            v.emplace_back(in);

            sum+=in;
        }

        if(sum%4)printf("no\n");
        else{

            memset(dp , -1 , sizeof(dp));
            if(f(0 , 0)==1)printf("yes\n");
            else printf("no\n");
        }
    }
    return 0;
}

// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int dp[1005][2005];
ll fib[100];

int main(void)
{
    fib[0] = 1;
    fib[1] = 1;

    for(int i=2;i<100;i++)fib[i] = fib[i-1]+fib[i-2];
    int t;
    scanf("%d",&t);
    while(t--){

        ll n , temp;
        scanf("%lld",&n);

        temp = n;
        string ans = "";

        for(int i=45;i>=1;i--){

            if(fib[i]<=n){

                n-=fib[i];
                ans+="1";
            }
            else if(ans.size()>0)ans+="0";
        }

        printf("%lld = ",temp);
        for(int i=0;i<ans.size();i++)printf("%c",ans[i]);
        printf(" (fib)\n");
    }
    return 0;
}

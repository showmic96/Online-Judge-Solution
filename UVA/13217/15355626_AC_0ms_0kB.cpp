// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

double dp[1005];

int main(void)
{
    dp[0] = 5.5957541127;
    for(int i=1;i<=100;i++)dp[i] = (dp[i-1]*dp[i-1]-5)/(2*dp[i-1]+4);
    string ar;
    while(cin >> ar){

        if(ar=="0")printf("%.10f\n",dp[0]);
        else if(ar=="1")printf("%.10f\n",dp[1]);
        else if(ar=="2")printf("%.10f\n",dp[2]);
        else if((ar[ar.size()-1]-'0')%2==1)printf("%.10f\n",dp[3]);
        else printf("%.10f\n",dp[4]);
    }
    return 0;
}

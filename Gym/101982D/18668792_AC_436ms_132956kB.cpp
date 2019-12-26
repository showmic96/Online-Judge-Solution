// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll MOD = 1000000009;
vector<int>v;
int k , b , dp[130][2][1005][130];

int f(int i , int smaller , int mod , int tot)
{
    if(i==v.size()){
        if(mod==0)return tot;
        return 0;
    }
    if(dp[i][smaller][mod][tot]!=-1)return dp[i][smaller][mod][tot];
    ll value = 0 , lim = v[i];
    if(smaller==1)lim = 1;
    for(int j=0;j<=lim;j++){
        value+=f(i+1 , smaller|(j<lim) , (mod*2+j)%k , tot+(j==1));
    }
    return dp[i][smaller][mod][tot] = value%MOD;
}

int main(void)
{
    scanf("%d %d",&k , &b);
    for(int i=0;i<b;i++)v.push_back(1);
    memset(dp , -1 , sizeof(dp));
    printf("%d\n",f(0 , 0 , 0 , 0));
    return 0;
}

// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ans[10] , dp[11][2][11][11][2];
vector<ll>v;

ll f(int i , int smaller , int now , int tot , int zero)
{
    if(i==v.size())return tot;
    if(dp[i][smaller][now][tot][zero]!=-1)return dp[i][smaller][now][tot][zero];
    int lim = v[i];
    if(smaller==1)lim = 9;
    ll value = 0;
    for(int j=0;j<=lim;j++){
        value+=f(i+1 , smaller|(j<lim) , now , tot+(j==now&&(zero|j>0)) , zero|(j>0));
    }
    return dp[i][smaller][now][tot][zero] = value;
}
void make(ll x)
{
    v.clear();
    while(x){
        v.push_back(x%10);
        x/=10;
    }
    if(v.size()==0)v.push_back(0);
    reverse(v.begin() , v.end());
}
int main(void)
{
    ll a , b;
    while(scanf("%lld %lld",&a , &b)==2){
        if(a==0&&b==0)break;
        if(a>b)swap(a , b);
        memset(ans , 0 , sizeof(ans));
        memset(dp , -1 , sizeof(dp));
        make(b);
        for(int i=0;i<10;i++){
            ans[i]+=f(0 , 0 , i , 0 , 0);
        }
        memset(dp, -1 , sizeof(dp));
        make(a-1);
        for(int i=0;i<10;i++){
            ans[i]-=f(0 , 0 , i , 0 , 0);
        }
        for(int i=0;i<10;i++){
            if(i)printf(" ");
            printf("%lld",ans[i]);
        }
        printf("\n");
    }
    return 0;
}

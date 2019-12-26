// In the name of Allah the Lord of the Worlds.

#include<iostream>
#include<vector>
#include<stdio.h>
#include<queue>
#include<math.h>
#include<algorithm>
using namespace std;

typedef long long ll;
ll dp[1005][1005] , n , m , r;
struct s{
    ll st , en , tot;
    s(ll _st , ll _en , ll _tot){
        st = _st;
        en = _en;
        tot = _tot;
    }
};
vector<s> v;

ll f(int now , int pre)
{
    if(now==m)return 0;
    if(dp[now][pre]!=-1)return dp[now][pre];
    ll value = f(now+1 , pre);
    if(pre==1001){
        value = max(value , f(now+1 , now)+v[now].tot);
    }
    else{
        if(v[pre].en+r<=v[now].st)value = max(value , f(now+1 , now)+v[now].tot);
    }
    return dp[now][pre] = value;
}
bool cmp(s a , s b)
{
    return a.st<b.st;
}

int main(void)
{
    scanf("%lld %lld %lld",&n , &m , &r);
    for(int i=0;i<=1004;i++){
        for(int j=0;j<=1004;j++){
            dp[i][j] = -1;
        }
    }
    for(int i=0;i<m;i++){
        ll in1 , in2 , in3;
        scanf("%lld %lld %lld",&in1 , &in2 , &in3);
        v.push_back(s(in1 , in2 , in3));
    }
    sort(v.begin() , v.end() , cmp);
    printf("%lld\n",f(0 , 1001));
    return 0;
}

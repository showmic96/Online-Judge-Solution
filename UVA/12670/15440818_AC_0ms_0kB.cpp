// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[65][2][65];
vector<int>v;

ll f(int i , int smaller , int l)
{
    if(i==v.size()){

        return l;
    }
    if(dp[i][smaller][l]!=-1)return dp[i][smaller][l];
    int lim = v[i];
    if(smaller==1)lim = 1;

    ll value = 0;

    for(int j=0;j<=lim;j++){

        if(j==lim){

            if(j==1)value+=f(i+1 , smaller , l+1);
            else value+=f(i+1 , smaller , l);
        }
        else{

            if(j==1)value+=f(i+1 , 1 , l+1);
            else value+=f(i+1 , 1 , l);
        }
    }
    return dp[i][smaller][l] = value;
}

void make(ll x)
{
    v.clear();
    while(x){

        v.push_back(x%2);
        x/=2;
    }
    if(v.size()==0)v.push_back(0);
    reverse(v.begin() , v.end());
}

int main(void)
{
    ll a , b;
    while(scanf("%lld %lld",&a , &b)==2){

        make(a-1);
        memset(dp , -1 , sizeof(dp));
        ll ans = f(0 , 0 , 0);

        make(b);
        memset(dp , -1 , sizeof(dp));
        ans = f(0 , 0 , 0)-ans;

        printf("%lld\n",ans);
    }
    return 0;
}

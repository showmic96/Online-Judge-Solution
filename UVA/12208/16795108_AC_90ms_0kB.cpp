// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>v;
ll dp[35][35][2];

void make(ll x)
{
    v.clear();
    while(x){

        v.push_back(x%2);
        x/=2;
    }
    reverse(v.begin() , v.end());
}

ll f(int i , int one , int smaller)
{
    if(i==v.size()){

        return one;
    }
    if(dp[i][one][smaller]!=-1)return dp[i][one][smaller];

    ll value = 0;

    int lim = v[i];
    if(smaller==1)lim = 1;

    for(int j=0;j<=lim;j++){

        if(j==lim){

            if(j==0)value+=f(i+1 , one , smaller);
            else value+=f(i+1 , one+1 , smaller);
        }
        else{

            if(j==0)value+=f(i+1 , one , 1);
            else value+=f(i+1 , one+1 , 1);
        }
    }

    return dp[i][one][smaller] = value;
}

int main(void)
{
    ll l , r;
    int c = 0;

    while(scanf("%lld %lld",&l , &r)==2){

        if(l==0&&r==0)break;

        make(l-1);
        memset(dp , -1 , sizeof(dp));

        ll ans = f(0 , 0 , 0);

        make(r);
        memset(dp , -1 , sizeof(dp));
        ans = f(0 , 0 , 0) - ans;

        printf("Case %d: %lld\n",++c , ans);
    }

    return 0;
}

// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[11][2][3];
vector<int>v;

ll f(int i , int smaller , int mod)
{
    if(i==v.size()){

        return mod;
    }
    if(dp[i][smaller][mod]!=-1)return dp[i][smaller][mod];

    int lim = v[i];
    if(smaller==1)lim = 9;

    ll value = 0;

    for(int j=0;j<=lim;j++){

        if(j==lim){

            value+=f(i+1 ,smaller , (mod+j)%3);
        }
        else{

            value+=f(i+1 , 1 , (mod+j)%3);
        }
    }

    return dp[i][smaller][mod] = value%3;
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
    int t;
    scanf("%d",&t);
    while(t--){

        ll x;
        scanf("%lld",&x);
        make(x);
        memset(dp , -1 , sizeof(dp));

        ll now = f(0 , 0 , 0);

        if(now%3==0)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

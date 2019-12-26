// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[111][2][2][111];
vector<ll>ar;
int si;

ll f(int i , int smaller , int first , int zero)
{

    if(i==si)return zero;

    if(dp[i][smaller][first][zero]!=-1)return dp[i][smaller][first][zero];

    int lim = 9;

    if(smaller==0)lim = ar[i];

    ll value = 0;

    if(first==0){

        for(int j=1;j<=lim;j++){

            if(j<lim)value+=f(i+1 , 1 , 1 , zero);
            else value+=f(i+1 , smaller , 1 , zero);
        }

        value+=f(i+1 , 1 , 0 , 0);
    }

    else{

        for(int j=0;j<=lim;j++){

            if(j==0&&lim==0) value+=f(i+1 , smaller , 1 , zero+1);
            else if(j==0)value+=f(i+1 , 1 ,1 , zero+1);
            else if(j<lim)value+=f(i+1 , 1 , 1 , zero);
            else value+=f(i+1 , smaller , 1 , zero);
        }
    }

    //value+=f(i+1 , 1 , 0 , 0);

    return dp[i][smaller][first][zero] = value;
}

void make(ll a)
{
    ar.clear();

    while(a!=0){

        ar.push_back(a%10);
        a/=10;
    }

    reverse(ar.begin() , ar.end());

    si = ar.size();
}

int main(void)
{
    ll a , b;
    while(scanf("%lld %lld",&a , &b)==2){

        if(a<0&&b<0)break;

        memset(dp , -1 , sizeof(dp));

        make(b);

        ll ans2 = f(0 , 0 , 0 , 0);

        if(a==0){printf("%lld\n",ans2+1);continue;}

        memset(dp , -1 , sizeof(dp));

        make(a-1);

        ll ans1 = f(0 , 0 , 0 , 0);

        printf("%lld\n",ans2-ans1);
    }
    return 0;
}

// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


ll coin[] = {5 , 10 , 20 , 50 , 100 , 200 , 500 , 1000 , 2000 , 5000 , 10000};
ll dp[22][300010];


ll f(ll i , ll w)
{
    //cout << i << " " << w << endl;
    if(i>=11){

        if(w==0)return 1;
        return 0;
    }

    if(dp[i][w]!=-1)return dp[i][w];

    ll p1 = 0 , p2 = 0;

    if(w-coin[i]>=0){

        p1 = f(i , w-coin[i]);
    }

    p2 = f(i+1 , w);

    return dp[i][w] = p1 + p2;


}

int main(void)
{

    double a;

    memset(dp , (ll)-1 , sizeof(dp));

    while(cin >> a){
        if(a==0)break;
        //cout << a*100 << endl;
        ll weight = a*100;
        while(weight%5!=0)weight++;
        ll ans = f((ll)0 , (ll)weight);
        printf("%6.2lf%17lld\n",a , ans);//cout << f(0 , a*100) << endl;;
    }

    return 0;
}

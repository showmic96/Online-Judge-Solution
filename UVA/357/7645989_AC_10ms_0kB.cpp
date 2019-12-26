// In the name of Allah the lord of the worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp[6][30000+10];
ll coin [] = {1, 5 , 10 , 25 , 50};
ll current , make;

ll f(ll i , ll counter)
{
    if(i>=5){
        if(counter==0)return 1;
        return 0;
    }

    if(dp[i][counter]!=-1)return dp[i][counter];

    ll p1 = 0 , p2 = 0;

    if(counter - coin[i]>=0){

        p1 = f(i , counter-coin[i]);
    }

    p2 = f(i+1 , counter);

    return dp[i][counter] = p1 + p2;
}

int main(void)
{
    memset(dp , -1 , sizeof(dp));

    while(cin >> make){

        if(f(0,make)==1){cout << "There is only 1 way to produce "<< make << " cents change." << endl;continue;}
        cout << "There are "<< f(0 , make)  << " ways to produce " << make << " cents change."<< endl;
    }

    return 0;
}

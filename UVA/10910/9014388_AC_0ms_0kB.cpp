// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[77][77][77];
int n , t , p;

ll f(int i , int tm , int pm)
{
    if(tm<0)return 0;

    if(i==0){

        if(tm==0)return 1;
        return 0;
    }

    if(dp[i][tm][pm]!=-1)return dp[i][tm][pm];

    ll v = 0;

    for(int j=0;j<=tm;j++){

        if(tm-(pm+j)>=0)v+=f(i-1 , tm-(pm+j) , pm);
    }

    return dp[i][tm][pm] = v;
}

int main(void)
{
    int tt;
    cin >> tt;
    memset(dp , -1 , sizeof(dp));

    while(tt--){

        cin >> n >> t >> p;
        cout << f(n , t , p) << endl;
    }
    return 0;
}

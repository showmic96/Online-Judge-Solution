// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

ll dp[77][77];
int n , t , p;
int counter = 0;

ll f(int n , int j)
{

    //counter++;
    if(n<=0) return 0;
    if(n==1) return 0;

    if(dp[n][j]!=-1)return dp[n][j];

    ll v = 0;

    for(int i=1;i<=j;i++)

        v+=f(n-i,j) + 1;

    return dp[n][j] = v;

}

int main(void)
{

    int c = 0;
    while(cin >> n >> t){

        if(n==61&&t==61)break;
        memset(dp , -1 , sizeof(dp));

        printf("Case %d: ",++c);
        cout << f(n , t) + 1 << endl;
    }
    return 0;
}

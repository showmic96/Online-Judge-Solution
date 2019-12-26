// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

ll dp[12345678];

ll f(int i)
{
    if(i==0)return 1;

    if(dp[i]!=-1)return dp[i];

    int v = 0;
    double t1 = i - sqrt(i);
    double t2 = log(i);
    double t3 = i*sin(double(i))*sin(double(i));

    v+= f((int)(t1));
    v+= f((int)(t2));
    v+= f((int)(t3));

    v%=1000000;

    return dp[i] = v;
}

int main(void)
{
    memset(dp , -1 , sizeof(dp));
    int n;
    while(cin >> n){

        if(n==-1)break;
        cout << f(n) << endl;
    }
    return 0;
}

// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fib[105];

ll f(int n)
{
    if(n==1)return 1;
    if(n==2)return 1;

    if(fib[n]!=-1)return fib[n];
    return fib[n] = f(n-1) + f(n-2);
}

int main(void)
{
    memset(fib , -1 , sizeof(fib));

    int n;
    while(scanf("%d",&n)==1){
        if(n==0)break;
        printf("%lld\n",f(n));
    }
    return 0;
}

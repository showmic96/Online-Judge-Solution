// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fib[65];

void pre()
{
    fib[1] = 1;
    fib[2] = 1;

    for(int i=3;i<65;i++)fib[i] = fib[i-1]+fib[i-2];
}

void print(string ar)
{
    for(int i=0;i<ar.size();i++)printf("%c",ar[i]);
    printf("\n");
}

int main(void)
{
    pre();
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        ll n;
        scanf("%lld",&n);

        int cur = 0;
        while(fib[cur]<=n)cur++;

        string ar = "";

        ll temp = 0;

        for(int i=cur-1;i>1;i--){

            if(fib[i]+temp<=n){

                ar+='1';
                temp+=fib[i];
            }
            else ar+='0';
        }
        print(ar);
    }
    return 0;
}

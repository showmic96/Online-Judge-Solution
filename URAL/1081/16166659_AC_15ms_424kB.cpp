// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fib[65];

void pre()
{
    fib[1] = 2;
    fib[2] = 3;

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

    ll n , k;
    scanf("%lld %lld",&n,&k);

    string ar = "";

    ll temp = k;

    for(int i=n-1;i>=1;i--){

        if(fib[i]>=k) ar+='0';
        else{

            ar+='1';
            k-=fib[i];
            i--;
            if(i<1)break;
            ar+='0';

        }
    }

    if(temp>fib[n])print("-1\n");
    else {

        if(k==1)ar+="0";
        else ar+="1";
        print(ar);
    }
    return 0;
}

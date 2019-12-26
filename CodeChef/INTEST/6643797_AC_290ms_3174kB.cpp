#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    ll a , b , in , counter = 0;

    scanf("%lld %lld",&a,&b);

    while(a--){

        scanf("%lld",&in);
        if(in%b==0)counter++;
    }
    printf("%lld\n",counter);
    return 0;
}

// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        int a , b;
        scanf("%d %d",&a , &b);

        int gcd = __gcd(a , b);

        printf("%d %d\n",b/gcd , a/gcd);
    }
    return 0;
}

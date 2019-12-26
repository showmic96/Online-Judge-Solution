// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        ll sum = 0;
        int n , m;
        scanf("%d %d",&n , &m);

        for(int i=0;i<n;i++){

            sum+=m-i-1;
        }

        printf("%lld\n",sum);
    }

    return 0;
}

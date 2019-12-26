// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int n , k;
    while(scanf("%d %d",&n , &k)==2){

        double ans = 0;
        for(int i=n-k+1;i<=n;i++){

            ans+=log((double)i)/log(10);
        }

        for(int i=1;i<=k;i++){

            ans-=log((double)i)/log(10);
        }

        printf("%d\n",(int)floor(ans)+1);
    }
    return 0;
}

// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        ll x;
        scanf("%lld",&x);

        int ans = 1;

        for(int i=1;i<=100005;i++){

            for(int j=0;j<35;j++){

                double temp = pow(i , j);

                if((ll)temp==abs(x)){

                    if(x<0&&j%2==0)continue;
                    ans = max(ans , j);
                }

                else if(temp>abs(x))break;
            }

            if(ans!=1)break;
        }

        printf("Case %d: %d\n",++c , ans);
    }
    return 0;
}

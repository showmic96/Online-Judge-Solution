// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll last[105];

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        ll n , ans = 0;
        scanf("%lld",&n);
        memset(last , 0 , sizeof(last));

        for(int i=1;;i++){

            bool check = false;
            for(int j=0;j<n;j++){

                if(last[j]==0){

                    last[j] = i;
                    ans = i;
                    check = true;
                    break;
                }
                else if((double)sqrt(last[j]+i)==(ll)sqrt(last[j]+i)){

                    last[j] = i;
                    ans = i;
                    check = true;
                    break;
                }
            }

            if(check==false)break;
        }

        printf("%lld\n",ans);
    }
    return 0;
}

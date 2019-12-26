// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n , k;
int ar[1234567];

bool is_possible(int x){

    if(x==0)return true;

    ll temp = 0;

    for(int i=0;i<n;i++){

        temp+=ar[i]/x;
    }

    if(temp>=k)return true;
    return false;
}

int main(void)
{
    int t;
    scanf("%d",&t);

    while(t--){

        scanf("%d %d",&n , &k);
        for(int i=0;i<n;i++){

            scanf("%d",&ar[i]);
        }

        sort(ar , ar+n);

        ll hi = ar[n-1] , low = 0 , mid , ans = 0;
        int cc = 200;

        while(cc--){

            mid = (hi+low)/2;

            if(is_possible(mid)==true){

                low = mid+1;
                ans = mid;
            }

            else{

                hi = mid - 1;
            }
        }

        printf("%lld\n",ans);
    }
    return 0;
}

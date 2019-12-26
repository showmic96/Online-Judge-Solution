// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int n , f;
double ar[1234567];

bool is_possible(double x)
{

    int counter = 0;

    for(int i=0;i<n;i++){

        counter+=(int)(ar[i]/x);
    }

    if(counter>=f)return true;
    return false;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        scanf("%d %d",&n,&f);
        f++;
        for(int i=0;i<n;i++){

            scanf("%lf",&ar[i]);
            ar[i] = ar[i]*ar[i]*acos(-1);
        }

        sort(ar , ar+n);

        double hi = 1e18 , low = 0 , mid , ans;

        int cc = 200;

        while(cc--){

            mid = (hi+low)/2;

            if(is_possible(mid)==true){

                ans = mid;
                low = mid;
            }

            else{

                hi = mid;
            }
        }
        //cout << ans << endl;
        printf("%.4f\n",ans);

    }
    return 0;
}

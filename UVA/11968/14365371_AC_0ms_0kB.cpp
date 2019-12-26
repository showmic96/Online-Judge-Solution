// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        vector<double>v1 , v2;
        double counter = 0;
        int n , m , k;
        scanf("%d %d %d",&n , &m , &k);

        for(int i=0;i<m;i++){

            double in;
            scanf("%lf",&in);
            v1.push_back(in);
            counter+=in;
        }

        for(int i=0;i<k;i++){

            double in;
            scanf("%lf",&in);
            v2.push_back(in);
            counter+=in;
        }

        sort(v1.begin() , v1.end());
        sort(v2.begin() , v2.end());

        for(int i=0;i<n-m-k;i++){

            double in;
            scanf("%lf",&in);
            counter+=in;
        }
        counter/=(double)n;

        double ans = 0 , mi = 1e19;
        for(int i=0;i<m;i++){

            double temp = abs(v1[i]-counter);
            if(temp<mi){

                ans = v1[i];
                mi = temp;
            }
        }

        printf("Case #%d: %.0f ",++c , ans);

        ans = 0 , mi = 1e19;
        for(int i=0;i<k;i++){

            double temp = abs(v2[i]-counter);
            if(temp<mi){

                ans = v2[i];
                mi = temp;
            }
        }

        printf("%.0f\n",ans);
    }
    return 0;
}

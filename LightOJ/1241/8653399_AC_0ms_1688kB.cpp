// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    scanf("%d",&t);

    for(int i=0;i<t;i++){

        int n;
        scanf("%d",&n);

        double ans = 0 , ar[n+1];

        ar[0] = 2;

        for(int j=1;j<=n;j++)scanf("%lf",&ar[j]);

        for(int j=0;j<n;j++){

            //cout << ar[j] << " " << ans << endl;

            ans+=ceil((ar[j+1]-ar[j])/5);
        }

        printf("Case %d: %d\n",i+1 , (int)ans);
    }

    return 0;
}

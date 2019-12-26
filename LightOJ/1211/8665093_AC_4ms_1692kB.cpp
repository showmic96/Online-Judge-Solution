// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

bool cmp(int a , int b){return a > b;}

int main(void)
{
    int t;
    scanf("%d",&t);

    for(int i=0;i<t;i++){

        int n;
        scanf("%d",&n);

        int x1[n] , x2[n] , y1[n] , y2[n] , z1[n] , z2[n];

        for(int j=0;j<n;j++){

            scanf("%d %d %d %d %d %d",&x1[j],&y1[j],&z1[j],&x2[j],&y2[j],&z2[j]);
        }

        sort(x1 , x1+n , cmp);
        sort(y1 , y1+n , cmp);
        sort(z1 , z1+n , cmp);
        sort(x2 , x2+n);
        sort(y2 , y2+n);
        sort(z2 , z2+n);
        //cout << x1[0] << " " << y1[0] << " " << z1[0] << " " << x2[0] << " " << y2[0] << " "<< z2[0] << endl;
        long long area = (max(0 , -x1[0]+x2[0])*max(0 , -y1[0]+y2[0])*max(0 , -z1[0]+z2[0]));

        printf("Case %d: %lld\n",i+1 , area);
    }

    return 0;
}

// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ar[3005][3005];

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        int n , m;
        scanf("%d %d",&n , &m);

        memset(ar , 0 ,sizeof(ar));

        for(int i=0;i<m;i++){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);
            ar[in1][in2] = 1;
            ar[in2][in1] = 1;
        }

        ll ans = 0;

        for(int i=1;i<=n;i++){

            for(int j=i+1;j<=n;j++){
                
                if(!ar[i][j])continue;
                
                for(int k=j+1;k<=n;k++){

                    if(ar[j][k]&&ar[k][i]&&ar[i][j])ans++;
                }
            }
        }

        printf("%lld\n",ans);
    }
    return 0;
}

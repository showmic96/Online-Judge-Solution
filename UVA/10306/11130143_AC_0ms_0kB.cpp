// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    scanf("%d",&t);

    while(t--){

        int n , s;
        scanf("%d %d",&n, &s);

        vector<int>v1 , v2;

        for(int i=0;i<n;i++){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);
            v1.push_back(in1);
            v2.push_back(in2);
        }

        ll ar[330][330];

        for(int i=0;i<330;i++){

            for(int j=0;j<330;j++){

                ar[i][j] = 1e9;
            }
        }

        ar[0][0] = 0;

        for(int i=0;i<n;i++){

            for(int j=v1[i];j<=s;j++){

                for(int k=v2[i];k<=s;k++){

                    ar[j][k] = min(ar[j][k] , ar[j-v1[i]][k-v2[i]] + 1);
                }
            }
        }

        ll ans = 1e9;

        for(int i=0;i<=s;i++){

            for(int j=0;j<=s;j++){

                if(ar[i][j]>1e8)continue;

                if(i*i+j*j==s*s){

                    ans = min(ans, ar[i][j]);
                }
            }
        }

        if(ans>1e8)printf("not possible\n");
        else printf("%lld\n",ans);
    }

    return 0;
}

// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    scanf("%d",&t);

    for(int i=0;i<t;i++){

        int n , m;
        scanf("%d %d",&n , &m);

        int ar[n][n];

        for(int j=0;j<n;j++){

            for(int k=0;k<n;k++){

                if(j!=k)ar[j][k] = 500000;
                else ar[j][k] = 0;
            }
        }

        for(int j=0;j<m;j++){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);

            ar[in1][in2] = 1;
            ar[in2][in1] = 1;
        }

        for(int l=0;l<n;l++){

            for(int j=0;j<n;j++){

                for(int k=0;k<n;k++){

                    if(ar[j][k]>ar[j][l] + ar[l][k]){

                            ar[j][k] = ar[j][l] + ar[l][k];
                            ar[k][j] = ar[j][k];
                    }
                }
            }
        }

        int dis = 0 , st , en;

        scanf("%d %d",&st , &en);

        for(int j=0;j<n;j++){

            //cout << st << " " << en<< endl;

            dis=max(ar[j][st]+ar[j][en] , dis);
        }

        printf("Case %d: %d\n",i+1 , dis);

    }

    return 0;
}

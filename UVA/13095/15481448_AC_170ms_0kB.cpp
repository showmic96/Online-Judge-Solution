// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int ar[11][100005];

int main(void)
{
    int n;
    while(scanf("%d",&n)==1){

        for(int i=0;i<=9;i++){

            for(int j=0;j<=n;j++)ar[i][j] = 0;
        }

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            ar[in][i+1] = 1;
        }

        for(int i=0;i<=9;i++){

            for(int j=1;j<=n;j++)ar[i][j]+=ar[i][j-1];
        }

        int q;
        scanf("%d",&q);
        while(q--){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);

            int counter = 0;

            for(int i=0;i<=9;i++){

                if(ar[i][in2]-ar[i][in1-1]>0)counter++;
            }

            printf("%d\n",counter);
        }
    }
    return 0;
}

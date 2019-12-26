// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 110;
double ar[10000+9];
int value[MAX+9];

void init()
{
    for(int i=0;i<=10000;i++){

        ar[i] = 1;
    }
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        init();

        int n;
        double mx;
        scanf("%lf %d",&mx , &n);

        int total = 0;

        vector<double>v;

        for(int i=0;i<n;i++){

            int in1 ;
            double in2;
            scanf("%d %lf",&in1 , &in2);

            v.push_back(in2);
            value[i] = in1;
            total+=in1;
        }

        ar[0] = 0;

        for(int i=0;i<n;i++){

            for(int j=total;j>=1;j--){

                if(j-value[i]>=0){

                    ar[j] = min(ar[j] , ar[j-value[i]]+(1-ar[j-value[i]])*v[i]);
                }
            }
        }

        int ans = 0;

        for(int i=0;i<=total;i++){

            if(ar[i]<mx){

                ans = i;
            }
        }

        printf("Case %d: %d\n",++c , ans);
    }
    return 0;
}

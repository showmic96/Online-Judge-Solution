// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ar[100005];

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        int n , m;
        scanf("%d %d",&n , &m);

        ll sum = 0;

        for(int i=0;i<n;i++){

            scanf("%lld",&ar[i]);
            sum+=ar[i]*(ll)(n-i-1);
            sum-=ar[i]*(ll)i;
        }

        printf("Case %d:\n",++c);

        for(int i=0;i<m;i++){

            int in;
            scanf("%d",&in);
            if(in==1){

                printf("%lld\n",sum);
            }
            else{

                ll in1 , in2;
                scanf("%lld %lld",&in1 ,&in2);

                sum-=ar[in1]*(ll)(n-in1-1);
                sum+=ar[in1]*(ll)in1;

                ar[in1] = in2;

                sum+=ar[in1]*(ll)(n-in1-1);
                sum-=ar[in1]*(ll)in1;
            }
        }
    }
    return 0;
}

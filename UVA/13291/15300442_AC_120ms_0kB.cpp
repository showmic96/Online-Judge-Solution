// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int n;
    while(scanf("%d",&n)==1){

        vector<int>v1 , v2;
        ll ar[3] , sum[3];
        ar[0] = ar[1] = ar[2] = 0;
        sum[0] = sum[1] = sum[2] = 0;

        for(int i=1;i<=n;i++){

            int in;
            scanf("%d",&in);
            v1.push_back(in);
            ar[i%3]+=in;
        }

        ll now = 0;

        for(int i=1;i<=n;i++){

            int in;
            scanf("%d",&in);
            v2.push_back(in);

            sum[now%3]+=(ll)in*ar[0];
            sum[(now+1)%3]+=(ll)in*ar[1];
            sum[(now+2)%3]+=(ll)in*ar[2];
            now++;

        }

        printf("%lld %lld %lld\n",sum[2] , sum[0] , sum[1]);
    }
    return 0;
}

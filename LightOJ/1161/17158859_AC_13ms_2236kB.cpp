// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);

        vector<ll>v(10005) , ans(10005);

        for(int i=0;i<v.size();i++)v[i] = 0;

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            v[in]++;
        }

        for(int i=10000;i>=1;i--){

            ll now = v[i];

            for(int j=2*i;j<=10000;j+=i){

                now+=v[j];
            }

            ans[i] = now*(now-1)*(now-2)*(now-3);
            ans[i]/=24LL;

            for(int j=2*i;j<=10000;j+=i)ans[i]-=ans[j];
        }

        printf("Case %d: %lld\n",++c , ans[1]);
    }

    return 0;
}

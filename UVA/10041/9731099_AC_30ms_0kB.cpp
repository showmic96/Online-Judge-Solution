// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);

        vector<int>v;

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            v.push_back(in);
        }

        long long sum = 1234567891011121314 , t = 0;

        for(int i=0;i<n;i++){

            t = 0;

            for(int j=0;j<n;j++){

                t+=abs(v[i]-v[j]);
            }

            sum = min(sum , t);
        }

        printf("%lld\n",sum);
    }
    return 0;
}

// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    
    while(t--){

        vector<int>v;

        int n , k , in;
        scanf("%d %d",&n , &k);

        for(int i=0;i<n;i++){

            scanf("%d",&in);
            v.push_back(in);
        }

        for(int i=0;i<n;i++){

            scanf("%d",&in);
            v[i] = in-v[i];
        }

        sort(v.begin() , v.end());

        long long sum = 0;

        for(int i=0;i<k;i++)if(v[i]>0)sum+=v[i];

        for(int i=k;i<n;i++)sum+=v[i];

        printf("Case %d: ",++c);

        if(sum<=0)printf("No Profit\n");
        else printf("%lld\n",sum);
    }
    return 0;
}

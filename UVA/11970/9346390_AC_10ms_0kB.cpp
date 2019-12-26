// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        long long n;
        scanf("%lld",&n);

        long long lim = sqrt(n);
        vector<long long>ans;

        for(long long i =1;i<=lim-1;i++){

            if((n-(i*i))%i==0){

                ans.push_back(n-(i*i));
            }
        }

        printf("Case %d:",++c);

        int si = ans.size();

        for(int i=si-1;i>=0;i--){

            printf(" %lld",ans[i]);
        }

        printf("\n");
    }
    return 0;
}

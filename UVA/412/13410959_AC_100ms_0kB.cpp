// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int n;
    while(scanf("%d",&n)==1){

        if(!n)break;

        vector<int>v;
        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            v.push_back(in);
        }

        double counter = 0;

        for(int i=0;i<n;i++){

            for(int j=i+1;j<n;j++){

                if(__gcd(v[i] , v[j])==1)counter++;
            }
        }

        double lim = (double(n)*(n-1)/2);

        if(counter==0)printf("No estimate for this data set.\n");
        else printf("%.6f\n",sqrt(lim/counter*6.00));
    }
    return 0;
}

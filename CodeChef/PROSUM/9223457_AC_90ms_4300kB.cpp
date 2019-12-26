// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int ar [123456] , two[123456];

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        vector<ll>v;
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){

            ll in;
            scanf("%lld",&in);
            v.push_back(in);
        }

        int c = 0;

        for(int i=0;i<n;i++){

            if(v[i]<=1)c++;
            ar[i] = c;
        }

        c = 0;
        for(int i=0;i<n;i++){

            if(v[i]==2)c++;
            two[i] = c;
        }

        ll counter = 0 , last = ar[n-1];

        for(int i=0;i<n;i++){

            if(v[i]<=1)continue;

            counter+= (n-i-1) - (last - ar[i]);

            if(v[i]==2)counter-=(two[n-1]-two[i]);
        }

        printf("%lld\n",counter);
    }
    return 0;
}

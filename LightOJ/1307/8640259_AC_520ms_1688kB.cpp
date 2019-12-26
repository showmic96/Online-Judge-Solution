// In the name of Allah the most merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    scanf("%d",&t);

    for(int i=0;i<t;i++){

        int n;
        scanf("%d",&n);

        ll in;

        vector<ll>ar;
        vector<ll>::iterator it;

        for(int j=0;j<n;j++){scanf("%lld",&in);ar.push_back(in);}

        sort(ar.begin() , ar.end());

        ll ans = 0;

        for(int j=0;j<n-2;j++){

            for(int k=j+1;k<n-1;k++){

                ll sum = ar[k] + ar[j];

                it = lower_bound(ar.begin()+k+1 , ar.end() , sum);

                ans+= (it - ar.begin()-k-1);

            }
        }

        printf("Case %d: %lld\n",i+1,ans);
    }

    return 0;
}

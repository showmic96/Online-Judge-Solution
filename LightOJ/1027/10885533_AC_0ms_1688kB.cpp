#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(void)
{
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        ll n;
        vector<ll>v;

        scanf("%lld",&n);
        ll mx = -110;
        for(int i=0;i<n;i++){

            ll in;
            scanf("%lld",&in);
            v.push_back(in);

            mx = max(in , mx);
        }

        if(mx<0)printf("Case %d: inf\n",++c);
        else{

            ll sum = 0 , counter = 0;

            for(int i=0;i<n;i++){

                if(v[i]<0)counter++;
                sum+=abs(v[i]);
            }

            counter = n - counter;

            printf("Case %d: %lld/%lld\n",++c , sum/(__gcd(sum , counter)) , counter/(__gcd(sum ,counter)));
        }
    }

    return 0;
}

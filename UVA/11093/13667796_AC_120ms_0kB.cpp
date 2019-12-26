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
        vector<ll>v1 , v2 , v;

        for(int i=0;i<n;i++){

            ll in;scanf("%lld",&in);
            v1.push_back(in);
        }

        for(int i=0;i<n;i++){

            ll in;scanf("%lld",&in);
            v.push_back(v1[i] - in);
        }

        ll sum = 0 , st = 0 , counter = 0;

        for(int i=0;i<=2*n;i++){

            ll temp = v[i%n];
            sum+=temp;

            if(sum<0){

                sum = 0;
                st = i+1;
                counter = 0;
            }
            else{

                counter++;
            }

            if(counter==n)break;
        }

        if(counter==n)printf("Case %d: Possible from station %lld\n",++c , st+1);
        else printf("Case %d: Not possible\n",++c);
    }
    return 0;
}

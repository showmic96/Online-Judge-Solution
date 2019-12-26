#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll make(ll x)
{
    ll counter = 0;

    while(x!=1){

        if(x%2==0)x/=2;
        else x--;
        counter++;
    }

    return counter;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        int n , q;
        scanf("%d %d",&n , &q);

        vector<ll>v , sum;

        for(int i=0;i<n;i++){

            ll in;
            scanf("%lld",&in);
            v.push_back(make(in));
        }

        sum.push_back(0);

        for(int i=0;i<n;i++){

            sum.push_back(sum[i]+v[i]);
        }

        while(q--){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);
            printf("%lld\n",sum[in2]-sum[in1-1]);
        }
    }
    return 0;
}

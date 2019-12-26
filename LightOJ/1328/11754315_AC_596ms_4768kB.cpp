// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t , tc = 0;
    scanf("%d",&t);
    while(t--){

        int k , c , n , in;
        vector<ll>v;

        scanf("%d %d %d %d",&k, &c , &n , &in);
        v.push_back(in);

        for(int i=1;i<n;i++){

            int temp = (k * v[i-1] + c) % 1000007;
            v.push_back(temp);
        }

        sort(v.begin() , v.end());
        reverse(v.begin() , v.end());

        ll sum = 0;

        vector<ll>vv;
        vv.push_back(0);

        for(int i=1;i<n;i++){

            vv.push_back(vv[i-1]+(v[i-1]-v[i])*i);
            sum+=vv[i];
        }

        printf("Case %d: %lld\n",++tc , sum);
    }
    return 0;
}
